#ifndef MYFORM_H
#define MYFORM_H

#include <QWidget>

namespace Ui {
class MyForm;
}

class MyForm : public QWidget
{
    Q_OBJECT

public:
    explicit MyForm(QWidget *parent = nullptr);
    ~MyForm();

    void resizeEvent(QResizeEvent *);
    void setBackgroundImage(QPixmap &e);

signals:
    void emit_Start();
private slots:
    void on_ptBn_StartGame_clicked();

    void on_ptBn_EndGame_clicked();
public slots:
    //void slots_back();

private:
    Ui::MyForm *ui;
};

#endif // MYFORM_H
