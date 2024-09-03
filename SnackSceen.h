#ifndef SNACKSCEEN_H
#define SNACKSCEEN_H

#include<QGraphicsScene>
class SnackSceen: public QGraphicsScene
{
public:
    SnackSceen(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);
    ~SnackSceen();
    void init();
    void autoMove();
    template<typename T>
    T creatNode(const QPointF& pos);
protected:
    void timerEvent(QTimerEvent* ev)override;
    void keyPressEvent(QKeyEvent* ev)override;
private:
    QList<QGraphicsRectItem*> Nodes;
    QGraphicsRectItem* foodItem;
    QGraphicsSimpleTextItem* scoreItem;
    int score=0;
    int GameTimerID;
    int dirX=10;
    int dirY=0;
};

#endif // SNACKSCEEN_H
