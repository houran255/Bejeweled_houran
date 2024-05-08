#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <myform.h>
#include "pbtn_start.h"
#include <QPixmap>
#include <QMediaPlayer>
#include <QVideoWidget>
#include "settingpage.h"
#include "gamewidget.h"
#include "selectlevel.h"
#include "record.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void setButton();
    void Sleep(int msec);

protected:
    void keyPressEvent(QKeyEvent *e);
    void resizeEvent(QResizeEvent *);

public slots:
    void slots_Start();
    void slots_settingPage();
    void slots_settingPage_exit();

signals:
    //void emit_back();

private slots:
    //void on_pushButton_clicked();
    void slots_exit();

private:
    Ui::Widget *ui;
    MyForm *my_form;
    settingPage *setting;
    selectlevel* select = new selectlevel();
    GameWidget* game = new GameWidget();
    record* re_cord = new record();


    Pbtn_Start *startButton;
    Pbtn_Start *recordButton;
    Pbtn_Start *settingButton;
    Pbtn_Start *exitButton;


    QPixmap Background1;
    QPixmap Background2;

    //QSound *sound;
    QMediaPlayer *media;
    QMediaPlaylist *music_list;

};

#endif // WIDGET_H
