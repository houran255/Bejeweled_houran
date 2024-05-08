#ifndef RECORD_H
#define RECORD_H

#include <QWidget>

namespace Ui {
class record;
}

class record : public QWidget
{
    Q_OBJECT

public:
    explicit record(QWidget *parent = nullptr);
    ~record();
    int score = 0;
    void tsInText();
    void tsOutText();
    int n = 0;
    void resetN();
    void resetScore(int s);
    void showEvent(QShowEvent *);
    QString text = "";

signals:
    void emit_back();

private slots:
    void on_pushButton_clicked();

private:
    Ui::record *ui;
};

#endif // RECORD_H
