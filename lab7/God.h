//
// Created by penguin augustus on 28/5/2021.
//

#ifndef _GOD_H
#define _GOD_H
#include <stdio.h>
#include <string>
#include <vector>
#include <time.h>
#include "Game.h"
#include "User.h"
#include "log.h"
#include"bonus.h"
using namespace std;

class God{
private:
    int endnum;
    int dir;
    bool cheatable;
    int mode;
    int scale;
    string cheatWords;
    int turn;
    User user1;
    User user2;
    Game game;
    bonus bonus1;
    class log log1;
    int movnum;
    int dscore;
    int WhetherLog;
    double dt;
public:
    God(int);
    ~God(){}
    void play();
    bool gameover();
    void set();
    void getdir(User *user_);
    void setcheat(User *user);
    void choosemode();
    void checkcheat(User *user);
    void whowin();
    void SinglePlay();
    void DoublePlay();
    int chess[5][5];
    void SetLog();
};
#endif //LAB7_GOD_H
