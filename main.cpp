#include "mygraphicsview.h"
#include "mygraphicsscene.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MyGraphicsScene scene;
    MyGraphicsView view(&scene,MyGraphicsView::VIEW_XSIZE,MyGraphicsView::VIEW_YSIZE);
//    QTimer timer;
//   QObject::connect(&timer,&QTimer::timeout,&scene,&MyGraphicsScene::advance);
//     timer.start(3);


    return a.exec();
}
