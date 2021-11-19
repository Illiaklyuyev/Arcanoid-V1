#include "platform.h"
#include<QPainter>
#include "mygraphicsview.h"
#include "ball.h"
#include <QRandomGenerator>
#include <cmath>

Platform::Platform(QObject *parent)
{
    _dx=0;

}

void Platform::advance(int phase)
{


    setPos(mapToParent(_dx,0));
    if(x()>=MyGraphicsView::VIEW_XSIZE-1)
    {

        setDx(0);
        setPos(MyGraphicsView::VIEW_XSIZE-1,y());

    }


    if(x()<=0)
    {
        setDx(0);
        setPos(0,y());

    }

    if(scene()->collidingItems(this).size()>0)
    {

        Ball* ball=static_cast<Ball *>(scene()->collidingItems(this).at(0)) ;
        ball->setDy(-ball->getDy());
        if(ball->getDx()<=0)
        {
            ball->setDx(-fmin(abs(ball->getDx()+this->dx()/2),MAX_BALL_SPEED));
        }
        else  if(ball->getDx()>=0)
        {
            ball->setDx(fmin(abs(ball->getDx()+this->dx()/2),MAX_BALL_SPEED));

        }
        if(bonuIsUsing)
        {
            setCollideCount(getCollideCount()+1);
            if(getCollideCount()==5)
            {
                setWight(DEFAULT_WIGHT);
                scene()->update();
                bonuIsUsing=false;
                setCollideCount(0);
            }
        }


    }


}

QRectF Platform::boundingRect() const
{
    return QRectF(-wight/2,-10,wight,20);
}

QPainterPath Platform::shape() const
{
    QPainterPath path;
    path.addRect(-wight/2,-10,wight,20);
    return path;

}

void Platform::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(Qt::blue);
    painter->drawRect(-wight/2,-10,wight,20);


}



float  Platform::dx() const
{
    return _dx;
}

void Platform::setDx(float  dx)
{
    _dx = dx;
}

int Platform::getWight() const
{
    return wight;
}

void Platform::setWight(int value)
{
    wight = value;
}

int Platform::getCollideCount() const
{
    return collideCount;
}

void Platform::setCollideCount(int value)
{
    collideCount = value;
}

bool Platform::getBonuIsUsing() const
{
    return bonuIsUsing;
}

void Platform::setBonuIsUsing(bool value)
{
    bonuIsUsing = value;
}



