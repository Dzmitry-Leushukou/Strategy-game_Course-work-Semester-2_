#include "game.h"

Game::Game(QWidget *parent)
{
    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1600,896);
    setFixedSize(1600,896);
    setScene(scene);

    add_log("Game scene was created");

    QPolygonF p({{0,0},{32,0},{32,32},{0,32}});
    select_block=new QGraphicsPolygonItem(p);
    select_block->setPen(QPen(QColor("yellow")));

    select_block->setPos(-32,-32);

    QPolygonF p1({{0,0},{22,0},{22,22},{0,22}});
    select_unit=new QGraphicsPolygonItem(p1);
    select_unit->setPen(QPen(QColor("red")));
    select_unit->setPos(-32,-32);

    //Make gui
    block_info=new QGraphicsTextItem();
    block_info->setPos(1440,2);
    scene->addItem(block_info);

    map = new World(scene,this,select_block,select_unit,block_info);


    add_log("Map was generated");

}

void Game::StartGame()
{
    //while(!enemies.empty())

        for(whosTurn=0;;whosTurn++)
        {

        }

}

