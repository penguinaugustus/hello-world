//
// Created by penguin augustus on 28/5/2021.
//
#include <iostream>
#include <string>
#include<vector>
#include <fstream>

using namespace std;

#include "God.h"
#include "Game.h"
#include "User.h"
#include "log.h"

enum direction{up_,down_,left_,right_};

God::God(int scal):game(scal){
    endnum = 2048;
    dir = 0;
    cheatable = true;
    mode = 1;
    movnum=0;
    dscore=0;
    WhetherLog=0;
    dt=1;
    turn=0;
}
bool God::gameover(){
    //判断是否达到2048或64
    if(game.checkwin(endnum)){
        if(mode==1){
            cout<<user1.GetName()<<" win!"<<endl;
        }else{
            whowin();
        }
        return true;
    }
    if(game.trymove()==0){//满了
        if(mode==1){
            cout<<user1.GetName()<<" lose!"<<endl;
        }else{
            whowin();
        }
        return true;
    }
    return false;
}
void God::set(){
    string endwith;
    while(1){
        cout<<"请输入'-t'以在64结束，或输入'-c'以继续"<<endl;
        cin>>endwith;
        if(endwith == "-t" ||endwith == "-c"){
            endnum = (int)endwith[1];
            if(endnum==99){
                endnum=1024;
            }else{endnum=64;}
            break;
        }else{
            cout<<"非法输入！请重新输入"<<endl;
        }
    }
}
void God::getdir(User *user_){
    char c;
    int a;
    while(1){
        cin>>c;
        a=(int)c;
        if(a == 119 ){
            dir = up_;
            break;
        }else if(a==97){
            dir = left_;
            break;
        }else if(a==122){
            dir = down_;
            break;
        }else if(a==100||a==115){
            dir = right_;
            break;
        }else if(a==99){
            if(mode==1){
                cout<<"非法输入！单人模式没有cheat功能"<<endl;
            }else{
                if(cheatable){
                    cheatable=false;
                    setcheat(user_);
                    cin>>cheatWords;
                }else{
                    cout<<"本局cheat机会已用完"<<endl;
                    cin.sync();
                }
            }
        }else{
            cout<<"非法输入！请输入w、z、a、d以控制上下左右"<<endl;
            cin.sync();
        }
    }
}
void God::setcheat(User *user){
    user->SetCheatstate();
}
void God::choosemode(){
    cout<<"请进行模式选择："<<endl;
    cout<<"1:单人模式"<<endl;
    cout<<"2:双人模式"<<endl;
    cout<<"请输入对应模式的序号："<<endl;
    while(1){
        cin>>mode;
        if(mode==1||mode==2){break;}
    }
    if(mode==1){
        string username_1;
        cout<<"请输入用户名："<<endl;
        cin>>username_1;
        user1.inputname(username_1);
    }else{
        string username_1;
        cout<<"请输入用户名1："<<endl;
        cin>>username_1;
        user1.inputname(username_1);
        string username_2;
        cout<<"请输入用户名2："<<endl;
        cin>>username_2;
        user2.inputname(username_2);
    }
}
void God::checkcheat(User *user){
    if(user->CheckCheatstate()==1){
        int i;
        char direc;
        if(game.trymove()!=1){return;}
        for(i=0;i<4;i++){
            if(game.Movable[i]==1){
                switch(i){
                    case 0: direc = 'w';break;
                    case 1: direc = 'z';break;
                    case 2: direc = 'a';break;
                    case 3: direc = 'd';break;
                }
            }
        }
        cout<<cheatWords<<",同意请按"<<direc<<endl;
    }
}
void God::whowin(){
    if(user1.getscore()>user2.getscore()){
        cout<<user1.GetName()<<" win!"<<endl;
    }else if(user1.getscore()==user2.getscore()){
        cout<<"tie!"<<endl;
    }else{
        cout<<user2.GetName()<<" win!"<<endl;
    }
}
void God::play(){
    choosemode();
    if(mode==1){
        SinglePlay();
    }else{
        DoublePlay();
    }
}
void God::SinglePlay(){
    set();
    while(1){
        game.generate();
        game.showchessboard();
        if(gameover()){
            cout<<"游戏结束！"<<endl;
            break;
        }
        while(1){
            getdir(&user1);
            if(game.GetMovable(dir)!=0){
                break;
            }
        }

        dt = bonus1.SingleBonus(&user1);
        dt = round(dt*10)/10;
        dscore=game.realmove(dir);
        user1.addscore(dscore);
        user1.getscore();
        if(WhetherLog==1&&dscore!=0){log1.MoveScore("默认用户",dir,dscore);}
        if(WhetherLog==1&&dt<1){log1.BonusScore("默认用户",dt);}
    }
}
void God::DoublePlay() {
    set();
    while (1) {
        game.generate();
        game.showchessboard();
        if (gameover()) {
            cout << "游戏结束！" << endl;
            break;
        }
        while (1) {
            if (turn % 2 == 0) {
                cout << "轮到" << user1.GetName() << "了" << endl;
                checkcheat(&user1);
                getdir(&user2);
            } else {
                cout << "轮到" << user2.GetName() << "了" << endl;
                checkcheat(&user2);
                getdir(&user1);
            }
            if (game.GetMovable(dir) != 0 && dir != 99) {
                turn++;
                break;
            }
        }
        if (turn % 2 == 1) {
            dt = bonus1.SingleBonus(&user1);
            dt = round(dt*10)/10;
            dscore=game.realmove(dir);
            user1.addscore(dscore);
            user1.getscore();
            if(WhetherLog==1&&dscore!=0){log1.MoveScore(user1.GetName(),dir,dscore);}
            if(WhetherLog==1&&dt<1){log1.BonusScore(user1.GetName(),dt);}
        } else {
            dt = bonus1.SingleBonus(&user2);
            dt = round(dt*10)/10;
            dscore=game.realmove(dir);
            user2.addscore(dscore);
            user2.getscore();
            if(WhetherLog==1&&dscore!=0){log1.MoveScore(user2.GetName(),dir,dscore);}
            if(WhetherLog==1&&dt<1){log1.BonusScore(user2.GetName(),dt);}
        }
    }
}
void God::SetLog(){
    WhetherLog=1;
}

