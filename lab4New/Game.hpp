//
//  Game.hpp
//  lab4New
//
//  Created by penguin augustus on 25/4/2021.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <string>
#include<vector>
class God;
using namespace std;

class Game{
private:
    int scale;
    int chess[5][5];
    int ChessTry[5][5];
public:
    Game(int);
    Game();
    ~Game();
    void showchessboard();
    void generate();
    int trymove();
    int realmove(int);
    int move(int chess_[5][5],int);
    bool checkwin();//xanweishixian64
    int getscale();
    void InputScale(int);
    friend class God;
};
#endif /* Game_hpp */
