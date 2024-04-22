#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //gamewindow = new GameWindow();
    //connect(gamewindow, &GameWindow::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PlayButton_clicked()
{
    this->close();
    game=new Game();
    game->show();
    //gamewindow->show();
    game->start();

}


void MainWindow::on_ExitButton_clicked()
{
    exit(0);
}
