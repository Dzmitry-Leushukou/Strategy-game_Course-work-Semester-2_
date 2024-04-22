#ifndef AABB_H
#define AABB_H

#include <QRectF>

class AABB
{
public:
    AABB(QRectF);
    AABB(QRectF, QRectF);
    QRectF a,b;
    bool collide=false;
};

#endif // AABB_H
