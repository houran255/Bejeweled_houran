#include "pbtn_start.h"
#include <QPixmap>

Pbtn_Start::Pbtn_Start(QWidget *parent): QPushButton(parent)
{
    //设置无边框;
    setStyleSheet("QPushButton{border:Opx;}");
    label.setText("");
}

void Pbtn_Start::setImage(QString pathNormal, QString pathHorver, int width, int height, QLabel *label)
{
    w = width;
    h = height;
    //设置正常和激活后的控件图标
    //指针是否为空，1不空、2空
    if(label)
    {
        Icon_Normal = QIcon(QPixmap(pathNormal).scaled(label->width(),label->height()));
        Icon_Horver = (pathHorver != QString("") ?
                    QIcon(QPixmap(pathHorver).scaled(label->width(),label->height())):
                    QIcon(QPixmap(pathNormal).scaled(label->width(),label->height()))
                    );
    }
    else {
        Icon_Normal = QIcon(QPixmap(pathNormal));
        Icon_Horver = (pathHorver != QString("") ? QIcon(QPixmap(pathHorver)) : QIcon(QPixmap(pathNormal)));
    }

    this->setIcon(Icon_Normal);
    this->setIconSize(QSize(width,height));
}

void Pbtn_Start::setSound(QString pathHorver, QString pathLeave, QString pathPress, QString pathRelease)
{
    //设置覆盖、按压、释放、离开音效
    soundHover = (pathHorver != QString("") ? new QSound(pathHorver, this) : nullptr);
    soundPress = (pathPress != QString("") ? new QSound(pathPress, this) : nullptr);
    soundRelease = (pathRelease != QString("") ? new QSound(pathRelease, this) : nullptr);
    soundLeave = (pathLeave != QString("") ? new QSound(pathLeave, this) : nullptr);
}

void Pbtn_Start::setLabel(QString text, int size)
{
    //设置label
    textSize = size;
    label.setText(text);
    label.setParent(this);
    label.setGeometry(0,0,w,h);
    label.setAttribute(Qt::WA_TransparentForMouseEvents);
    label.setAlignment(Qt::AlignCenter);
    label.setFont(QFont("Microsoft YaHei",size,QFont::Normal));
    label.setStyleSheet("QLabel{color:white;}");
    label.setVisible(true);

}

void Pbtn_Start::setCircle(int r, int x, int y, int width, int height, QString path, QString path2, QWidget *parent)
{
    this->setParent(parent);
    setGeometry(x-r,y-r,2*r,2*r);
    setImage(path,path2,2*r,2*r);
    textAnimation->setParent(parent);
    textAnimation->setTargetObject(this);
    textAnimation->setDuration(2000);
    textAnimation->setPropertyName("geometry");
    textAnimation->setStartValue(QRect(x-r,height,2*r,2*r));
    textAnimation->setEndValue(QRect(x-r,y-r,2*r,2*r));
    textAnimation->setEasingCurve(QEasingCurve::InOutCubic);
    setVisible(false);

}

void Pbtn_Start::showContent(QString text, int size)
{
    setVisible(true);
    setLabel(text,size);
}


bool Pbtn_Start::event(QEvent *e)
{
    if(!isEnabled())
    {
        return QPushButton::event(e);
    }

    switch (e->type()) {
    case QEvent::Enter:
        setCursor(QCursor(QPixmap(":/image/mouse2.png")));
        setIcon(Icon_Horver);
        if(soundHover)
        soundHover->play();
        if(label.text()!="")
        {
            label.setFont(QFont("Microsoft YaHei",(textSize*1.5),QFont::Bold));
        }
        break;
    case QEvent::Leave:
        setCursor(QCursor(QPixmap(":/image/mouse1.png")));
        setIcon(Icon_Normal);
        if(soundLeave)
        soundLeave->play();
        if(label.text()!="")
        {
            label.setFont(QFont("Microsoft YaHei",textSize,QFont::Normal));
        }
        break;
    case QEvent::MouseButtonPress:
        //设置鼠标-press
        setCursor(QCursor(QPixmap(":/image/mouse3.png")));
        if(soundPress)
        soundPress->play();
        if(label.text()!="")
        {
            label.setFont(QFont("Microsoft YaHei",(textSize*1.5),QFont::Bold));
        }
        break;
    case QEvent::MouseButtonRelease:
        //设置鼠标-release
        setCursor(QCursor(QPixmap(":/image/mouse2.png")));
        if(soundRelease)
        soundRelease->play();
        if(label.text()!="")
        {
            label.setFont(QFont("Microsoft YaHei",textSize,QFont::Normal));
        }
        break;
    default:
        break;
    }
    return QPushButton::event(e);
}


