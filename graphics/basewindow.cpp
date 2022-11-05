#include "graphics/basewindow.h"
#include "config/Configurator.h"
#include "ui_basewindow.h"

BaseWindow::BaseWindow(Config::Configurator *config, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::BaseWindow)
    , config(config)
{
    ui->setupUi(this);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFocusPolicy(Qt::StrongFocus);
}

BaseWindow::~BaseWindow()
{
    delete ui;
    delete menu;
    delete help;
}

void BaseWindow::callLoseDialog()
{
    QMessageBox::information(this, "Поражение", "Вы проиграли!");
    notifySubscribers("the \"Lose\" event triggered", "game");
}

void BaseWindow::callVictoryDialog()
{
    QMessageBox::information(this, "Победа", "Уровень пройден!");
    notifySubscribers("the \"Victory\" event triggered", "game");
}

void BaseWindow::callRestartDialog()
{

}

bool BaseWindow::callExitDialog()
{
    notifySubscribers("the Exit dialog", "game");
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Выход", "Вы действительно хотите завершить уровень?",
                                    QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        end = true;
        emit endStatus();
        return true;
    }
    emit endStatus();
    return false;


}

void BaseWindow::callPauseDialog()
{
    notifySubscribers("the pause", "game");
    help->exec();
    emit endStatus();
}

void BaseWindow::callSaveDialog()
{

}

void BaseWindow::callNewGameDialog()
{

}

void BaseWindow::callMenuDialog()
{
    notifySubscribers("the menu", "game");
    menu->exec();
    emit endStatus();
}

void BaseWindow::init(ReadData *readData, QGraphicsScene *scene, View *player)
{
    this->setWindowTitle("Sokoban");
    this->resize(readData->getWidth()*sizeCellPx + 100, readData->getHeight()*sizeCellPx + 100);
    this->setFixedSize(readData->getWidth()*sizeCellPx + 100, readData->getHeight()*sizeCellPx + 100);
    this->player = player;
    int width = readData->getWidth() * readData->getSizeCell();
    int height = readData->getHeight() * readData->getSizeCell();
    scene->setSceneRect(-width/2, -height/2, width, height);
    scene->addLine(-width/2,-height/2, width/2,-height/2, QPen(Qt::black));
    scene->addLine(-width/2, height/2, width/2, height/2, QPen(Qt::black));
    scene->addLine(-width/2,-height/2,-width/2, height/2, QPen(Qt::black));
    scene->addLine(width/2,-height/2, width/2, height/2, QPen(Qt::black));
    ui->graphicsView->setScene(scene);
    status = WindowStatus::GAME;
    setFocus();
}

void BaseWindow::setController(Controller *newController)
{
    controller = newController;
}

void BaseWindow::getMessage(GLMessage* mes)
{
    status = WindowStatus(mes->getArg(ArgsTypes::STATUS));
}

void BaseWindow::setEnd(bool newEnd)
{
    end = newEnd;
}

bool BaseWindow::getEnd() const
{
    return end;
}

void BaseWindow::closeEvent(QCloseEvent *event)
{
    emit endApp();
    event->accept();
}

WindowStatus BaseWindow::getStatus() const
{
    return status;
}

void BaseWindow::setStatus(WindowStatus newStatus)
{
    status = newStatus;
}

void BaseWindow::createDialogs(const std::map <Commands, int> KeyCommands)
{
    menu = new MenuDialog(KeyCommands);
    help = new HelpDialog(KeyCommands);

    connect(menu, SIGNAL(saveGameSignal()), this, SLOT()); // ?
    connect(menu, SIGNAL(restartGameSignal()), this, SLOT(callRestartDialog()));
    connect(menu, SIGNAL(helpSignal()), this, SLOT(callPauseDialog())); // +
    connect(menu, SIGNAL(exitSignal()), this, SLOT(callExitDialog()));//+
    //
}

void BaseWindow::keyPressEvent(QKeyEvent *event)
{
    key = event->key();
}

void BaseWindow::slotPlayerTimer()
{
    if(key)
    {
        GLMessage newMes(Sender::WINDOW, ArgsTypes::KEY, key);
        game->notify(&newMes);
        ui->graphicsView->scene()->update();
        key = 0;
    }

    ui->HealthLabel->setText(QString::number(player->getObject()->getAttribute(ObjectAttribute::HEALTH)));
    ui->PointsLabel->setText(QString::number(player->getObject()->getAttribute(ObjectAttribute::POINTS)));
    this->update();
}

