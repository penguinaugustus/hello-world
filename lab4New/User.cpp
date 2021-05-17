//
//  User.cpp
//  lab4New
//
//  Created by penguin augustus on 25/4/2021.
//
#include <iostream>
#include "User.hpp"
using namespace std;

User::User(string name){
    username = name;
    score = 0;
    cheatstate = 0;
}
User::User(){
    username = "nobody";
    score = 0;
    cheatstate = 0;
}
void User::addscore(int add){
    score+=add;
}
void User::inputname(string name){
    username = name;
}
int User::getscore(){
    cout<<"the score of "<<username<<" is:"<<score<<endl;
    return score;
}
string User::GetName(){
    return username;
}
void User::SetCheatstate(){
    cheatstate = 1;
}
int User::CheckCheatstate(){
    return cheatstate;
}
