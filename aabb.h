#ifndef AABB_H
#define AABB_H

#include <QRectF>
#pragma once

class AABB
{
public:
    AABB(QRectF);
    AABB(QRectF, QRectF);
    QRectF a,b;
    bool collide=false;
};

#endif // AABB_H
