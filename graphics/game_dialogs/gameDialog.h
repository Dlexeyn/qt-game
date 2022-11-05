#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H

#include <QKeyEvent>

class GameDialog{
protected:
    int key;
    virtual void keyPressEvent(QKeyEvent *event) = 0;
};


#endif // GAMEDIALOG_H
