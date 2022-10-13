#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QApplication>
#include <QMessageBox>
#include "graphics/DialogSize.h"
#include "graphics/FieldScene.h"
#include "graphics/PlayerView.h"
#include "graphics/dialoglevel.h"
#include "game/Controller.h"
#include "map/LevelReader.h"
#include "game/GlobalComponent.h"
#include "game/GlobalMediator.h"
#include "EventWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BaseWindow; }
QT_END_NAMESPACE

class BaseWindow : public QMainWindow, public GlobalComponent, public EventWindow
{
    Q_OBJECT

public:
    BaseWindow(QWidget *parent = nullptr);
    ~BaseWindow();

    void callVictoryDialog();

    void callRestartDialog();

    void callExitDialog();

    void sendCignal();

    void init(LevelReader *lvlReader, FieldScene *scene);

    int getKey() const;

    void setController(Controller *newController);

    bool getCloseApp() const;

    DialogLevel *getDialogLevel() const;

private:
    Ui::BaseWindow *ui;

    LevelReader *lvlReader = nullptr;
    PlayerView *player = nullptr;
    DialogSize *dialog = nullptr;
    DialogLevel *dialogLevel = nullptr;
    QTimer *timerForPlayer = nullptr;
    QTimer *indicatorsTimer = nullptr;
    Controller *controller = nullptr;

    const unsigned sizeCellPx = 50;
    int key = 0;
    bool closeApp = false;

    void keyPressEvent(QKeyEvent *event);


private slots:
    void slotPlayerTimer();
    void updateLabels();
};
#endif // BASEWINDOW_H
