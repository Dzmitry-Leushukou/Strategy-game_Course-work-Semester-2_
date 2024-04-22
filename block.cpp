#include "block.h"

Block::Block(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    //qDebug()<<pixmap();
    setPixmap(QPixmap(":game/resource/water.png"));
    //qDebug()<<pixmap();
    owner=0;
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
