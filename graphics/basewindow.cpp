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
    delete load;
}

void BaseWindow::callLoseEventDialog()
{
    QMessageBox::information(this, "Поражение", "Вы проиграли!");
    notifySubscribers("the \"Lose\" event triggered", "game");
}

void BaseWindow::callVictoryEventDialog()
{
    QMessageBox::information(this, "Победа", "Уровень пройден!");
    notifySubscribers("the \"Victory\" event triggered", "game");
}

bool BaseWindow::callRestartEventDialog(bool withQuestion)
{
    QMessageBox::StandardButton reply = QMessageBox::Yes;
    if(withQuestion)
    {
        reply = QMessageBox::question(this, "Перезапуск", "Вы действительно хотите начать сначала?",
                                        QMessageBox::Yes|QMessageBox::No);
    }
    return answerTheBox(WindowStatus::RESTART_LEVEL, reply);
}

bool BaseWindow::callExitDialog()
{
    notifySubscribers("the Exit dialog", "game");
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Выход", "Вы действительно хотите завершить уровень?",
                                    QMessageBox::Yes|QMessageBox::No);
    return answerTheBox(WindowStatus::END_LEVEL, reply);
}

void BaseWindow::callPauseDialog()
{
    notifySubscribers("the pause", "game");
    help->exec();
    emit endStatus(WindowStatus::GAME);
}

void BaseWindow::callSaveDialog()
{
    notifySubscribers("the game was saved", "game");
    QMessageBox::information(this, "Сохранение", "Игра сохранена.");
    emit endStatus(WindowStatus::GAME);
}

void BaseWindow::callMenuDialog()
{
    notifySubscribers("the menu", "game");
    menu->exec();
    if(status == WindowStatus::MENU)
        emit endStatus(WindowStatus::GAME);
}

int BaseWindow::callLoadSaveDialog(std::vector<std::string> saves)
{
    notifySubscribers("the load save dialog", "game");
    load->setSaves(saves);
    load->exec();
    int n = load->getCur();
    if(n > 0)
        emit endStatus(WindowStatus::LOAD_SAVE);
    else if(n < 0)
        emit endStatus(WindowStatus::DELETE_SAVE);
    else
        emit endStatus(WindowStatus::GAME);

    return n;
}

bool BaseWindow::answerTheBox(WindowStatus status, QMessageBox::StandardButton &reply)
{
    if (reply == QMessageBox::Yes)
    {
        emit endStatus(status);
        return true;
    }
    else
        emit endStatus(WindowStatus::GAME);
    return false;
}

void BaseWindow::setSaveIsLoad(bool newSaveIsLoad)
{
    saveIsLoad = newSaveIsLoad;
}

void BaseWindow::callWarningSaveDialog()
{
    QMessageBox::warning(this, tr("Сохранение"),
                                   tr("Все слоты для сохранений заполнены."));
    emit endStatus(WindowStatus::GAME);
}

bool BaseWindow::getSaveIsLoad() const
{
    return saveIsLoad;
}

void BaseWindow::init(int h, int w, QGraphicsScene *scene, const Player *player)
{
    this->setWindowTitle("Sokoban");
    this->resize(w + 100, h + 100);
    this->setFixedSize(w + 100, h + 100);
    this->player = player;
    scene->setSceneRect(-w/2, -h/2, w, h);
    scene->addLine(-w/2,-h/2, w/2,-h/2, QPen(Qt::black));
    scene->addLine(-w/2, h/2, w/2, h/2, QPen(Qt::black));
    scene->addLine(-w/2,-h/2,-w/2, h/2, QPen(Qt::black));
    scene->addLine(w/2,-h/2, w/2, h/2, QPen(Qt::black));
    ui->graphicsView->setScene(scene);
    status = WindowStatus::GAME;
    setFocus();
}

void BaseWindow::getMessage(GLMessage* mes)
{
    status = WindowStatus(mes->getArg(ArgsTypes::STATUS));
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

void BaseWindow::createDialogs(const std::map <int, Commands> KeyCommands)
{
    std::map<Commands, int> tempKeyCommads;
    for (std::map<int, Commands>::const_iterator it = KeyCommands.begin(); it != KeyCommands.end(); ++it)
        tempKeyCommads.insert(std::pair<Commands, int>(it->second, it->first));

    menu = new MenuDialog(tempKeyCommads);
    help = new HelpDialog(tempKeyCommads);
    load = new LoadDialog();

    connect(menu, SIGNAL(saveGameSignal()), this, SLOT(callSaveDialog())); // ?
    connect(menu, SIGNAL(restartGameSignal()), this, SLOT(callRestartEventDialog())); // +
    connect(menu, SIGNAL(helpSignal()), this, SLOT(callPauseDialog())); // +
    connect(menu, SIGNAL(exitSignal()), this, SLOT(callExitDialog()));//+
    //connect(menu, SIGNAL(loadGame()), this, SLOT(callLoadSaveDialog(std::vector<std::string>)));

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

    ui->HealthLabel->setText(QString::number(player->getCurHealth()));
    ui->PointsLabel->setText(QString::number(player->getVictoryPoints()));
    this->update();
}

