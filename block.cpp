#include "block.h"

Block::Block(short int id, short int res, QWidget* w,QGraphicsScene *&scene,QGraphicsPolygonItem *select, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    this->select=select;

    this->scene=scene;
    widget=w;
    this->id=id;
    resource=res;
    switch(id)
    {
        case 0:
        if(res==0)
            setPixmap(QPixmap(":game/resource/water.png"));
        if(res==4)
            setPixmap(QPixmap(":game/resource/water_fish.png"));
            break;
        case 1:
            if(res==0)
            setPixmap(QPixmap(":game/resource/grass.png"));
            if(res==1)
                setPixmap(QPixmap(":game/resource/grass_wheat.png"));
            if(res==2)
                setPixmap(QPixmap(":game/resource/grass_stone.png"));
            if(res==3)
                setPixmap(QPixmap(":game/resource/grass_iron.png"));
            break;
        default:
            if(res==0)
            setPixmap(QPixmap(":game/resource/mountain.png"));
            if(res==2)
                setPixmap(QPixmap(":game/resource/mountain_stone.png"));
            if(res==3)
                setPixmap(QPixmap(":game/resource/mountain_iron.png"));
            break;
    }

    owner=building=-1;
}

void Block::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug()<<pos().x()<<" "<<pos().y()<<" | "<<id<<" "<<resource;

    if(event->buttons() & Qt::LeftButton)
    {
        selectBlock();
        //qDebug()<<"L";
        add_log("Left Button clicked");

    }
    if(event->buttons() & Qt::RightButton)
    {

        //City check NEED
        //qDebug()<<"R";
        selectBlock();
        add_log("Right Button clicked");
        getInfo();

    }
}

void Block::getInfo()
{
   QMessageBox::about(widget,"Square info", QString::fromStdString(get_square_info()));

}

void Block::selectBlock()
{
    select->setPos(x(),y());
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

    return res;
}

void Block::setOwner(short newOwner)
{
    owner = newOwner;
}
