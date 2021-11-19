#ifndef BALL_H
#define BALL_H

#include <QGraphicsObject>

class Ball : public QGraphicsObject
{
    Q_OBJECT
public:
    Ball(QObject *parent=nullptr);


    // QGraphicsItem interface
public:
    void advance(int phase);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float getDy() const;

    void setDy(float value);

    float getDx() const;
    void setDx(float value);



private:

    float dx;
    float dy;

    // MyGraphicsScene _scene;

};

#endif // BALL_H
