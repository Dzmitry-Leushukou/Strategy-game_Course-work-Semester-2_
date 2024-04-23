#include "unit.h"

Unit::Unit(QGraphicsScene* scene, bool ** used,  std::pair<int,int>** map) {
    this->scene=scene;
    this->used=used;
    this->map=map;
}

void Unit::Spawn(int id)
{
    this->id=id;
    SetAttributes();
    std::mt19937_64 gen(time(0));
    int x1,y1;
    do{
        x1=gen()%(1440/32);
        y1=gen()%(896/32);
    }while(used[x1][y1]);
    setPos(x1*32,y1*32);
    drawUnit();
}

void Unit::Spawn(int id, int x, int y)
{
    this->id=id;
    SetAttributes();
    std::mt19937_64 gen(time(0));
    setPos(x*32,y*32);
    drawUnit();
}

void Unit::drawUnit()
{
    if(map[(int)(x()/32)][(int)(y()/32)].first==0)
        return setPixmap(QPixmap(":game/resource/ship.png"));
    switch(id)
    {
    case 0:
        setPixmap(QPixmap(":game/resource/builder.png"));
        break;
    case 1:
        setPixmap(QPixmap(":game/resource/knight1.png"));
        break;
    case 2:
        setPixmap(QPixmap(":game/resource/kngiht2.png"));
        break;
    case 3:
        setPixmap(QPixmap(":game/resource/settler.png"));
        break;
    }
}

void Unit::SetAttributes()
{
    switch(id)
    {
    case 0:
        attack=0,hp=10,actions=3;
        break;
    case 1:
        attack=10,hp=20,actions=-1;
        break;
    case 2:
        attack=0,hp=20,actions=-1;
        break;
    case 4:
        attack=0,hp=10,actions=1;
        break;
    }
}
