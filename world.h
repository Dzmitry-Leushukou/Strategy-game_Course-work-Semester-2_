#ifndef WORLD_H
#define WORLD_H

#include <QList>
#include "block.h"
#include <QGraphicsScene>
#include <ctime>
#include <random>
#include <QWidget>
#include "city.h"
#include <queue>


class World
{
public:
    //Constructors
    World(QGraphicsScene*&, QWidget*);

    //Methods
    void placeBlocks();
    short generate_block();
    short gen_res(short);
    void normalise_world();

    //Getters
    QList<Block*>getBlocks();
    Block* getBlock(int,int);
    bool** getUnitstay();
    std::pair<int,int> **getMap();

    //Setters


private:
    void createBlockColumn(int x,int y, int numOfRows);
    QList<Block*>blocks;
    QList<city*>cities;
    QGraphicsScene *scene;
    QWidget *widget;
    std::mt19937 gen;
    QGraphicsPolygonItem * select;
    bool **unitstay;
    int** height_map;
    std::pair<int,int> **map;
};

#endif // WORLD_H
