#include "record.h"
#include "ui_record.h"
#include <QTextStream>
#include <QTextCodec>
#include <QString>
#include <QFileInfo>
#include <QFile>
#include <QTime>

record::record(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::record)
{
    ui->setupUi(this);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QPalette pal;
    pal.setBrush(backgroundRole(),QBrush(QPixmap(":/image/background4.jpg").scaled(this->size(),Qt::IgnoreAspectRatio)));
    this->setPalette(pal);


    this->setWindowIcon(QIcon(":/image/Icon_3.png"));
    this->setWindowTitle(tr("记录"));

    QString strFile = QCoreApplication::applicationDirPath()+"Users.txt";
    QFile fileIn(strFile);
    QTextStream tsIn(& fileIn);
    QString strScore = tr("%1").arg(score);



}

record::~record()
{
    delete ui;
}

void record::tsInText()
{
    QString strFile = QCoreApplication::applicationDirPath()+"Users.txt";
    QFile fileIn(strFile);
    fileIn.open(QIODevice::ReadWrite);
    QTextStream tsIn(& fileIn);
    QString strScore = tr("%1").arg(score);
    n++;
    tsIn<<tr("总游玩次数: ")<<tr("%1").arg(n)<<endl;
    tsIn<<tr("姓名\t得分")<<endl;
    tsIn<<tr("第 %1 次游玩").arg(n)+"User: "+strScore;

}

void record::tsOutText()
{
    QString strFile = QCoreApplication::applicationDirPath()+"Users.txt";
    QFile fileIn(strFile);
    QTextStream tsOut(& fileIn);
    fileIn.open(QIODevice::ReadWrite);

    text = "";
    if(!fileIn.atEnd())
    {
        text += fileIn.readLine();
        text.append("\n");
    }
    ui->textBrowser->setText(text);
    QString s = "\n";
    s.append(tr("暂无数据(请先连接网络后再查看排行榜)"));
    ui->textBrowser_2->setText(s);


}

void record::resetN()
{
    QString strFile = QCoreApplication::applicationDirPath()+"Users.txt";
    QFile fileIn(strFile);
    QTextStream tsIn(& fileIn);
    fileIn.open(QIODevice::ReadWrite);

    QString num = tsIn.readLine();

    n= num.toInt();
}

void record::resetScore(int s)
{
    score = s;
}

void record::showEvent(QShowEvent *)
{
    resetN();
    tsInText();
    tsOutText();
}


void record::on_pushButton_clicked()
{
    emit emit_back();
}
