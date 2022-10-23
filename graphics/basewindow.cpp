#include "graphics/basewindow.h"
#include "ui_basewindow.h"

BaseWindow::BaseWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BaseWindow)
{
    ui->setupUi(this);

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

        ui->graphicsView->setRenderHint(QPainter::Antialiasing);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

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
    notifySubscriber("the game is over");
    qApp->quit();

}

void BaseWindow::callRestartDialog()
{

}

void BaseWindow::callExitDialog()
{
    QMessageBox::information(this, "Поражение", "Вы проиграли!");
    notifySubscriber("the game is over");
    qApp->quit();

}

void BaseWindow::sendCignal()
{
    game->notify("basewindow");
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
    ui->HealthLabel->setText(QString::number(player->getObject()->getFirstAttribute()));
    ui->PointsLabel->setText(QString::number(player->getObject()->getSecondAttribute()));
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

