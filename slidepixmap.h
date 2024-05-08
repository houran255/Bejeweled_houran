#ifndef SLIDEPIXMAP_H
#define SLIDEPIXMAP_H
#include <QWidget>
#include <QPixmap>


class SlidePixmap : public QWidget
{
    Q_OBJECT
public:
    explicit SlidePixmap(QWidget *parent = nullptr);
    ~SlidePixmap();

public:
    void SetPos(int mPos, bool nFlag = false);


signals:

public slots:


private:
    QPoint m_movePoint;
    bool m_flag_mousePress;
    bool m_flag_ThumbPress;
    bool m_bEnable;
    int m_nMouseOffset;

    bool m_bVertical;
    int m_nStep;
    int m_nPos;
    int m_nMax;
    int m_nMin;
    int m_nThumbHeight;
    int m_nThumbWidth;

    QPixmap Red;
    QPixmap Blue;
    QPixmap Green;
    QPixmap Purple;
    QPixmap Yellow;
    QPixmap Gray;
    QPixmap Orange;

};

#endif // SLIDEPIXMAP_H
