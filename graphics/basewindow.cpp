#include "graphics/basewindow.h"
#include "ui_basewindow.h"

BaseWindow::BaseWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BaseWindow)
{
    ui->setupUi(this);

//    dialog = new DialogSize();
//    dialog->show();
//    dialog->exec();

    dialogLevel = new DialogLevel();
    dialogLevel->show();
    dialogLevel->exec();

    if(dialogLevel->getIsExit())
    {
        closeApp = true;
        this->close();
    }
    else
    {
        this->show();
//        lvlReader = new LevelReader(dialogLevel->getLevel());
//        fieldScene = new FieldScene(lvlReader, sizeCellPx);

//        this->resize(lvlReader->getWidth()*sizeCellPx + 100, lvlReader->getHeight()*sizeCellPx + 100);
//        this->setFixedSize(14*sizeCellPx + 100, 7*sizeCellPx  + 100);

        ui->graphicsView->setRenderHint(QPainter::Antialiasing);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        //ui->HealthLabel->setText(QString::number(fieldScene->getPlayerView()->getHealth()));

        timerForPlayer = new QTimer(this);
        connect(timerForPlayer, SIGNAL(timeout()), this, SLOT(slotPlayerTimer()));
        timerForPlayer->start(150);

        indicatorsTimer = new QTimer(this);
        indicatorsTimer->setInterval(100);
        connect(indicatorsTimer, SIGNAL(timeout()), this, SLOT(updateLabels()));
        indicatorsTimer->start();
    }
}

BaseWindow::~BaseWindow()
{
    delete ui;
}

void BaseWindow::callVictoryDialog()
{
    QMessageBox::information(this, "Победа", "Уровень пройден!");
//    this->hide();
//    dialogLevel->show();
//    dialogLevel->exec();
    qApp->quit();

}

void BaseWindow::callRestartDialog()
{

}

void BaseWindow::callExitDialog()
{
    QMessageBox::information(this, "Поражение", "Вы проиграли!");
    qApp->quit();

}

void BaseWindow::sendCignal()
{
    game->notify(this, "basewindow");
}

void BaseWindow::init(LevelReader *lvlReader, FieldScene *scene)
{
    this->lvlReader = lvlReader;
    this->player = scene->getPlayerView();
    this->resize(lvlReader->getWidth()*sizeCellPx + 100, lvlReader->getHeight()*sizeCellPx + 100);
    this->setFixedSize(lvlReader->getWidth()*sizeCellPx + 100, lvlReader->getHeight()*sizeCellPx + 100);
    ui->graphicsView->setScene(scene->getGameScene());

}

int BaseWindow::getKey() const
{
    return key;
}

void BaseWindow::setController(Controller *newController)
{
    controller = newController;
}

bool BaseWindow::getCloseApp() const
{
    return closeApp;
}

DialogLevel *BaseWindow::getDialogLevel() const
{
    return dialogLevel;
}

void BaseWindow::keyPressEvent(QKeyEvent *event)
{
    key = event->key();
}

void BaseWindow::updateLabels()
{
    ui->HealthLabel->setText(QString::number(player->getHealth()));
    ui->PointsLabel->setText(QString::number(player->getPoints()));
    this->update();
}

void BaseWindow::slotPlayerTimer()
{
    if(key)
    {
        controller->sendPlayerCommand(key);
        ui->graphicsView->scene()->update();
        key = 0;
    }
}

