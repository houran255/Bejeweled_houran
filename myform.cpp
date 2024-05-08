#include "myform.h"
#include "ui_myform.h"
#include <QPalette>
#include <QPixmap>
#include <QIcon>

MyForm::MyForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyForm)
{
    ui->setupUi(this);
    resize(400,466);
    setWindowTitle(tr("宝石迷阵启动器"));
    QIcon Icon_window(":/image/Icon_1");

    setWindowIcon(Icon_window);

    //QPalette pal_title;
    //QPixmap title(":/image/title.jfif");
    //pal_title.setBrush(backgroundRole(),QPixmap(title));

    //this->setPalette(pal_title);




}

MyForm::~MyForm()
{
    delete ui;
}

void MyForm::resizeEvent(QResizeEvent *)
{
    QPixmap title(":/image/title.jfif");
    setBackgroundImage(title);
}

void MyForm::setBackgroundImage(QPixmap &e)
{
    QPalette pal_title;
    pal_title.setBrush(backgroundRole(),QBrush(QPixmap(e).scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(pal_title);
}

void MyForm::on_ptBn_StartGame_clicked()
{
    emit emit_Start();
    this->hide();
}

void MyForm::on_ptBn_EndGame_clicked()
{
    this->close();
}

/*void MyForm::slots_back()
{
    this->show();
}
*/
