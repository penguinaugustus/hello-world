//
// Created by penguin augustus on 28/5/2021.
//

#ifndef _USER_H
#define _USER_H

#include <stdio.h>
#include <string>
#include<vector>

class God;

using namespace std;

class User{
public:
    User(string);
    User();
    int getscore();
    void addscore(int);
    void inputname(string);
    string GetName();
    void SetCheatstate();
    int CheckCheatstate();
    //void getname();
    //friend class God;
private:
    int score;
    string username;
    int cheatstate;
};
#endif //LAB7_USER_H
