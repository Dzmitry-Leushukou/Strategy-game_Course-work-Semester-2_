#include "world.h"
//#include "game.h"





World::World(QGraphicsScene* &scene)
{
    this->scene=scene;
    gen.seed(time(0));
}

void World::placeBlocks()
{

    for(int i=0;i<1440/32;i++)
    {
        for(int j=0;j<896/32;j++)
        {
            short id=generate_block(),res=gen_res(id);
            qDebug()<<id;

            Block* block=new Block(id,res);
            block->setPos(32*i,32*j);
            blocks.append(block);
            scene->addItem(block);
        }
    }
}

short World::generate_block()
{

    short g=gen()%8;
    qDebug()<<"Gen:"<<g;
    if(g<1)
    {
        return 0;
    }
    g=gen()%10;
    qDebug()<<"Gen:"<<g;
    if(g>0)
        return 1;
    return 2;
}

short World::gen_res(short id)
{
    short res;
    //0 - nothing 1 - wheat 2 - stone 3 - steal 4 - fish
    if(id==0)
    {
        res=gen()%10;
        if(res!=4)return 0;
        return 4;
    }
    if(id==1)
    {
        res=gen()%6;
        if(res==0)
        {
            res=gen()%10;
            if(res<6)
                return 1;
            if(res<8)
                return 2;
                return 3;
        }
        return 0;
    }
    if(id==2)
    {
        res=gen()%3;
        if(res==0)
        {
            res=gen()%10;
            if(res<6)
                return 2;
            return 3;
        }
        return 0;
    }
}

QList<Block *> World::getBlocks()
{
    return blocks;
}
