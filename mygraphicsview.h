#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
   static const int VIEW_XSIZE=800;
    static const int VIEW_YSIZE=600;
    MyGraphicsView(QGraphicsScene *scene,int xSize,int ySize, QWidget *parent = nullptr);
    ~MyGraphicsView();

};
#endif // MYGRAPHICSVIEW_H
