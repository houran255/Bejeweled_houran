#ifndef PBTN_GAME_H
#define PBTN_GAME_H

#include <QWidget>
#include <QPushButton>

class Pbtn_Game : public QPushButton
{
    Q_OBJECT
public:
    Pbtn_Game(int type, int len, int x, int y, QWidget *parent = nullptr, int offset = 0);
    int type;
    int x;
    int y;

protected:

private:

};

#endif // PBTN_GAME_H
