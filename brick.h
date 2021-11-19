#ifndef BRICK_H
#define BRICK_H
#include <QGraphicsObject>

class Brick : public QGraphicsObject
{
    Q_OBJECT

public:
    Brick(QObject *parent=nullptr);

    // QGraphicsItem interface
public:
    //void advance(int phase);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // QGraphicsItem interface
public:
    void advance(int phase);

    void setColor(const QColor &color);

    int bonus() const;
    void setBonus(int bonus);

    QColor color() const;

private:
    QColor _color;
    int _bonus;



};

#endif // BRICK_H
