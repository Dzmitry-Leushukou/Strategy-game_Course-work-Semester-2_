#include "game.h"

long long Game::whosTurn=0;

Game::Game(QWidget *parent)
{
    players.resize(4);

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

    res_info=new QGraphicsTextItem();
    res_info->setPos(1440,210);
    scene->addItem(res_info);


    turn_info=new QGraphicsTextItem();
    turn_info->setPos(1440,790);
    QFont fnt;
    fnt.setBold(true);
    fnt.setPixelSize(17);
    turn_info->setFont(fnt);
    scene->addItem(turn_info);

    UpdateTurnInfo(turn_info);

    map = new World(scene,this,select_block,select_unit,block_info, players);
    add_log("Map was generated");

    //QPushButton *skip_button=new QPushButton();

    skip_button=new Button("Skip",160,80);
    skip_button->setPos(1440,816);
    connect(skip_button,SIGNAL(clicked()),this,SLOT(next_turn()));
    scene->addItem(skip_button);

    ShowResourceInfo("Money: "+std::to_string(players[whosTurn%4]->resource_amount[0])+
                         "\nStone: "+std::to_string(players[whosTurn%4]->resource_amount[1])+
                         "\nIron: "+std::to_string(players[whosTurn%4]->resource_amount[2])+
                         "\nWheat: "+std::to_string(players[whosTurn%4]->resource_amount[3])+
                         "\nFish: "+std::to_string(players[whosTurn%4]->resource_amount[4]),res_info);

}

void Game::next_turn()
{
    do{
    whosTurn++;
    //qDebug()<<whosTurn;
    map->set_player(players[whosTurn%4]);
    }while(players[whosTurn%4]->getLose());
    QMessageBox::information(this,"Turn","Player "+QString::fromStdString(std::to_string(whosTurn%4+1))+ ", your turn");
    UpdateTurnInfo(turn_info);
    ShowResourceInfo("Money: "+std::to_string(players[whosTurn%4]->resource_amount[0])+
                     "\nStone: "+std::to_string(players[whosTurn%4]->resource_amount[1])+
                     "\nIron: "+std::to_string(players[whosTurn%4]->resource_amount[2])+
                     "\nWheat: "+std::to_string(players[whosTurn%4]->resource_amount[3])+
                     "\nFish: "+std::to_string(players[whosTurn%4]->resource_amount[4]),res_info);
}

/*
void Game::StartGame()
{
    //while(!enemies.empty())

        for(whosTurn=0;;whosTurn++)
        {

        }

}
*/
