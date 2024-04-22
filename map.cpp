#include "map.h"
//#include "game.h"





Map::Map(QGraphicsScene* &scene)
{
    qDebug()<<scene;
    this->scene=scene;
}

void Map::placeBlocks()
{
    createBlockColumn(100,100,5);
}

QList<Block *> Map::getBlocks()
{
    return blocks;
}

void Map::createBlockColumn(int x, int y, int numOfRows)
{
    //extern Game* game;
    //created a column of Blocks
    for(int i=0,n=numOfRows;i<n;i++)
    {
        Block* block=new Block();
        block->setPos(x,y+32*i);
        blocks.append(block);
        scene->addItem(block);
    }
}
