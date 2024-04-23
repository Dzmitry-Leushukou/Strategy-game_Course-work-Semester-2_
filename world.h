#ifndef WORLD_H
#define WORLD_H

#include <QList>
#include "block.h"
#include <QGraphicsScene>
#include <ctime>
#include <random>
#include <QWidget>
#include "city.h"


class World
{
public:
    //Constructors
    World(QGraphicsScene*&, QWidget*);

    //Methods
    void placeBlocks();
    short generate_block();
    short gen_res(short);
    //getters
    QList<Block*>getBlocks();
    Block* getBlock(int,int);
    //setters

private:
    void createBlockColumn(int x,int y, int numOfRows);
    QList<Block*>blocks;
    QList<city*>cities;
    QGraphicsScene *scene;
    QWidget *widget;
    std::mt19937 gen;
    QGraphicsPolygonItem * select;
};

#endif // WORLD_H
