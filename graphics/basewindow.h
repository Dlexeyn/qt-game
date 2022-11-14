#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QApplication>
#include <QMessageBox>
#include "config/Configurator.h"
#include "log/LogObject.h"
#include "map/ReadData.h"
#include "EventWindow.h"
#include "BaseWindowStatus.h"
#include "game_dialogs/MenuDialog.h"
#include "game_dialogs/HelpDialog.h"
#include "map/objects/Player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BaseWindow; }
QT_END_NAMESPACE

class BaseWindow : public QMainWindow, public EventWindow, public LogObject
{
    Q_OBJECT

public:
    BaseWindow(Config::Configurator *config, QWidget *parent = nullptr);
    ~BaseWindow();

    void init(ReadData *readData, QGraphicsScene *scene, const Player *player);

    void getMessage(GLMessage *mes);

    void closeEvent( QCloseEvent* event );

    WindowStatus getStatus() const;

    void setStatus(WindowStatus newStatus);

    void createDialogs(const std::map <int, Commands> KeyCommands);

public slots:
    void callLoseEventDialog();      // event dialog

    void callVictoryEventDialog();   // event dialog

    bool callRestartEventDialog(bool withQuestion = true);   // event or status dialog

    bool callExitDialog();      // status dialog

    void callPauseDialog();     // status dialog

    void callSaveDialog();      // status dialog

    void callNewGameDialog();   // status dialog

    void callMenuDialog();      // status dialog

signals:
    void endApp();
    void endStatus(WindowStatus curStatus = WindowStatus::NONE);

private:
    Ui::BaseWindow *ui;

    const Player *player = nullptr;
    //Controller *controller = nullptr;
    Config::Configurator *config = nullptr;
    MenuDialog *menu = nullptr;
    HelpDialog *help = nullptr;

    WindowStatus status;

    bool answerTheBox(WindowStatus status, QMessageBox::StandardButton &reply);

    const unsigned sizeCellPx = 50;
    int key;
    virtual void keyPressEvent(QKeyEvent *event);
public slots:
    void slotPlayerTimer();
};
#endif // BASEWINDOW_H
