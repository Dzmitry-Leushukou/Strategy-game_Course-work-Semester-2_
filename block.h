#ifndef BLOCK_H
#define BLOCK_H

#include<QGraphicsPixmapItem>

class Block : public QGraphicsPixmapItem
{
public:
    //Constructors
    Block(QGraphicsItem* parent=NULL);

    //Methods
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    //getters


    //setters


private:
    short int owner;
    short int building;
    short int type;
    short int subtype;
};

#endif // BLOCK_H
