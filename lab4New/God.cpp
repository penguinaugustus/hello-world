//
//  God.cpp
//  lab4New
//
//  Created by penguin augustus on 25/4/2021.
//
#include <iostream>
#include <string>
#include<vector>
using namespace std;
#include "God.hpp"
#include "Game.hpp"
#include "User.hpp"
enum direction{up_,down_,right_,left_};

God::God(int scal):game(scal){
    endnum = 2048;
    dir = 0;
    cheat = 0;
    mode = 1;
}
bool God::gameover(){
    //判断是否达到2048或64
    if(game.checkwin()){
        if(mode==1){
            cout<<user1.GetName()<<"win!"<<endl;
        }else{
            whowin();
        }
        return true;
    }
    if(game.trymove()==0){//满了
        if(mode==1){
            cout<<user1.GetName()<<"lose!"<<endl;
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
           break;
        }else{
            cout<<"非法输入！请重新输入"<<endl;
            }
        }
}
void God::getdir(User *user){
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
        }else if(a==100){
            dir = right_;
            break;
        }
            
            else if(a==99){
            if(mode==1){
                cout<<"非法输入！单人模式没有cheat功能"<<endl;
            }else{
                if(cheat){
                    cheat=false;
                    setcheat(user);
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
    int i = turn/2;
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
    int i=turn/2;
    if(user->CheckCheatstate()==1){
        cout<<cheatWords<<"同意请按"<<"sss"<<endl;// ///////////////////////////////////cichuweiwancheng
    }
}
void God::whowin(){
    if(user1.getscore()>user2.getscore()){
        cout<<user1.GetName()<<"win!"<<endl;
    }else if(user1.getscore()==user2.getscore()){
        cout<<"tie!"<<endl;
    }else{
        cout<<user2.GetName()<<"win!"<<endl;
    }
}
void God::play(){
    choosemode();
    if(mode==1){
        SinglePlay();
    }else{
        //DoublePlay();
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
        getdir(&user1);
        game.realmove(dir);
    }
}

