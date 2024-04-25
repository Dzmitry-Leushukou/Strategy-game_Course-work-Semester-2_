#include "gui.h"
void ShowBlockInfo(std::string info, QGraphicsTextItem* t)
{
    //qDebug()<<t;
    t->show();
    t->setPlainText(QString::fromStdString(info));
    //qDebug()<<info;
}
void HideBlockInfo(QGraphicsTextItem* t)
{
    t->hide();
}
