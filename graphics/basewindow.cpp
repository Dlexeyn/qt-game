#include "graphics/basewindow.h"
#include "ui_basewindow.h"

BaseWindow::BaseWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BaseWindow)
{
    ui->setupUi(this);

    dialog = new DialogSize();
    dialog->show();
    dialog->exec();

    if(dialog->getCancel())
    {
        closeApp = true;
        this->close();
    }
    else
    {
        this->show();
        fieldScene = new FieldScene(dialog->getWidth(), dialog->getHeight(), sizeCellPx);

        this->resize(dialog->getWidth()*sizeCellPx + 100, dialog->getHeight()*sizeCellPx + 100);
        this->setFixedSize(dialog->getWidth()*sizeCellPx + 100, dialog->getHeight()*sizeCellPx  + 100);

        ui->graphicsView->setScene(fieldScene->getGameScene());

        ui->graphicsView->setRenderHint(QPainter::Antialiasing);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        ui->HealthLabel->setText(QString::number(fieldScene->getPlayerView()->getHealth()));

        timerForPlayer = new QTimer(this);
        connect(timerForPlayer, SIGNAL(timeout()), this, SLOT(slotPlayerTimer()));
        timerForPlayer->start(150);

        indicatorsTimer = new QTimer(this);
        indicatorsTimer->setInterval(100);
        connect(indicatorsTimer, SIGNAL(timeout()), this, SLOT(updateHealthLabel()));
        indicatorsTimer->start();
    }
}

BaseWindow::~BaseWindow()
{
    delete ui;
}

int BaseWindow::getKey() const
{
    return key;
}

FieldScene *BaseWindow::getFieldScene() const
{
    return fieldScene;
}

void BaseWindow::setController(Controller *newController)
{
    controller = newController;
}

bool BaseWindow::getCloseApp() const
{
    return closeApp;
}

void BaseWindow::keyPressEvent(QKeyEvent *event)
{
    key = event->key();
}

void BaseWindow::updateHealthLabel()
{
    ui->HealthLabel->setText(QString::number(fieldScene->getPlayerView()->getHealth()));
    this->update();
}

void BaseWindow::slotPlayerTimer()
{

    if(key)
    {
        controller->sendPlayerCommand(key);
        fieldScene->getGameScene()->update();
        key = 0;
    }


}

