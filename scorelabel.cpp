#include "scorelabel.h"
#include <QPainter>
#include <QFont>
#include "brick.h"
ScoreLabel::ScoreLabel(QString name ,QObject *parent)
{

   setPlainText(name);
   QFont *font = new QFont("Courier New", 20, 900);
   setFont(*font);




}

void ScoreLabel::advance(int phase)
{
    

}

//QRectF ScoreLabel::boundingRect() const
//{
//    return QRectF(-20,-10,40,20);

//}

//void ScoreLabel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//   // painter->setBrush(Qt::white);
//    painter->drawRect(-20,-10,40,20);

//}
