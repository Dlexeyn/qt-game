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

QT_BEGIN_NAMESPACE
namespace Ui { class BaseWindow; }
QT_END_NAMESPACE

class BaseWindow : public QMainWindow, public GlobalComponent, public EventWindow, public LogObject
{
    Q_OBJECT

public:
    BaseWindow(Config::Configurator *config, QWidget *parent = nullptr);
    ~BaseWindow();

    void callVictoryDialog();

    void callRestartDialog();

    void callExitDialog();

    void init(ReadData *readData, QGraphicsScene *scene, View *player);

    void setController(Controller *newController);  // ref

    void getMessage(GLMessage *mes);

    void setEnd(bool newEnd);

    bool getEnd() const;

    void closeEvent( QCloseEvent* event );

signals:
    void endApp();

private:
    Ui::BaseWindow *ui;

    View *player = nullptr;
    Controller *controller = nullptr;
    Config::Configurator *config = nullptr;

    const unsigned sizeCellPx = 50;
    bool end = false;
    int key;
    void keyPressEvent(QKeyEvent *event);
public slots:
    void slotPlayerTimer();
};
#endif // BASEWINDOW_H
