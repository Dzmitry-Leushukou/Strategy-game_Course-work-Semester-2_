#ifndef BLOCK_H
#define BLOCK_H

#include<QGraphicsPixmapItem>
#include<QDebug>

class Block : public QGraphicsPixmapItem
{
public:
    //Constructors
    Block(QGraphicsItem* parent=NULL);

    //Methods
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    //getters


    //setters


    void setOwner(short newOwner);

private:
    short int owner;
    short int building;
    short int type;
    short int subtype;
};

#endif // BLOCK_H
