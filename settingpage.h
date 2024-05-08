#ifndef SETTINGPAGE_H
#define SETTINGPAGE_H

#include <QWidget>
#include <QSlider>

namespace Ui {
class settingPage;
}

class settingPage : public QWidget
{
    Q_OBJECT

public:
    explicit settingPage(QWidget *parent = nullptr);
    ~settingPage();
    void getVolume(int back);
    void setLabelVolume();
    int t_getVolum();

protected:
    void resizeEvent(QResizeEvent *);
signals:
    void emit_pushButton_Enter();


private slots:


    void on_pushButton_Enter_clicked();

private:
    Ui::settingPage *ui;

    int volume;
    QPixmap back;
};

#endif // SETTINGPAGE_H
