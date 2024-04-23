#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QMessageBox>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsPolygonItem>

#include "log.h"
class Block : public QGraphicsPixmapItem
{
public:
    //Constructors
    Block(short,short,  QWidget*, QGraphicsScene*,QGraphicsPolygonItem *,QGraphicsItem* parent=NULL);

    //Methods
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void getInfo();
    void selectBlock();
    //getters
    std::string get_square_info();

    //setters


    void setOwner(short newOwner);

private:
    QWidget *widget;
    QGraphicsScene *scene;
    QGraphicsPolygonItem *select;
    short int owner;
    short int building;
    short int id;
    short int resource;//0 - nothing 1 - wheat 2 - stone 3 - steal 4 - fish
};

#endif // BLOCK_H
