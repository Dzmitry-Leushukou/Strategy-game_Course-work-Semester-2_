#include "player.h"
#include "game.h"
#include "world.h"
//QVector<int> Player::resource_amount={0,0,0,0,0};
Player::Player(QGraphicsScene *&scene, int ** used,  std::pair<int,int>** map, QGraphicsPolygonItem *&select,QGraphicsPolygonItem *&select_block,Button *& action_button,int n)
{
    this->action_button=action_button;
    this->scene=scene;
    this->used=used;
    this->map=map;
    this->select_block=select_block;
    this->select=select;
    //number=n;
    //qDebug()<<u;
    units.push_back(new Unit(scene,used,map,select,select_block,action_button,n+1));
    units.back()->Spawn(3);
    //qDebug()<<"Player:"<<scene;
    scene->addItem(units.back());

    //units.back()->setScene();
    //resource_amount.resize(5);
    qDebug()<<"C:"<<select;
}

QList<Unit *> Player::getUnits() const
{
    return units;
}

bool Player::move_unit(QPointF pos, int x1, int y1)
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
            //qDebug()<<"Found unit:"<<x1<<" "<<y1;
            //qDebug()<<units[i]->pos();
            //units[i]->move(x1,y1);

            if(units[i]->getMoves()==0)return false;

            if(units[i]->getId()==2||units[i]->getId()==1)
            {
                qDebug()<<World::getBlock(x1,y1)->getOwner()<<" "<<Game::whosTurn%4;
                if(World::getBlock(x1,y1)->getOwner()!=Game::whosTurn%4)
                {

                    if(World::getBlock(x1,y1)->isCity())
                    {
                        World::getBlock(x1,y1)->attack(units[i]->getAttack());
                    }
                    else
                    {
                        bool del=false;
                        for(auto& p:Game::players)
                        {
                            int ind=0;
                            if(del)break;
                            for(auto& i:p->getUnits())
                            {
                                //qDebug()<<i->pos()<<" "<<QPointF(x1+5,y1+5);
                                if(i->pos()==QPointF(x1,y1))
                                {
                                    qDebug()<<i->getOwner();
                                    if(i->getOwner()!=Game::whosTurn%4+1)
                                    {
                                        qDebug()<<i;
                                        i->kill();
                                        //~i;
                                        p->getUnits().removeAt(ind);
                                        used[(int)pos.x()/32][(int)pos.y()/32]=true;
                                        delete i;
                                        i=nullptr;


                                        del=true;
                                        break;
                                    }
                                    else
                                    {
                                        qDebug()<<"!!!!";
                                        return false;
                                    }
                                }
                                ind++;
                            }
                        }
                        if(World::getBlock(x1,y1)->getOwner()!=-1)
                        World::getBlock(x1,y1)->setOwner(Game::whosTurn%4);
                    }
                }

                if(World::getBlock(x1,y1)->isCity())
                return false;
            }
            else if(used[x1/32][y1/32]==true){qDebug()<<"*********";return false;}

            used[x1/32][y1/32]=true;
            used[(int)pos.x()/32][(int)pos.y()/32]=false;
            units[i]->setMoves(0);
            units[i]->setPos(x1,y1);
            units[i]->hide_select();
            return true;
        }
    }
    qDebug()<<"-----------";
    return false;
}

void Player::show_units()
{
for(auto& i:units)
        scene->addItem(i);
}

bool Player::getLose() const
{
    return lose;
}

Unit *Player::getUnit(QPointF pos)
{
    for(qsizetype i=0;i<units.size();i++)
    {
        if(units[i]->pos()==pos)
        {
            return units[i];
        }
    }
}

bool Player::Spawn(double x, double y, int id)
{
    for(auto& i:units)
    {
        //qDebug()<<i->pos()<<" == "<<QPointF(x,y);
        if(i->pos()==QPointF(x,y))
            return false;
    }

    //qDebug()<<select;
    units.push_back(new Unit(scene,used,map,select,select_block,action_button,Game::whosTurn%4+1));

    //qDebug()<<"SPAWN";
    units.back()->Spawn(id,x,y);
    //qDebug()<<units.back();
    scene->addItem(units.back());
    //qDebug()<<scene->items().front();
    //scene->update();
    return true;
}

void Player::del_unit(int ind)
{
    //delete units[ind];
    //units[ind] =nullptr;

    units.removeAt(ind);
}

void Player::setLose(bool newLose)
{
    lose = newLose;
}
/*
void Player::try_to_spawn()
{

}

*/

