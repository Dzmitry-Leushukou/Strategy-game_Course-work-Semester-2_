#include "block.h"

Block::Block(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    qDebug()<<pixmap();
    setPixmap(QPixmap(":game/resource/image.png"));
    qDebug()<<pixmap();
}

void Block::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}
