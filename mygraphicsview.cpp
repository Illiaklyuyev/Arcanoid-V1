#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QGraphicsScene *scene,int xSize,int ySize, QWidget *parent)
    : QGraphicsView(scene,parent)
{
    setFixedSize(xSize,ySize);
    setSceneRect(0,0,xSize,ySize);
    show();
    fitInView(0,0,xSize,ySize,Qt::KeepAspectRatio);



}

MyGraphicsView::~MyGraphicsView()
{
}

