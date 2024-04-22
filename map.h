#ifndef MAP_H
#define MAP_H

#include <QList>
#include "block.h"
#include <QGraphicsScene>

class Map
{
public:
    //Constructors
    Map(QGraphicsScene*&);

    //Methods
    void placeBlocks();

    //getters
    QList<Block*>getBlocks();

    //setters


private:
    void createBlockColumn(int x,int y, int numOfRows);
    QList<Block*>blocks;
    QGraphicsScene *scene;
    //extern Game* game;
};

#endif // MAP_H
