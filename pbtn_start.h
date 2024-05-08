#ifndef PBTN_START_H
#define PBTN_START_H
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QPropertyAnimation>
#include <QEvent>
#include <QTimer>
#include <QSound>



class Pbtn_Start : public QPushButton
{
    Q_OBJECT
public:
    Pbtn_Start(QWidget *parent = nullptr);
    void setImage(QString pathNormal, QString pathHorver,int width, int height,QLabel *label = nullptr);
    void setSound(QString pathHorver = "",QString pathLeave = "",QString pathPress = "",QString pathRelease="");
    void setLabel(QString text,int size);
    void setCircle(int r , int x ,int y ,int width , int height, QString path, QString path2, QWidget *parent);
    void showContent(QString text,int size);
    QPropertyAnimation *textAnimation = new QPropertyAnimation();
    QLabel label;

protected:
    bool event(QEvent *e) override;


private:
    int w = 0;
    int h = 0;
    int textSize;
    QSound *soundHover = nullptr;
    QSound *soundPress = nullptr;
    QSound *soundRelease = nullptr;
    QSound *soundLeave = nullptr;
    QIcon Icon_Normal;
    QIcon Icon_Horver;

};

#endif // PBTN_START_H
