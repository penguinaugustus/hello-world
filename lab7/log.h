//
// Created by penguin augustus on 28/5/2021.
//

#ifndef _LOG_H
#define _LOG_H
#include <iostream>
#include <string>
#include<vector>
#include <fstream>
using namespace std;
class log{
public:
    void MoveScore(string name,int dir,int dscore);
    void BonusScore(string name,double dt);
    log();
private:
    string GetTime();
};

#endif //LAB7_LOG_H
