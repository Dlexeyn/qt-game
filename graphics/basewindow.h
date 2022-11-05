#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QApplication>
#include <QMessageBox>
#include "View.h"
#include "config/Configurator.h"
#include "game/Controller.h"
#include "map/ReadData.h"
#include "game/GlobalComponent.h"
#include "EventWindow.h"
#include "BaseWindowStatus.h"
#include "game_dialogs/MenuDialog.h"
#include "game_dialogs/HelpDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BaseWindow; }
QT_END_NAMESPACE

class BaseWindow : public QMainWindow, public GlobalComponent, public EventWindow, public LogObject
{
    Q_OBJECT

public:
    BaseWindow(Config::Configurator *config, QWidget *parent = nullptr);
    ~BaseWindow();

    void init(ReadData *readData, QGraphicsScene *scene, View *player);

    void setController(Controller *newController);  // ref

    void getMessage(GLMessage *mes);

    void setEnd(bool newEnd);

    bool getEnd() const;

    void closeEvent( QCloseEvent* event );

    WindowStatus getStatus() const;

    void setStatus(WindowStatus newStatus);

    void createDialogs(const std::map<Commands, int> KeyCommands);

public slots:
    void callLoseDialog();      // event dialog

    void callVictoryDialog();   // event dialog

    void callRestartDialog();   // status dialog

    bool callExitDialog();      // status dialog

    void callPauseDialog();     // status dialog

    void callSaveDialog();      // status dialog

    void callNewGameDialog();   // status dialog

    void callMenuDialog();      // status dialog

signals:
    void endApp();
    void endStatus();

private:
    Ui::BaseWindow *ui;

    View *player = nullptr;
    Controller *controller = nullptr;
    Config::Configurator *config = nullptr;
    MenuDialog *menu = nullptr;
    HelpDialog *help = nullptr;

    WindowStatus status;

    const unsigned sizeCellPx = 50;
    bool end = false;
    int key;
    virtual void keyPressEvent(QKeyEvent *event);
public slots:
    void slotPlayerTimer();
};
#endif // BASEWINDOW_H
