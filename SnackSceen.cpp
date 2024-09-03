#include "SnackSceen.h"
#include<QTimerEvent>
#include<QGraphicsRectItem>
#include<QKeyEvent>
#include<qrandom.h>
#define random() QRandomGenerator::global()->bounded(999999)
#define randomPos() QPointF(random()%static_cast<int>(width()/10)*10,random()%static_cast<int>(height()/10)*10)
SnackSceen::SnackSceen(qreal x, qreal y, qreal width, qreal height, QObject *parent)
    :QGraphicsScene(x,y,width,height,parent)
{
    init();
    //启动定时器
    GameTimerID=startTimer(100);
}

SnackSceen::~SnackSceen()
{
    killTimer(GameTimerID);
}

void SnackSceen::init()
{
    //往场景中添加三个蛇身体,注意，里面的坐标参数是相对于内部矩形的
    Nodes<<addRect(0,0,10,10);//蛇头
    Nodes<<addRect(0,0,10,10);
    Nodes<<addRect(0,0,10,10);
    //设置在场景上面的坐标
    for(int i= 0;i<Nodes.size();i++)
    {
        Nodes[i]->setPos((2-i)*10,0);
    }
    //添加食物
    foodItem=creatNode<QGraphicsRectItem*>(randomPos());
    //分数
    scoreItem=addSimpleText("分数:0");
    scoreItem->setPos(0,0);
}

void SnackSceen::autoMove()
{
    //蛇身跟着蛇头移动
    for(int i = Nodes.size()-1;i>0;i--)
    {
        Nodes[i]->setPos(Nodes[i-1]->pos());
    }
    //蛇头移动
    Nodes[0]->moveBy(dirX,dirY);
    //判断是否碰撞到食物
    if(Nodes[0]->collidesWithItem(foodItem,Qt::ContainsItemBoundingRect))
    {
        Nodes<<creatNode<QGraphicsRectItem*>(QPointF(-10,-10));
        foodItem->setPos(randomPos());
        score+=10;
        scoreItem->setText(QString("分数:%1").arg(score));
    }

}
template<typename T>
T SnackSceen::creatNode(const QPointF& pos)
{
    auto item=new QGraphicsRectItem(0,0,10,10);
    item->setPos(pos);
    item->setBrush(QColor(QRandomGenerator::global()->bounded(256),QRandomGenerator::global()->bounded(256),QRandomGenerator::global()->bounded(256)));
    addItem(item);
    return item;
}

void SnackSceen::timerEvent(QTimerEvent *ev)
{
    if(ev->timerId() == GameTimerID)
    {
        autoMove();
    }
}

void SnackSceen::keyPressEvent(QKeyEvent *ev)
{
    switch (ev->key())
    {
    case Qt::Key::Key_Up:
        dirX=0;
        dirY=-10;
        break;
    case Qt::Key::Key_Down:
        dirX=0;
        dirY=10;
        break;
    case Qt::Key::Key_Left:
        dirY=0;
        dirX=-10;
        break;
    case Qt::Key::Key_Right:
        dirY=0;
        dirX=10;
        break;
    }
}
