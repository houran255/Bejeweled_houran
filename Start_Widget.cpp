#include "Start_Widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QList>
#include <QLabel>
#include <QPalette>
#include "myform.h"
#include <QIcon>
#include "pbtn_start.h"
#include "pbtn_game.h"
#include <QMovie>
#include <QVBoxLayout>
#include <QSplashScreen>
#include <QDateTime>
#include <QTime>
#include <QSlider>
#include "settingpage.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    my_form = new MyForm();
    my_form->show();

    re_cord->hide();

    resize(1920,1080);


    QIcon Icon_2(":/image/Icon_2.png");
    this->setWindowIcon(Icon_2);
    this->setWindowTitle(tr("宝石迷阵"));

    //showFullScreen();
    setCursor(QCursor(QPixmap(":/image/mouse1.png")));


    startButton = new Pbtn_Start();
    recordButton = new Pbtn_Start();
    settingButton = new Pbtn_Start();
    exitButton = new Pbtn_Start();

    startButton->setSound(":/music/Pbtn/button_mouseover.wav",":/music/Pbtn/button_mouseleave.wav",":/music/Pbtn/button_press.wav",":/music/Pbtn/button_release.wav");
    recordButton->setSound(":/music/Pbtn/button_mouseover.wav",":/music/Pbtn/button_mouseleave.wav",":/music/Pbtn/button_press.wav",":/music/Pbtn/button_release.wav");
    settingButton->setSound(":/music/Pbtn/button_mouseover.wav",":/music/Pbtn/button_mouseleave.wav",":/music/Pbtn/button_press.wav",":/music/Pbtn/button_release.wav");
    exitButton->setSound(":/music/Pbtn/button_mouseover.wav",":/music/Pbtn/button_mouseleave.wav",":/music/Pbtn/button_press.wav",":/music/Pbtn/button_release.wav");

    setButton();

    startButton->showContent(tr("开始游戏"),40);
    recordButton->showContent(tr("记录"),20);
    settingButton->showContent(tr("设置"),20);
    exitButton->showContent(tr("退出"),20);


     Background1.load(":/image/background2.jpg");
     Background2.load(":/backdrop00.jpg");




    //QPalette back;
    //Background1 = Background1.scaled(1920,1200,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    //back.setBrush(QPalette::Background,QPixmap(Background1));
    //this->setPalette(back);
    //this->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);


    setting = new settingPage();
    setting->resize(this->size());
    setting->hide();

    //setting->setVisible(false);

    QObject::connect(my_form,&MyForm::emit_Start,this,&Widget::slots_Start);
    //QObject::connect(this,&Widget::emit_back,my_form,&MyForm::slots_back);
    QObject::connect(exitButton,&Pbtn_Start::clicked,this,&Widget::slots_exit);
    QObject::connect(settingButton,&Pbtn_Start::clicked,this,&Widget::slots_settingPage);
    QObject::connect(setting,&settingPage::emit_pushButton_Enter,this,&Widget::slots_settingPage_exit);
    /*QObject::connect(startButton,&Pbtn_Start::clicked,[=]()
    {
        this->hide();
        game->show();
    });*/
    /*QObject::connect(game->menuButton,&Pbtn_Start::clicked,[=]()
    {
        this->show();
        delete game;
    });*/


    /*QObject::connect(setting,&settingPage::emit_pushButton_Enter,[=]()
    {
        game->volume = static_cast<double>(setting->t_getVolum())/static_cast<double>(100);
        game->setVolume();
    });*/
    connect(select,&selectlevel::selectDone,[=](int difficulty){
       this->hide();
       media->stop();

       music_list = new QMediaPlaylist(this);
       music_list->addMedia(QUrl("qrc:/music/background/music-2.wav"));
       media->setPlaylist(music_list);
       music_list->setPlaybackMode(QMediaPlaylist::Loop);
       media->play();

       game->DIFFICULTY=difficulty;
       game->setupScene(0);
       game->show();
   });
    /*connect(game->menuButton,&Pbtn_Start::clicked,[=]()
    {
        media->stop();
        this->show();
        re_cord->resetScore(game->get_score());
    });*/
    connect(game, &GameWidget::showStartPage, [=](){
        media->stop();
        this->show();

        re_cord->resetScore(game->get_score());
    });
    connect(startButton, &Pbtn_Start::clicked, [=](){
        select->setParent(this);
        select->setGeometry(700,400,800,555);
        select->setVisible(true);
    });
    connect(recordButton,&Pbtn_Start::clicked,[=]()
    {
        this->hide();
        re_cord->show();
    });
    connect(re_cord,&record::emit_back,[=](){
        re_cord->hide();
        this->show();
    });



}

Widget::~Widget()
{
    delete ui;
}

void Widget::setButton()
{
    startButton->setCircle(this->width()/10,this->width()/2,this->height()/2+100,this->width(),this->height(),
                           ":/image/Moon.png","",this);
    recordButton->setCircle(this->width()/100*5,this->width()/6,this->height()/2,this->width(),this->height(),
                            ":/image/Galaxy2.png","",this);
    settingButton->setCircle(this->width()/100*5,this->width()/6*5,this->height()/2,this->width(),this->height(),
                             ":/image/Setting.png","",this);
    exitButton->setCircle(this->width()/25,this->width()/2,this->height()/2+400,this->width(),this->height(),
                          ":/image/Galaxy3.png","",this);
}

void Widget::Sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime()<dieTime) {

    }
    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape)
    {
        this->showNormal();
        return;
    }
    if(e->key() == Qt::Key_F11)
    {
        if(this->isFullScreen() == true)
        {
            this->showNormal();
            return;
        }
        if(this->isFullScreen() == false)
        {
            this->showFullScreen();
            return;
        }
    }
}

void Widget::resizeEvent(QResizeEvent *)
{
    QPalette back;
    back.setBrush(backgroundRole(),QBrush(Background1.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(back);
    setButton();
    startButton->showContent(tr("开始游戏"),40);
    recordButton->showContent(tr("记录"),20);
    settingButton->showContent(tr("设置"),20);
    exitButton->showContent(tr("退出"),20);
}

void Widget::slots_Start()
{
    QSplashScreen splash(QPixmap(":/image/splash.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    splash.setWindowOpacity(1);//设置窗口透明度;
    splash.show();
    splash.showMessage(tr("正在加载游戏..."),Qt::AlignHCenter|Qt::AlignTop,Qt::white);
    /*QDateTime time = QDateTime::currentDateTime();
    QDateTime currentTime = QDateTime::currentDateTime();
    while (time.secsTo(currentTime)<=2) {
        currentTime = QDateTime::currentDateTime();
        //a.processEvents()使在显示启动画面时，仍能响应鼠标等事件;
    };*/

    Sleep(2000);
    splash.showMessage(tr("正在加载配置文件..."),Qt::AlignHCenter|Qt::AlignTop,Qt::white);
    Sleep(1000);
    splash.showMessage(tr("加载完毕，请稍后."),Qt::AlignHCenter|Qt::AlignTop,Qt::white);
    Sleep(500);
    splash.showMessage(tr("加载完毕，请稍后.."),Qt::AlignHCenter|Qt::AlignTop,Qt::white);
    Sleep(500);
    splash.showMessage(tr("加载完毕，请稍后..."),Qt::AlignHCenter|Qt::AlignTop,Qt::white);

    splash.finish(this);

    this->show();
    /*sound = new QSound (":/music/background/music-1.wav",this);
    sound->setLoops(-1);
    sound->play();
    */
    media = new QMediaPlayer(this);
    //media->setMedia(QUrl("qrc:/music/background/music-1.wav"));
    media->setVolume(50);
    music_list = new QMediaPlaylist(this);
    music_list->addMedia(QUrl("qrc:/music/background/music-1.wav"));
    media->setPlaylist(music_list);
    music_list->setPlaybackMode(QMediaPlaylist::Loop);
    media->play();
}

void Widget::slots_settingPage()
{
    /*QPalette pal_back;
    pal_back.setBrush(backgroundRole(),QBrush(Background2));
    setting->setPalette(pal_back);*/

    this->hide();
    setting->show();
    /*startButton->setVisible(false);
    recordButton->setVisible(false);
    settingButton->setVisible(false);
    exitButton->setVisible(false);

    setting->setVisible(true);*/
    setting->getVolume(this->media->volume());

}

void Widget::slots_settingPage_exit()
{
    //setting->setVisible(false);

    /*QPalette pal_back;
    pal_back.setBrush(backgroundRole(),QBrush(Background1));
    this->setPalette(pal_back);*/

    setting->hide();
    media->setVolume(setting->t_getVolum());
    this->show();

    /*startButton->setVisible(true);
    recordButton->setVisible(true);
    settingButton->setVisible(true);
    exitButton->setVisible(true);*/

}

void Widget::slots_exit()
{
    this->close();
}


 /*void Widget::on_pushButton_clicked()
{
    emit emit_back();
    this->close();
}
*/
