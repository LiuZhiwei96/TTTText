#ifndef GAMESENSE_H
#define GAMESENSE_H

#include <QMainWindow>
#include "gamebutton.h"
#include "dataconfig.h"

namespace Ui {
class GameSense;
}

class GameSense : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameSense(int number);
    ~GameSense();

    void paintEvent(QPaintEvent *);

    //维护游戏的二维数组
    int gameArray[4][4];

    GameButton * button[4][4]; //储存新创建出的游戏按钮

    bool isWin;//检测游戏是否胜利的标志

private:
    Ui::GameSense *ui;

signals:
    void back();
};

#endif // GAMESENSE_H
