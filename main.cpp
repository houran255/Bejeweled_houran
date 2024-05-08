#include "Start_Widget.h"
#include <QApplication>
#include <QMovie>
#include <QSplashScreen>
#include "myform.h"
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.hide();

    return a.exec();
}



