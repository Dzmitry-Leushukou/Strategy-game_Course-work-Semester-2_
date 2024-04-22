#include "block.h"

Block::Block(QGraphicsItem *parent)
{
    //draw the block
    QVector<QPointF>hexPoints;
    hexPoints<<QPointF(1,0)<<QPointF(2,0)<<QPointF(3,1)<<QPointF(2,2)<<QPointF(1,2)<<QPointF(0,1);

    QPolygonF hexagon(hexPoints);

    setPolygon(hexagon);
}
