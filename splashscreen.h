#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QWidget>


class SplashScreen : public QWidget
{
    Q_OBJECT
public:
    explicit SplashScreen(QWidget *parent = nullptr);

signals:
    void emit_splash_exit();
public slots:
    void slots_splash_enter();
};

#endif // SPLASHSCREEN_H
