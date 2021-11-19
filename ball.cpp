#include "ball.h"
#include <QPainter>
#include "brick.h"
#include <QRandomGenerator>
#include "mygraphicsview.h"
#include "mygraphicsscene.h"
#include <QDebug>
Ball::Ball(QObject *parent)
{
    dx=QRandomGenerator::global()->bounded(3);
    dy=QRandomGenerator::global()->bounded(2);
    dx=dx==1?-0.5:dx/4.0;
    dy=dy==0?-0.5:0.5;


}

void Ball::advance(int phase)
{

    if(x()>=MyGraphicsView::VIEW_XSIZE-1)
    {
        dx=-dx;
    }
    if(y()>=MyGraphicsView::VIEW_YSIZE-1)
    {
          dy=-dy;
          MyGraphicsScene * sc=static_cast<MyGraphicsScene *>(scene());
          sc->setScore(sc->getScore()-10);
          sc->scorelabel3->setPlainText (QString::number(sc->getScore()));
          sc->update();

          if(sc->getScore()<=0)
          {
              sc->scorelabel4->setPlainText ("Game over");
            //  sc->getTimer()->stop();
          }
          qDebug()<<sc->getScore();

    }
    if(x()<=0)
    {
        dx=-dx;
    }
    if(y()<=0)
    {
          dy=-dy;
    }

    setPos(mapToParent(dx,dy));


}

QRectF Ball::boundingRect() const
{
    return QRectF(-20,-20,40,40);

}

QPainterPath Ball::shape() const
{
    QPainterPath path;
    path.addRect(-10,-10,20,20);
    return path;

}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->setBrush(Qt::red);
   painter->drawEllipse(-10,-10,20,20);


}

float Ball::getDy() const
{
    return dy;
}

void Ball::setDy(float value)
{
    dy = value;
}

float Ball::getDx() const
{
    return dx;
}

void Ball::setDx(float value)
{
    dx = value;
}


