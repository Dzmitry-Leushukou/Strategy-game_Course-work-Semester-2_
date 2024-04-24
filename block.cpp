#include "block.h"

Block::Block(short int id, short int res, QWidget* w,QGraphicsScene *&scene,QGraphicsPolygonItem *select, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    this->select=select;

    this->scene=scene;
    widget=w;
    this->id=id;
    this->height=id;
    resource=res;
    updateTexture();
    owner=building=-1;
}

void Block::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(event->buttons() & Qt::LeftButton)
    {
        selectBlock();
    }
    if(event->buttons() & Qt::RightButton)
    {
        selectBlock();
        getInfo();

    }
}

void Block::getInfo()
{
   add_log("Get info "+std::to_string(x()/32)+" "+std::to_string(y()/32));
   QMessageBox::about(widget,"Square info", QString::fromStdString(get_square_info()));

}

void Block::selectBlock()
{
    add_log("Select block "+std::to_string(x()/32)+" "+std::to_string(y()/32));
    select->setPos(x(),y());
}

void Block::updateTexture()
{
    switch(id)
    {
    case 0:
        if(resource==0)
            setPixmap(QPixmap(":game/resource/water.png"));
        if(resource==4)
            setPixmap(QPixmap(":game/resource/water_fish.png"));
        break;
    case 1:
        if(resource==0)
            setPixmap(QPixmap(":game/resource/grass.png"));
        if(resource==1)
            setPixmap(QPixmap(":game/resource/grass_wheat.png"));
        if(resource==2)
            setPixmap(QPixmap(":game/resource/grass_stone.png"));
        if(resource==3)
            setPixmap(QPixmap(":game/resource/grass_iron.png"));
        break;
    default:
        if(resource==0)
            setPixmap(QPixmap(":game/resource/mountain.png"));
        if(resource==2)
            setPixmap(QPixmap(":game/resource/mountain_stone.png"));
        if(resource==3)
            setPixmap(QPixmap(":game/resource/mountain_iron.png"));
        break;
    }
}

void Block::change(int id)
{
    this->id=height=id;
    updateTexture();
}

std::string Block::get_square_info()
{
    std::string res;

    res+="Type: ";
    switch (id)
    {
    case 0:
        res+="Water";
        break;

    case 1:
        res+="Grass";
        break;

    case 2:
        res+="Mountain";
        break;
    }

    res+="\n";

    res+="Resource: ";
    switch(this->resource)
    {
    case 0:
        res+="None";
        break;
    case 1:
        res+="Wheat";
        break;
    case 2:
        res+="Stone";
        break;
    case 3:
        res+="Iron";
        break;
    }

    res+="\n";

    res+="Owner: Player ";
    if(owner==-1)
        res+="Neutral";
    else
    {
        res+=std::to_string(owner);
        if(owner==0)
            res+=" (You)";
    }
    res+="\n";

    switch (id)
    {
    case 1:
        res+="Continent: "+continent;
        break;

    case 2:
        res+="Continent: "+continent;
        break;
    }
    return res;
}

void Block::setOwner(short newOwner)
{
    owner = newOwner;
}

short Block::getHeight() const
{
    return height;
}

void Block::setContinent(std::string newContinent)
{
    continent = newContinent;
}
