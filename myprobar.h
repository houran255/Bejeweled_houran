#ifndef MYPROBAR_H
#define MYPROBAR_H

#include <QProgressBar>
#include <QPainter>
#include <QPainterPath>
#include <math.h>

class MyProBar : public QProgressBar
{
    Q_OBJECT
public:
    MyProBar(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *e);

};

#endif // MYPROBAR_H
