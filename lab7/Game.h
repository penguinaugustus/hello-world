//
// Created by penguin augustus on 28/5/2021.
//

#ifndef _GAME_H
#define _GAME_H
#include <stdio.h>
#include <string>
#include<vector>
#include<map>

class God;
using namespace std;

class Game{
private:
    int scale;
    int chess[5][5];
    int ChessTry[5][5];
    int WhetherMove;
    bool Movable[4];
    int RandX,RandY;
    string MovableDir;
public:
    Game(int);
    Game();
    Game(int,int chess_[5][5]);
    ~Game(){}
    void showchessboard();
    void generate();
    int trymove();
    int realmove(int);
    int move(int chess_[5][5],int);
    bool checkwin(int);
    int getscale();
    void InputScale(int);
    bool GetMovable(int dir);
    string GetMovableDir();
    void CopyChess(int Chess1[5][5],int Chess2[5][5]);
    friend class God;
};
#endif //LAB7_GAME_H
