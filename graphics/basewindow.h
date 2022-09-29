#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QApplication>
#include "graphics/DialogSize.h"
#include "graphics/FieldScene.h"
#include "game/Controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BaseWindow; }
QT_END_NAMESPACE

class BaseWindow : public QMainWindow
{
    Q_OBJECT

public:
    BaseWindow(QWidget *parent = nullptr);
    ~BaseWindow();

    int getKey() const;

    FieldScene *getFieldScene() const;

    void setController(Controller *newController);

    bool getCloseApp() const;

private:
    Ui::BaseWindow *ui;
    FieldScene *fieldScene = nullptr;
    DialogSize *dialog = nullptr;
    QTimer *timerForPlayer = nullptr;
    QTimer *indicatorsTimer = nullptr;
    Controller *controller = nullptr;

    const unsigned sizeCellPx = 40;
    int key = 0;
    bool closeApp = false;

    void keyPressEvent(QKeyEvent *event);


private slots:
    void slotPlayerTimer();
    void updateHealthLabel();
};
#endif // BASEWINDOW_H
