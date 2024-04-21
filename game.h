#ifndef GAME_H
#define GAME_H

#include <QMainWindow>

namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT
signals:
    void firstWindow();

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();


private:
    Ui::Game *ui;
};

#endif // GAME_H
