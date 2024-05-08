#include "selectlevel.h"
#include "ui_selectlevel.h"
#include <QPainter>

selectlevel::selectlevel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectlevel)
{
    ui->setupUi(this);

    level1L->setGeometry(70,220,70,21);
    level2L->setGeometry(220,220,70,21);
    level3L->setGeometry(370,220,70,21);


    level1L->setParent(this);
    level1L->setVisible(false);
    level2L->setParent(this);
    level2L->setVisible(false);
    level3L->setParent(this);
    level3L->setVisible(false);


    QFont font ( "Arial Black",12, 87);

    level1L->setFont(font);
    level2L->setFont(font);
    level3L->setFont(font);

    level1L->setAlignment(Qt::AlignHCenter);
    level2L->setAlignment(Qt::AlignHCenter);
    level3L->setAlignment(Qt::AlignHCenter);


    //去窗口边框
    this->setWindowFlags(Qt::FramelessWindowHint | this->windowFlags());
    //把窗口背景设置为透明
    this->setAttribute(Qt::WA_TranslucentBackground);
    //鼠标移动改变形状
    ui->level1B->setCursor(QCursor(Qt::PointingHandCursor));
    ui->level2B->setCursor(QCursor(Qt::PointingHandCursor));
    ui->level3B->setCursor(QCursor(Qt::PointingHandCursor));
    ui->DoneB->setCursor(QCursor(Qt::PointingHandCursor));

    white.setColor(QPalette::WindowText,Qt::white);
    dyellow.setColor(QPalette::WindowText,Qt::darkYellow);
    purple.setColor(QPalette::WindowText,Qt::white);

    initColor();

}

selectlevel::~selectlevel()
{
    delete ui;
}

void selectlevel::initColor()
{
    level1L->setPalette(white);
    level2L->setPalette(white);
    level3L->setPalette(white);
}

void selectlevel::on_level1B_pressed()
{
    level1L->setPalette(dyellow);
}

void selectlevel::on_level1B_released()
{
    level=4;
    initColor();
    level1L->setPalette(purple);
}

void selectlevel::on_level2B_pressed()
{
    level2L->setPalette(dyellow);
}

void selectlevel::on_level2B_released()
{
    level=6;
    initColor();
    level2L->setPalette(purple);
}

void selectlevel::on_level3B_pressed()
{
    level3L->setPalette(dyellow);
}

void selectlevel::on_level3B_released()
{
    level=7;
    initColor();
    level3L->setPalette(purple);
}


void selectlevel::on_DoneB_clicked()
{

}

void selectlevel::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0, 0, pixmap);
}

void selectlevel::on_level1B_clicked()
{
    level1L->setVisible(true);
    level2L->setVisible(false);
    level3L->setVisible(false);
}

void selectlevel::on_level2B_clicked()
{
    level1L->setVisible(false);
    level2L->setVisible(true);
    level3L->setVisible(false);
}

void selectlevel::on_level3B_clicked()
{
    level1L->setVisible(false);
    level2L->setVisible(false);
    level3L->setVisible(true);
}

void selectlevel::on_DoneB_pressed()
{

}

void selectlevel::on_DoneB_released()
{
    this->setVisible(false);
    this->selectDone(level);
}
