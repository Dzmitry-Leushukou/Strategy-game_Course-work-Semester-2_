#include "unit.h"

#include "game.h"
#include "world.h"
//extern long long Game::whosTurn;

Unit::Unit(QGraphicsScene*& scene, int ** used,  std::pair<int,int>** map, QGraphicsPolygonItem *& select,QGraphicsPolygonItem *& select_block, Button *& action_button,int n) {
    this->scene=scene;
    owner=n;
    this->used=used;
    this->select_block=select_block;
    this->map=map;
    this->select=select;

    this->action_button=action_button;
    moves=1;
    //qDebug()<<"unit:"<<scene;
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
    }while(used[x1][y1]||map[x1][y1].first==0);
    setPos(x1*32+11/2,y1*32+11/2);
    used[x1][y1]=owner;
    drawUnit();
}

void Unit::Spawn(int id, int x, int y)
{
    this->id=id;
    SetAttributes();
    setPos(x*32,y*32);
    drawUnit();
}

void Unit::drawUnit()
{/*
    if(map[(int)(x()/32)][(int)(y()/32)].first==0)
        return setPixmap(QPixmap(":game/resource/ship.png"));
*/
    switch(id)
    {
    case 0:
        switch(owner)
        {
        case 1:
            setPixmap(QPixmap(":game/resource/builder.png"));
            break;
        case 2:
            setPixmap(QPixmap(":game/resource/builder2.png"));
            break;
        case 3:
            setPixmap(QPixmap(":game/resource/builder3.png"));
            break;
        case 4:
            setPixmap(QPixmap(":game/resource/builder4.png"));
            break;
        }
        break;
    case 1:
        switch(owner)
        {
        case 1:
            setPixmap(QPixmap(":game/resource/knight.png"));
            break;
        case 2:
            setPixmap(QPixmap(":game/resource/knight2.png"));
            break;
        case 3:
            setPixmap(QPixmap(":game/resource/knight3.png"));
            break;
        case 4:
            setPixmap(QPixmap(":game/resource/knight4.png"));
            break;
        }
        break;
    case 2:
        switch(owner)
        {
        case 1:
            setPixmap(QPixmap(":game/resource/knight2.png"));
            break;
        case 2:
            setPixmap(QPixmap(":game/resource/knight22.png"));
            break;
        case 3:
            setPixmap(QPixmap(":game/resource/knight23.png"));
            break;
        case 4:
            setPixmap(QPixmap(":game/resource/knight24.png"));
            break;
        }
        break;
    case 3:
        switch(owner)
        {
        case 1:
            setPixmap(QPixmap(":game/resource/settler.png"));
            break;
        case 2:
            setPixmap(QPixmap(":game/resource/settler2.png"));
            break;
        case 3:
            setPixmap(QPixmap(":game/resource/settler3.png"));
            break;
        case 4:
            setPixmap(QPixmap(":game/resource/settler4.png"));
            break;
        }
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
        attack=18,hp=20,actions=-1;
        break;
    case 3:
        attack=0,hp=10,actions=1;
        break;
    }
}

void Unit::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)//Select unit
    {
        //<<select;

        select->setPos(x(),y());

        //qDebug()<<(Game::whosTurn)%4+1<<" "<<owner;
        if(Game::whosTurn+1==owner)
            action_button->setPos(1441,730);
        else
            action_button->setPos(-32,-32);
        select_block->setPos(-32,-32);

    }
    if(event->buttons() & Qt::RightButton)//Unselect unit
    {
        select->setPos(-32,-32);
        action_button->setPos(-32,-32);

    }
}


void Unit::hide_select()
{
    select->setPos(x(),y());
}

int Unit::getMoves() const
{
    return moves;
}

void Unit::setMoves(int newMoves)
{
    moves = newMoves;
}

void Unit::action()
{
    switch(id)
    {
    case 3:
        if(World::choosed_block->isCity())
        {
            QMessageBox::warning(0,"Error","You can't place city these");
            return;
        }
        actions--;
        World::choosed_block->build_city();
        select->setPos(-32,-32);
        action_button->setPos(-32,-32);
        break;
    }
}

int Unit::getActions() const
{
    return actions;
}
