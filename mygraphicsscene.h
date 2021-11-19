#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H
#include "scorelabel.h"
#include <QWidget>
#include <QGraphicsScene>
#include "ball.h"
#include "platform.h"
#include "brick.h"
#include <QTimer>
class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MyGraphicsScene(QWidget *parent = nullptr);
      ~MyGraphicsScene();

    int getScore() const;
    void setScore(int value);
     ScoreLabel *scorelabel3;
     ScoreLabel *scorelabel4;
     const int BRICKS_COL=15;
     const int BRICKS_ROW=5;

     int getBrickcount() const;
     void setBrickcount(int value);

     QTimer* getTimer() const;

     Platform *getPlatform() const;

private:
     Ball *ball;
     Platform *platform;
     Brick **bricks;
    ScoreLabel *scorelabel;
    ScoreLabel *scorelabel2;
    int score=0;
    int brickcount=0;
    QTimer *_timer;


    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
     void keyReleaseEvent(QKeyEvent *event);



};

#endif // MYGRAPHICSSCENE_H
