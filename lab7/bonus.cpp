//
// Created by penguin augustus on 28/5/2021.
//
#include"bonus.h"
#include <iostream>
#include <chrono>

#include"User.h"
using namespace std;

bonus::bonus(){
    turn =0;
    start = std::chrono::high_resolution_clock::now();
    end = std::chrono::high_resolution_clock::now();
}

double bonus::Time(){
    if(turn%2==0){
        end = std::chrono::high_resolution_clock::now();
    }else{
        start = std::chrono::high_resolution_clock::now();
    }
    turn++;
    std::chrono::duration<double, std::milli> float_ms;
    if(end>start){
        float_ms= end - start;
    }else{
        float_ms= start -end;
    }
    double dt=float_ms.count()/1000.0;
    return dt;
}
double bonus::SingleBonus(User *user) {

    double dt_=Time();
   // cout<<dt_<<endl;
    if(dt_<1.0){
        cout<<"获得奖励加分1"<<endl;
        user->addscore(1);
    }
    return dt_;
}
