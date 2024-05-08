#include "myprobar.h"

MyProBar::MyProBar(QWidget *parent):QProgressBar(parent)
{

}

void MyProBar::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPainterPath *drawPath = new QPainterPath();
    int radius = height()/2;
    double percent = static_cast<double>(value())/static_cast<double>(maximum());
    painter.setRenderHint(QPainter::Antialiasing);//抗锯齿，减少边缘凹凸锯齿

    drawPath = new QPainterPath;
    drawPath->moveTo(radius,0);
    drawPath->arcTo(QRect(0,0,radius*2,radius*2),90,90);
    drawPath->lineTo(0,height()-radius);
    drawPath->arcTo(QRect(0,0,radius*2,radius*2),180,90);
    drawPath->lineTo(width()-radius,height());
    drawPath->arcTo(QRect(width()-radius*2,0,radius*2,radius*2),270,90);
    drawPath->lineTo(width(),radius);
    drawPath->arcTo(QRect(width()-radius*2,0,radius*2,radius*2),0,90);
    drawPath->lineTo(radius,0);


    painter.fillPath(*drawPath,QColor(0,0,109));//背景色

    drawPath = new QPainterPath();
    double x_move = (percent*width());
    double theta = acos((abs(x_move-radius)/radius));//acos反余弦
    double y_move = (sin(theta)*radius);

    if(x_move>radius*2){
        drawPath->moveTo(radius,0);
        drawPath->arcTo(QRect(0,0,radius*2,radius*2),90,90);
        drawPath->lineTo(0,height()-radius*2);
        drawPath->arcTo(QRect(0,0,radius*2,radius*2),180,90);
        drawPath->lineTo(percent*width()-radius*2,height());
        drawPath->arcTo(QRect(static_cast<int>(percent*width())-radius*2,0,radius*2,radius*2),270,90);
        drawPath->lineTo(percent*width(),radius*2);
        drawPath->arcTo(QRect(static_cast<int>(percent*width()-radius*2),0,radius*2,radius*2),0,90);
        drawPath->lineTo(radius*2,0);
    }
    else if(x_move<radius){
        drawPath->moveTo(x_move,radius-y_move);
        drawPath->arcTo(QRect(0,0,radius*2,radius*2),static_cast<int>(180-theta/M_PI*180),static_cast<int>(theta/M_PI*180));
        drawPath->arcTo(QRect(0,0,radius*2,radius*2),180,static_cast<int>(theta/M_PI*180));
        drawPath->lineTo(static_cast<int>(x_move),static_cast<int>(radius-y_move));
    }
    else {// >=2*r
        drawPath->moveTo(radius,0);
        drawPath->arcTo(QRect(0,0,radius*2,radius*2),90,90);
        drawPath->arcTo(QRect(0,0,radius*2,radius*2),180,90);
        drawPath->arcTo(QRect(0,0,radius*2,radius*2),270,static_cast<int>(90-theta/M_PI*180));
        drawPath->lineTo(static_cast<int>(x_move),static_cast<int>(radius-y_move));
        drawPath->arcTo(QRect(0,0,radius*2,radius*2),90-static_cast<int>(90-theta/M_PI*180),static_cast<int>(90-theta/M_PI*180));
    }


    if(percent>0.25)
        painter.fillPath(*drawPath,QColor(6, 118, 216));//前景色
    else
        painter.fillPath(*drawPath,QColor(205,38,38));//时间剩余不足时改为红色



}

