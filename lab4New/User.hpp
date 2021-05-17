//
//  User.hpp
//  lab4New
//
//  Created by penguin augustus on 25/4/2021.
//

#ifndef User_hpp
#define User_hpp
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

#endif /* User_hpp */
