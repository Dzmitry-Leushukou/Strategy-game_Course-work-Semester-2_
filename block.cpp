#include "block.h"

Block::Block(short int id, short int res, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    this->id=id;
    resource=res;
    switch(id)
    {
        case 0:
        if(res==0)
            setPixmap(QPixmap(":game/resource/water.png"));
        if(res==4)
            setPixmap(QPixmap(":game/resource/water_with_fish.png"));
            break;
        case 1:
            if(res==0)
            setPixmap(QPixmap(":game/resource/grass.png"));
            if(res==1)
                setPixmap(QPixmap(":game/resource/grass_with_wheat.png"));
            if(res==2)
                setPixmap(QPixmap(":game/resource/grass_with_stone.png"));
            if(res==3)
                setPixmap(QPixmap(":game/resource/grass_with_steel.png"));
            break;
        default:
            if(res==0)
            setPixmap(QPixmap(":game/resource/mountain.png"));
            if(res==2)
                setPixmap(QPixmap(":game/resource/mountain_with_stone.png"));
            if(res==3)
                setPixmap(QPixmap(":game/resource/mountain_with_steel.png"));
            break;
    }

    owner=building=-1;
}

void Block::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"MousePressEvent:"<<owner;
    qDebug()<<this->pos().x()<<" "<<this->pos().y();
}

void Block::setOwner(short newOwner)
{
    owner = newOwner;
}
