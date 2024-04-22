#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    //QScreen *chosen = this;
    QRect resolution=this->geometry();
    scene.setSceneRect(0, 0, resolution.width(), resolution.height());
    View *view = new View(&scene);

    //showFullScreen();
    //QTimer::singleShot(1000, this, SLOT(showFullScreen()));

    // /this->setCentralWidget(view);
}

GameWindow::~GameWindow()
{
    delete ui;
}
