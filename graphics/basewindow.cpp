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
}

BaseWindow::~BaseWindow()
{
    delete ui;
}

void BaseWindow::callVictoryDialog()
{
    QMessageBox::information(this, "Победа", "Уровень пройден!");
    notifySubscribers("the \"Victory\" event triggered", "game");
}

void BaseWindow::callRestartDialog()
{

}

void BaseWindow::callExitDialog()
{
    QMessageBox::information(this, "Поражение", "Вы проиграли!");
    notifySubscribers("the \"Lose\" event triggered", "game");
}

void BaseWindow::init(ReadData *readData, QGraphicsScene *scene, View *player)
{
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
}

void BaseWindow::setController(Controller *newController)
{
    controller = newController;
}

void BaseWindow::getMessage(GLMessage* mes)
{

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


void BaseWindow::keyPressEvent(QKeyEvent *event)
{
    key = event->key();
}

void BaseWindow::slotPlayerTimer()
{
    if(key)
    {
        GLMessage newMes(Sender::WINDOW, ArgsTypes::KEY, key);
        game->notify(this, &newMes);
        ui->graphicsView->scene()->update();
        key = 0;
    }

    ui->HealthLabel->setText(QString::number(player->getObject()->getFirstAttribute()));
    ui->PointsLabel->setText(QString::number(player->getObject()->getSecondAttribute()));
    this->update();
}

