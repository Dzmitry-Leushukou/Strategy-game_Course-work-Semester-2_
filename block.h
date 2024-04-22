#ifndef BLOCK_H
#define BLOCK_H

#include<QGraphicsItem>

class Block : public QGraphicsPolygonItem
{
public:
    //Constructors
    Block(QGraphicsItem* parent=NULL);

    //getters


    //setters
private:
    short int owner;
    short int building;
    short int type;
    short int subtype;
};

#endif // BLOCK_H
