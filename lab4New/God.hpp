//
//  God.hpp
//  lab4New
//
//  Created by penguin augustus on 25/4/2021.
//

#ifndef God_hpp
#define God_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Game.hpp"
#include "User.hpp"
using namespace std;

class God{
private:
    int endnum;
    int dir;
    bool cheat;
    int mode;
    int scale;
    string cheatWords;
    int turn=0;
    User user1;
    User user2;
    Game game;
public:
    God(int);
    ~God();
    void play();
    bool gameover();
    void set();
    void getdir(User *user);
    void setcheat(User *user);
    void choosemode();
    void checkcheat(User *user);
    void whowin();
    void SinglePlay();
    //void DoublePlay();
};
#endif /* God_hpp */
