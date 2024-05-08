#include "settingpage.h"
#include "ui_settingpage.h"
#include <QButtonGroup>

settingPage::settingPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingPage)
{
    ui->setupUi(this);
    resize(1920,1080);

    this->setWindowTitle(tr("设置"));
    this->setWindowIcon(QIcon(":/image/Icon_3.png"));

    QPalette pal_back;
    back.load(":/image/backdrop00.jpg");
    pal_back.setBrush(backgroundRole(),QBrush(back));
    this->setPalette(pal_back);

    ui->horizontalSlider_back->setStyleSheet("QSlider:handle{border-image:url(:/image/setting/slider-track-2.png);width:1500px;}");
    this->setCursor(QCursor(QPixmap(":/image/mouse1.png")));


    //QPalette pal_button;
    //QPixmap pushButton_back(":/image/Rocket.png");
    //pal_button.setBrush(backgroundRole(),QPixmap(pushButton_back));
    //ui->pushButton_Enter->setPalette((pal_button));
    ui->pushButton_Enter->setIcon(QIcon(":/image/Rocket.png"));

    volume = 50;
    ui->label_Value1->setText("50");
    ui->horizontalSlider_back->setMaximum(100);
    ui->horizontalSlider_back->setMinimum(0);
    setLabelVolume();

    QObject::connect(ui->horizontalSlider_back,&QSlider::valueChanged,this,&settingPage::setLabelVolume);

}

settingPage::~settingPage()
{
    delete ui;
}

void settingPage::getVolume(int back)
{
    volume = back;
}

void settingPage::setLabelVolume()
{
    ui->label_Value1->setText(tr("%1").arg(volume));

    int v = ui->horizontalSlider_back->value();
    ui->label_Value1->setText(tr("%1").arg(v));
    volume = v;
    update();
}

int settingPage::t_getVolum()
{
    return volume;
}


void settingPage::resizeEvent(QResizeEvent *)
{
    QPalette back_1;
    back_1.setBrush(backgroundRole(),QBrush(back.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(back_1);
}

void settingPage::on_pushButton_Enter_clicked()
{
    emit emit_pushButton_Enter();
    //this->setVisible(false);
}
