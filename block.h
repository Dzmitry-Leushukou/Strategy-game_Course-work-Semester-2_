#ifndef BLOCK_H
#define BLOCK_H

#include <QRectF>

class Block
{
public:
    Block(int, int, int);
    void update();
    //Real coords
    int getRX();
    int getRY();

    QRectF getTextureByID(int);
    QRectF texture;

    const static int SIZE = 32;
    int id,x,y;
};

#endif // BLOCK_H
