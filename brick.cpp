#include "brick.h"
#include <QPainter>
#include <cmath>
#include "ball.h"
#include <QDebug>
#include "mygraphicsscene.h"
#include "platform.h"
const  QColor COLORS[]{Qt::red,Qt::blue,Qt::yellow,Qt::green};
Brick::Brick(QObject *parent)
{



}

QRectF Brick::boundingRect() const
{
     return QRectF(-20,-10,40,20);
}

QPainterPath Brick::shape() const
{
    QPainterPath path;
    path.addRect(-20,-10,40,20);
    return path;
}

void Brick::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
     painter->setBrush(_color);
     painter->drawRect(-20,-10,40,20);


}

void Brick::advance(int phase)
{

    if(scene()->collidingItems(this).size()>0)
    {
        Ball* ball=static_cast<Ball *>(scene()->collidingItems(this).at(0)) ;
        MyGraphicsScene * sc=static_cast<MyGraphicsScene *>(scene());
        sc->setScore(sc->getScore()+this->bonus()+1);
        sc->scorelabel3->setPlainText (QString::number(sc->getScore()));
        sc->update();
        qDebug()<<sc->getScore();
        ball->setDy(-ball->getDy());
        ball->setDx(ball->getDx());
        if(this->color()==Qt::cyan)
        {
            sc->getPlatform()->setBonuIsUsing(true);
            sc->getPlatform()->setWight(sc->getPlatform()->DEFAULT_WIGHT*3);
        }
        sc->setBrickcount(sc->getBrickcount()+1);
       sc->scorelabel4->setPlainText (QString::number(sc->getBrickcount()));
        if(sc->getBrickcount()==75)
        {
               sc->scorelabel4->setPlainText ("Game over");
               sc->getTimer()->stop();

        }
        scene()->removeItem(this);

    }




}

void Brick::setColor(const QColor &color)
{
    _color = color;
}

int Brick::bonus() const
{
    return _bonus;
}

void Brick::setBonus(int bonus)
{
    _bonus = bonus;
}

QColor Brick::color() const
{
    return _color;
}
