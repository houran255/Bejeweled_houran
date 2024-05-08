#ifndef SELECTLEVEL_H
#define SELECTLEVEL_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class selectlevel;
}

class selectlevel : public QWidget
{
    Q_OBJECT

public:
    explicit selectlevel(QWidget *parent = nullptr);
    ~selectlevel();
    QLabel*level1L=new QLabel("选择");
    QLabel*level2L=new QLabel("选择");
    QLabel*level3L=new QLabel("选择");

private slots:


    void initColor();

    void on_level1B_pressed();

    void on_level1B_released();

    void on_level2B_pressed();

    void on_level2B_released();

    void on_level3B_pressed();

    void on_level3B_released();


    void on_DoneB_clicked();

    void on_level1B_clicked();

    void on_level2B_clicked();

    void on_level3B_clicked();

    void on_DoneB_pressed();

    void on_DoneB_released();

private:
    Ui::selectlevel *ui;
    QPalette white;
    QPalette dyellow;
    QPalette purple;
    int level=4;
    void paintEvent(QPaintEvent *);
    QPixmap pixmap=QPixmap(":/image/setting/score.png").scaled(QSize(574,307));
signals:
    void selectDone(int difficulty);
};

#endif // SELECTLEVEL_H
