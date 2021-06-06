//
// Created by penguin augustus on 28/5/2021.
//

#ifndef _BONUS_H
#define _BONUS_H
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include"User.h"
class User;

using namespace std;
class bonus{
public:
    bonus();
    double Time();
    double SingleBonus(User *user);

private:
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point end;
    int turn;
};
#endif //LAB7_BONUS_H
