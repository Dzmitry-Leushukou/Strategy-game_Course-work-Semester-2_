#include "block.h"

Block::Block(short int id, short int res, QWidget* w,QGraphicsScene *&scene,QGraphicsPolygonItem *select,QGraphicsPolygonItem *unit, Player*& pl, int** height_map,QGraphicsTextItem*block_info, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    this->block_info=block_info;
    this->height_map=height_map;
    this->player=pl;
    this->select=select;
    this->unit=unit;
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
        HideBlockInfo(block_info);
    }
    if(event->buttons() & Qt::RightButton)
    {
        selectBlock();
        if(unit->pos()!=QPointF(-32,-32))
        {
            std::queue<std::pair<int,std::pair<int,int>>> q;

            int **d=new int*[1440/32];
            std::pair<int,int>** pred=new std::pair<int,int>*[1440/32];
            for(int i=0;i<1440/32;i++)
            {
                d[i]=new int[896/32];
                pred[i]=new std::pair<int,int>[896/32];
                for(int j=0;j<896/32;j++)
                    d[i][j]=1e6,pred[i][j]={0,0};
            }


            if((int)unit->pos().x()/32==x()/32&&(int)unit->pos().y()/32==y()/32)//Already stay in pos
                return;

            q.push({0,{(int)unit->pos().x()/32,(int)unit->pos().y()/32}});
            d[(int)unit->pos().x()/32][(int)unit->pos().y()/32]=0;

            std::pair<int,int>p;
            while(!q.empty())
            {
                int w=(-1)*q.front().first;
                p=q.front().second;
                q.pop();
                //qDebug()<<p<<" "<<x()/32<<" "<<y()/32;
                if(p.first==x()/32&&p.second==y()/32)
                    break;
                if (w > d[p.first][p.second])  continue;

                for(int i=-1;i<=1;i++)
                {
                    for(int j=-1;j<=1;j++)
                    {
                        if((i!=0&&j!=0)||(i==0&&j==0))continue;
                        int toi=p.first+i,toj=p.second+j;
                        toi%=1440/32;
                        toj%=896/32;

                        if(toi<0)
                            toi+=1440/32;
                        if(toj<0)
                            toj+=896/32;

                        int len = abs(height_map[p.first][p.second]-height_map[toi][toj]);
                        if (d[p.first][p.second] + len < d[toi][toj]) {
                            d[toi][toj] = d[p.first][p.second] + len;
                            pred[toi][toj] = {p.first,p.second};
                            q.push ({-d[toi][toj],{ toi,toj}});
                        }
                    }

                }
            }

            while(!q.empty())
            q.pop();

            //qDebug()<<"Not find";
            if(p.first==x()/32&&p.second==y()/32)
            {
                //qDebug()<<"Find";
            }else return;


            std::pair<int,int>s={(int)unit->pos().x()/32,(int)unit->pos().y()/32},l;
            while(p!=s)
            {
                l=p;
                p=pred[p.first][p.second];
            }
            //qDebug()<<"Try to move: "<<player ;

            if(!player->move_unit(unit->pos(),l.first*32+11/2,l.second*32+11/2))
            {
                //unit_error->setPos(1440/2-50,3);
                QMessageBox::warning(widget,"Error","This unit have no steps on this turn");
            }
        }else
            getInfo();

    }
}

void Block::getInfo()
{
   add_log("Get info "+std::to_string(x()/32)+" "+std::to_string(y()/32));
   //QMessageBox::about(widget,"Square info", QString::fromStdString(get_square_info()));
   ShowBlockInfo(get_square_info(),block_info);
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
    std::string res="=====Block info=====\n";

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

    res+="Owner: ";
    if(owner==-1)
        res+="Neutral";
    else
    {
        res+="Player ";
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

void Block::setPlayer(Player *newPlayer)
{
    player = newPlayer;
}



short Block::getHeight() const
{
    return height;
}

void Block::setContinent(std::string newContinent)
{
    continent = newContinent;
}
