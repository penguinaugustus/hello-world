//
//  Game.cpp
//  lab4New
//
//  Created by penguin augustus on 25/4/2021.
//
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Game.hpp"
enum direction{up,down,right,left};

Game::Game(int scal){
    scale = scal;
    int i,j;
    for(i=0;i<scale;i++){
        for(j=0;j<scale;j++){
            chess[i][j]=0;
            ChessTry[i][j]=0;
        }
    }
}
Game::Game(){
    scale = 4;
    int i,j;
    for(i=0;i<scale;i++){
        for(j=0;j<scale;j++){
            chess[i][j]=0;
        }
    }
}
int Game::getscale(){
    return scale;
}
int Game::move(int chess_[5][5],int dir){
    vector<int[2]>NextPoint{{1,0},{-1,0},{0,-1},{0,1}};
    vector<int[2]>StartPoint{{0,0},{scale-1,scale-1}};//右上和左下
    int dx=NextPoint[dir][0];
    int dy=NextPoint[dir][1];
    int x,y;
    int x2,y2;
    int count1=0,count2=0;
    int dscore=0;
    x=StartPoint[dir/2][0];
    y=StartPoint[dir/2][1];//设定遍历初始点
    while(count1<scale){     //add
        if(chess_[x][y]!=0){
            x2=x;
            y2=y;
            while(count2<scale-count1-1){
                x2+=dx;
                y2+=dy;
                if(chess_[x2][y2]!=0&&chess_[x2][y2]==chess_[x][y]){
                    chess_[x][y]=chess_[x][y]*2;
                    chess_[x2][y2]=0;
                    dscore=chess_[x][y];
                    break;
                }
                count2++;
            }
        }
        count1++;
        x+=NextPoint[3-dir][0];
        y+=NextPoint[3-dir][0];
    }
    count1=0;
    count2=0;
    x=StartPoint[dir/2][0];
    y=StartPoint[dir/2][1];//设定遍历初始点
    while(count1<scale){
        if(chess_[x][y]==0){
            x2=x;
            y2=y;
            while(count2<scale-count1-1){
                x2+=dx;
                y2+=dy;
                if(chess_[x2][y2]!=0){
                    chess_[x][y]=chess_[x2][y2];
                    chess_[x2][y2]=0;
                    break;
                }
                count2++;
            }
        }
        count1++;
        x+=NextPoint[3-dir][0];
        y+=NextPoint[3-dir][0];
    }
    return dscore;
}

void Game::InputScale(int scal){
    scale=scal;
}
void Game::generate(){
    srand( (unsigned)time( NULL ) );
   while(1){
       int i,j;
       i = rand()%scale;
       j = rand()%scale;
       if( chess[i][j] == 0){
           chess[i][j] = 2;
           break;
       }
   }
}
void Game::showchessboard(){
    int i,j;
    for(j=0;j<scale;j++){
        printf("+");
        for(i=0;i<scale;j++){
            printf("-------+");
        }
        printf("/n");
    cout<<"|";
    for(i = 0;i<scale;i++) {
        if (chess[j][i] != 0) {
            if(chess[j][i]>100 && chess[j][i]<1000){
                cout<<chess[j][i]<<"\t|";
            }
            else if(chess[j][i]>1000){
                cout<<chess[j][i]<<"\t|";
            }else{
                cout<<chess[j][i]<<"\t|";
            }
        } else {
            cout<<"\t|";
        }
    }
    cout<<"\n";
    }
    for(j=0;j<scale;j++){
        printf("+");
        for(i=0;i<scale;j++){
            printf("-------+");
        }
        printf("/n");
    }
}
int Game::trymove(){
    int i,j;
    int k;
    int movescore = 0;
    for(k=0;k<4;k++){
    for(i=0;i<scale;i++){
        for(j=0;j<scale;j++){
           ChessTry[i][j]=chess[i][j];
        }
    }
    movescore += move(ChessTry,k);
    }
    return movescore;
}

int Game::realmove(int dir){
    int dscore;
    dscore = move(chess,dir);
    return dscore;
}

bool Game::checkwin(){
    int i,j;
    bool win = false;
    for(i=0;i<scale;i++){
        for(j=0;j<scale;j++){
            if(chess[i][j]==2048){
                win = true;
                break;
            }
        }
    }
    return win;
}
