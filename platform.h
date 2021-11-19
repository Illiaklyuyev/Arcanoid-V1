#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsObject>
class Platform : public QGraphicsObject
{
    Q_OBJECT

public:
    Platform(QObject *parent=nullptr);

    // QGraphicsItem interface
public:
    void advance(int phase);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    float  dx() const;
    void setDx(float  dx);
    const int DX=1;

  const int DEFAULT_WIGHT=60;
    int getWight() const;
    void setWight(int value);

    int getCollideCount() const;
    void setCollideCount(int value);


    bool getBonuIsUsing() const;
    void setBonuIsUsing(bool value);

private:
    float _dx;
    const int MAX_BALL_SPEED=1;
    int wight=60;
    int collideCount=0;
    bool bonuIsUsing=false;


};

#endif // PLATFORM_H
