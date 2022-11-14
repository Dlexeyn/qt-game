#ifndef STATICVIEW_H
#define STATICVIEW_H

#include <QObject>

class StaticView: public QObject
{
Q_OBJECT
public slots:
    virtual void changeView() = 0;
};

#endif // STATICVIEW_H
