#ifndef WORLD_H
#define WORLD_H

#include <QList>
#include "block.h"
#include <QGraphicsScene>
#include <ctime>
#include <random>
#include "city.h"

class World
{
public:
    //Constructors
    World(QGraphicsScene*&);

    //Methods
    void placeBlocks();
    short generate_block();
    short gen_res(short);
    //getters
    QList<Block*>getBlocks();

    //setters


private:
    void createBlockColumn(int x,int y, int numOfRows);
    QList<Block*>blocks;
    QList<city*>cities;
    QGraphicsScene *scene;
    std::mt19937 gen;
};

#endif // WORLD_H
