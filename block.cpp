#include "block.h"

//Block::Block() {}

Block::Block(int x, int y, int id)
{
    this->x=x;
    this->y=y;
    this->id=id;
    this->texture=getTextureByID(id);
}

void Block::update()
{

}

int Block::getRX()
{
    return this->x*SIZE;
}

int Block::getRY()
{
    return this->y*SIZE;
}

QRectF Block::getTextureByID(int)
{
    int tileSize = 16, tilesOnLine = 16;
    float tx = id%tilesOnLine, ty = id/tilesOnLine;
    QRectF texture = QRectF(tx * tileSize, ty * tileSize, tileSize, tileSize);
    return texture;
}
