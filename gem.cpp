#include "gem.h"

Gem::Gem(int type, int len, int x, int y, QWidget *parent, int offset) : QPushButton(parent), type(type), x(x), y(y)
{
    initialPath();

    oriX = LEN*x;
    oriY = LEN*(y+offset);

    setVisible(true);
    setStyleSheet(QString("QPushButton{border-image:url(%1);}").arg(path_stable[type]));
    setIconSize(QSize(len,len));

    connect(this,&Gem::pressed,[=]()
    {
        this->mouseClickedGem(this);
    });



}

void Gem::initialPath()
{
    path_stable[0] = ":/image/Magic.png";
    path_stable[1] = ":/image/Blue.png";
    path_stable[2] = ":/image/Green.png";
    path_stable[3] = ":/image/Purple.png";
    path_stable[4] = ":/image/Yellow.png";
    path_stable[5] = ":/image/Gray.png";
    path_stable[6] = ":/image/Orange.png";
    path_stable[7] = ":/image/Red.png";

    path_dynamic[0] = ":/image/Magic.gif";
    path_dynamic[1] = "";
    path_dynamic[2] = "";
    path_dynamic[3] = "";
    path_dynamic[4] = "";
    path_dynamic[5] = "";
    path_dynamic[6] = "";
    path_dynamic[7] = "";
    path_dynamic[11] = ":/image/goldSQ.gif";
    path_dynamic[12] = ":/image/waterSQ.gif";
    path_dynamic[13] = ":/image/fire.gif";
}

void Gem::bomb()
{
    delete this;
}
