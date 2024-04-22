#include "map.h"
//#include "game.h"





Map::Map(QGraphicsScene* &scene)
{
    this->scene=scene;
}

void Map::placeBlocks()
{

    for(int i=0;i<1440/32;i++)
    {
        for(int j=0;j<896/32;j++)
        {
        Block* block=new Block();
        block->setPos(32*i,32*j);
        blocks.append(block);
        scene->addItem(block);
        }
    }
}

QList<Block *> Map::getBlocks()
{
    return blocks;
}
