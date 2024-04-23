#ifndef BLOCK_H
#define BLOCK_H

#include<QGraphicsPixmapItem>
#include<QDebug>
#include "log.h"

class Block : public QGraphicsPixmapItem
{
public:
    //Constructors
    Block(short,short, QGraphicsItem* parent=NULL);

    //Methods
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    //getters


    //setters


    void setOwner(short newOwner);

private:
    short int owner;
    short int building;
    short int id;
    short int resource;//0 - nothing 1 - wheat 2 - stone 3 - steal 4 - fish
};

#endif // BLOCK_H
