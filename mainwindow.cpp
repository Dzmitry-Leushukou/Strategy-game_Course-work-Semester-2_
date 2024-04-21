#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    GameWindow=new Game();
    connect(GameWindow, &Game::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PlayButton_clicked()
{
    GameWindow->show();
    this->close();
}


void MainWindow::on_ExitButton_clicked()
{
    exit(0);
}
