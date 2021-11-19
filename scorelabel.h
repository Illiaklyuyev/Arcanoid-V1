#ifndef SCORELABEL_H
#define SCORELABEL_H
#include <QGraphicsTextItem>

class ScoreLabel : public QGraphicsTextItem
{
    Q_OBJECT
public:
    ScoreLabel(QString name, QObject *parent=nullptr);


   // QGraphicsItem interface
public:
    void advance(int phase);
//    QRectF boundingRect() const;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SCORELABEL_H
