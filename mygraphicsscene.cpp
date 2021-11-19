#include "mygraphicsscene.h"
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include "mygraphicsview.h"
#include <QLineEdit>
#include <QRandomGenerator>
const  QColor COLORS[]{Qt::red,Qt::blue,Qt::yellow,Qt::green};
const int COLORS_COUNT=4;
const int BONUS_COUNT=10;
MyGraphicsScene::MyGraphicsScene(QWidget *parent)
{
    _timer=new QTimer;
   connect(_timer,&QTimer::timeout,this,&MyGraphicsScene::advance);
     _timer->start(4);
     scorelabel=new ScoreLabel("Arcanoid V1");
    scorelabel->setPos(10,550);
    addItem(scorelabel);

     scorelabel2=new ScoreLabel("Score: ");

      scorelabel2->setPos(300,550);
      addItem(scorelabel2);

      scorelabel3=new ScoreLabel(QString::number(0));
       scorelabel3->setPos(400,550);
       addItem(scorelabel3);
       scorelabel4=new ScoreLabel(QString::number(0));
        scorelabel4->setPos(500,550);
        addItem(scorelabel4);

    ball=new Ball;
    ball->setPos(400,300);
    addItem(ball);
    platform=new Platform;
    platform->setPos(400,500);
    addItem(platform);
    bricks=new Brick*[BRICKS_COL];
    for (int i=0;i<BRICKS_COL;i++)
    {
        bricks[i]=new Brick[BRICKS_ROW];
    }
     for(int i=0;i<BRICKS_COL;i++)
     {
         for(int j=0;j<BRICKS_ROW;j++)
         {

                 bricks[i][j].setPos( MyGraphicsView::VIEW_XSIZE/8-50+i*50,MyGraphicsView::VIEW_YSIZE-550+30*j);
                 bricks[i][j].setColor(COLORS[j%COLORS_COUNT]);
                  bricks[i][j].setBonus(j%COLORS_COUNT);
                addItem(&bricks[i][j]);
         }
     }
//     for(int i=0;i<BONUS_COUNT;i++)
//     {
//         int col=QRandomGenerator::global()->bounded( BRICKS_COL);
//         int row=QRandomGenerator::global()->bounded( BRICKS_ROW);
//         bricks[col][row].setColor(Qt::magenta);
//         bricks[col][row].setBonus(50);
//     }
     for(int i=0;i<BONUS_COUNT;i++)
     {
         int col=QRandomGenerator::global()->bounded( BRICKS_COL);
         int row=QRandomGenerator::global()->bounded( BRICKS_ROW);
         bricks[col][row].setBonus(QRandomGenerator::global()->bounded(BONUS_COUNT)+50);
         if( bricks[col][row].bonus()>55)
         {
              bricks[col][row].setColor(Qt::magenta);
         }
         else
         {
              bricks[col][row].setColor(Qt::cyan);

         }

     }




}

MyGraphicsScene::~MyGraphicsScene()
{

}

int MyGraphicsScene::getScore() const
{
    return score;
}

void MyGraphicsScene::setScore(int value)
{
    score = value;
}

int MyGraphicsScene::getBrickcount() const
{
    return brickcount;
}

void MyGraphicsScene::setBrickcount(int value)
{
    brickcount = value;
}

QTimer *MyGraphicsScene::getTimer() const
{
    return _timer;
}

Platform *MyGraphicsScene::getPlatform() const
{
    return platform;
}

void MyGraphicsScene::keyPressEvent(QKeyEvent *event)
{
    //qDebug()<<"keypressed "<<event->key();
    switch (event->key()) {
    case Qt::Key_Left:platform->setDx(-platform->DX);  //qDebug()<<"left ";
       break;
    case Qt::Key_Right:platform->setDx(platform->DX);  //qDebug()<<"right ";
        break;
    case Qt::Key_Space:if(this->getTimer()->isActive())
        {
            getTimer()->stop();

        }
        else
        {
            getTimer()->start();
        }


         break;

    }



}

void MyGraphicsScene::keyReleaseEvent(QKeyEvent *event)
{
    // qDebug()<<"keyreleased "<<event->key();
     switch (event->key()) {
      case Qt::Key_Left:platform->setDx(0);  //qDebug()<<"left ";break;
         case Qt::Key_Right:platform->setDx(0); // qDebug()<<"right ";break;

     }
}
