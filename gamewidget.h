#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>
#include <QPropertyAnimation>
#include <QLabel>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QIcon>
#include <QTimer>
#include <QRandomGenerator>
#include <QTime>
#include <QSound>
#include <QSoundEffect>
#include <QFont>
#include <QTemporaryDir>
#include "gem.h"
#include "pbtn_start.h"
#include "settingpage.h"
#include "myprobar.h"

#define TO_BOMB 100

namespace Ui {
class GameWidget;
}

class Point{
public:
    int x;
    int y;
    Point(int x1,int y1){x=x1;y=y1;}
};

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = nullptr);
    ~GameWidget();
    int DIFFICULTY = 5;
    void setAdaptedImage(QString path,QLabel *label);
    void setupScene(int i);
    QSoundEffect* sound;

    Pbtn_Start *menuButton = nullptr;
    double volume = 0.5;
    void setVolume();
    int get_score();

protected:
    virtual void keyPressEvent(QKeyEvent *ev) override;

private:
    Ui::GameWidget *ui;
    bool GameOver = false;
    int FTime = 0;
    int mousePosX = -1;
    int mousePosY = -1;
    bool exitMagic = false;

    int hintArrowTimes = 6;
    int score = 0;
    bool is_acting = false;
    bool is_paused = false;
    int eliminateTimes = 0;
    QSound *effect = nullptr;

    QLabel *scoreTextLabel = nullptr;

    QLabel *pauseBKLabel = nullptr;
    QMovie *pauseBKgif = nullptr;
    QLabel *pauseTXLabel = nullptr;

    int fallNum = 0;
    int fallCount = 0;

    unsigned int gemType[8][8];
    Gem* gems[8][8];
    int fallHeight[8][8];//掉落高度
    std::vector<Gem*> bombList;//存放消除的宝石
    int updateBombList();

    QWidget* boardWidget = nullptr;
    Pbtn_Start *resetButton = nullptr;
    Pbtn_Start *hintButton = nullptr;
    Pbtn_Start *pauseButton =nullptr;
    MyProBar *progressBar = nullptr;
    QTimer *progressTimer = nullptr;
    QLabel *selectedLabel = nullptr;
    QTimer *timeoutTimer = nullptr;
    QLabel *outLabel = nullptr;
    QTimer *redBoardTimer = nullptr;
    QLabel *redLabel = nullptr;

    int redBoardershow = 0;
    double trans = 0;

    QPropertyAnimation *startfallAnimation (Gem *gem, int h);
    int randomGem();
    void startGame();
    void fall();
    void fill();
    void magicFall();
    void magicFill();
    void makeStopSpin(int , int );
    void makeSpin(int , int );
    void swap(int ,int ,int gemX,int gemY);
    void eliminateBoard();
    Point tipsdetect();

    void fallAnimation(Gem *gem,int h);
    void fillfallAnimation(Gem *gem,int h);
    void Sleep(int msec);
    void act(Gem *gem);
    int selectedX = -1;
    int selectedY = -1;
    void playSound(int type);
    void forbidAll(bool forbid);
    std::vector<Gem *> bombsToMakeMagic1;
    std::vector<Gem *> bombsToMakeMagic2;
    std::vector<Gem *> tList1;
    std::vector<Gem *> tList2;
    int getBombsToMakeMagic(int cX,int cY,std::vector<Gem *> bombToMakeMagic,int time);
    void generateMagic(int cX,int cY,int type,int time);
    void finishAct();
    int tHeight[8][8];
    void magicCollect(int coType,int toX,int toY);

    void allFallOut();
    void reSetBoard();
    void update(int score);



signals:
    void showStartPage();
    void eliminateFinished();
    void myMouseMove(QMouseEvent *);
    void finishCount();


};

#endif // GAMEWIDGET_H
