#include "slidepixmap.h"

SlidePixmap::SlidePixmap(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(parent->width()/3,0,parent->width()/3*2,parent->height());

    Red.load(":/image/Red.png");
    Blue.load(":/image/Blue.png");
    Green.load(":/image/Green.png");
    Purple.load(":/image/Purple.png");
    Yellow.load(":/image/Yellow.png");
    Gray.load(":/image/Gray.png");
    Orange.load(":/image/Orange.png");


}

SlidePixmap::~SlidePixmap()
{

}

void SlidePixmap::SetPos(int mPos, bool nFlag)
{
    if(mPos > m_nMax)
    {

    }

}
