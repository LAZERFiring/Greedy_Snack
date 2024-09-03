#include<QApplication>
#include<QGraphicsView>
#include"SnackSceen.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView w;
    SnackSceen* s=new SnackSceen(0,0,640,480,&w);
    w.setScene(s);
    w.show();
    return a.exec();
}
