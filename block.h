#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QMessageBox>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <queue>
#include <stack>
#include <QTimer>
#include <QObject>
#include <QMainWindow>

#include "log.h"
#include "player.h"
class Block : public QGraphicsPixmapItem
{
    //Q_OBJECT
public:
    //Constructors
    Block(short,short,  QWidget*, QGraphicsScene*&,QGraphicsPolygonItem *,QGraphicsPolygonItem *, Player*& pl,int** height_map,QGraphicsItem* parent=NULL);

    //Methods
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void getInfo();
    void selectBlock();
    void updateTexture();
    void change(int id);

    //getters
    std::string get_square_info();
    short getHeight() const;

    //setters
    void setContinent(std::string newContinent);
    void setOwner(short newOwner);
    void setPlayer(Player *newPlayer);
    void setUnit_error(QGraphicsTextItem *newUnit_error);

public slots:
    void HideError();
    void ShowError();
private:
    QWidget *widget;
    QGraphicsScene *scene;
    QGraphicsPolygonItem *select;
    QGraphicsPolygonItem *unit;
    QGraphicsTextItem * unit_error;


    Player* player;

    std::string continent="";
    short int height;
    short int owner;
    short int building;
    short int id;
    short int resource;//0 - nothing 1 - wheat 2 - stone 3 - steal 4 - fish
    int** height_map;
};

#endif // BLOCK_H
