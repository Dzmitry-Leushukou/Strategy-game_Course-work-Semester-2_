#include "world.h"
//#include "game.h"





World::World(QGraphicsScene* &scene, QWidget* w)
{
    this->scene=scene;
    qDebug()<<scene;
    widget=w;
    gen.seed(time(0));

    QPolygonF p({{0,0},{32,0},{32,32},{0,32}});
    select=new QGraphicsPolygonItem(p);
    select->setPen(QPen(QColor("yellow")));

    placeBlocks();

    scene->addItem(select);
    select->setPos(-32,-32);
}

void World::placeBlocks()
{
    unitstay=new bool*[1440/32];
    map = new std::pair<int,int>*[1440/32];
    for(int i=0;i<1440/32;i++)
    {
        unitstay[i]=new bool[896/32];
        map[i]=new std::pair<int,int>[896/32];
        for(int j=0;j<896/32;j++)
        {
            unitstay[i][j]=false;
            short id=generate_block(),res=gen_res(id);
            if(i==0||i==1440/32-1||j==0||j==896/32-1)
                id=0,res=gen_res(id);
            //qDebug()<<id;
            map[i][j]={id,res};
            Block* block=new Block(id,res, widget,scene,select);
            //qDebug()<<select;
            block->setPos(32*i,32*j);
            blocks.push_back(block);
            scene->addItem(block);
        }
    }
}

short World::generate_block()
{

    short g=gen()%8;
    //qDebug()<<"Gen:"<<g;
    if(g<1)
    {
        return 0;
    }
    g=gen()%10;
    //qDebug()<<"Gen:"<<g;
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

Block *World::getBlock(int x, int y)
{
    x/=32;
    y/=32;
    int ind=y+(x-1)*(896/32);
    return blocks[ind];
}

bool** World::getUnitstay()
{
    return unitstay;
}

std::pair<int, int> **World::getMap()
{
    return map;
}
