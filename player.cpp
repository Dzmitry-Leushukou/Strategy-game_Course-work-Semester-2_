#include "player.h"

Player::Player(QGraphicsScene *&scene, bool ** used,  std::pair<int,int>** map, QGraphicsPolygonItem *select,QGraphicsPolygonItem *select_block)
{
    this->scene=scene;
    this->used=used;
    this->map=map;
    this->select_block=select_block;
    Unit* u=new Unit(scene,used,map,select,select_block);
    u->Spawn(3);
    units.push_back(u);
    //qDebug()<<units.size();
    scene->addItem(u);
    scene->addItem(select);
    qDebug()<<select;
    //qDebug()<<u->pos();
}

QList<Unit *> Player::getUnits() const
{
    return units;
}

void Player::move_unit(QPointF pos, int x1, int y1)
{
    //qDebug()<<"Doshli";
    //qDebug()<<x<<" "<<y;

    //qDebug()<<select;
    for(qsizetype i=0;i<units.size();i++)
    {
        //qDebug()<<"dsd";
        //qDebug()<<i->pos();
        //qDebug()<<i;

        if(units[i]->pos()==pos)
        {
            qDebug()<<"Found unit:"<<x1<<" "<<y1;
            qDebug()<<units[i]->pos();
            //units[i]->move(x1,y1);


            units[i]->setPos(x1,y1);
            units[i]->hide_select();
            return;
        }
    }
}

void Player::show_units()
{
for(auto& i:units)
        scene->addItem(i);
}

