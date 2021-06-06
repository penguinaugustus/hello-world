//
// Created by penguin augustus on 28/5/2021.
//
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include<map>
#include "Game.h"
enum direction{up,down,left,right};
char dir[5]= {'w', 'a', 'z', 's', '\0'};

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

Game::Game(int scal,int chess_[5][5]){
    scale = scal;
    int i,j;
    for(i=0;i<scale;i++){
        for(j=0;j<scale;j++){
            chess[i][j]=chess_[i][j];
            ChessTry[i][j]=0;
        }
    }
}

int Game::getscale(){
    return scale;
}
int Game::move(int chess_[5][5],int dir) {
    int NextPoint[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};//上下左右
    int StartPoint[2][2] = {{0,0},{scale - 1, scale - 1}};//左上和右下
    int dx = NextPoint[dir][0];
    int dy = NextPoint[dir][1];
    int x, y;
    int x2, y2;
    int x1, y1;//每一行/列的起始点
    int dscore = 0;
    WhetherMove = 0;
    x = StartPoint[dir % 2][0];
    y = StartPoint[dir % 2][1];//设定遍历初始点
    while (x < scale && x >= 0 && y < scale && y >= 0) {//add
        x1 = x;
        y1 = y;
        while (x < scale && x >= 0 && y < scale && y >= 0) {
            if (chess_[x][y] != 0) {
                x2 = x + dx;
                y2 = y + dy;
                while (x2 < scale && x2 >= 0 && y2 < scale && y2 >= 0) {
                    if (chess_[x2][y2] != 0 && chess_[x2][y2] == chess_[x][y]) {
                        chess_[x][y] = chess_[x][y] * 2;
                        chess_[x2][y2] = 0;
                        dscore += chess_[x][y];
                        WhetherMove++;
                        break;
                    }else if(chess_[x2][y2] != 0){break;}
                    x2 += dx;
                    y2 += dy;
                }
            }
            x += dx;
            y += dy;
        }
        x = x1 + NextPoint[(dir + 2) % 4][0];
        y = y1 + NextPoint[(dir + 2) % 4][1];//换行
    }
    //move
    x = StartPoint[dir % 2][0];
    y = StartPoint[dir % 2][1];//设定遍历初始点
    while (x < scale && x >= 0 && y < scale && y >= 0){
        x1 = x;
        y1 = y;
        while (x < scale && x >= 0 && y < scale && y >= 0) {
            if (chess_[x][y] == 0) {
                x2 = x + dx;
                y2 = y + dy;
                while (x2 < scale && x2 >= 0 && y2 < scale && y2 >= 0) {
                    if (chess_[x2][y2] != 0) {
                        chess_[x][y] = chess_[x2][y2];
                        chess_[x2][y2] = 0;
                        WhetherMove++;
                        break;
                    }
                    x2 += dx;
                    y2 += dy;
                }
            }
            x+=dx;
            y+=dy;
        }
        x = x1 + NextPoint[(dir + 2) % 4][0];
        y = y1 + NextPoint[(dir + 2) % 4][1];//换行
    }
    return dscore;
}
void Game::InputScale(int scal){
    scale=scal;
}
void Game::generate(){
    srand( (unsigned)time( NULL ) );
    while(1){
        RandX = rand()%scale;
        RandY = rand()%scale;
        if( chess[RandX][RandY] == 0){
            chess[RandX][RandY] = 2;
            break;
        }
    }
}
void Game::showchessboard(){
    int i,j;
    cout<<scale<<endl;
    for(j=0;j<scale;j++){
        printf("+");
        for(i=0;i<scale;i++){
            printf("-------+");
        }
        printf("\n");
        cout<<"|";
        for(i = 0;i<scale;i++) {
            if (chess[j][i] != 0) {
                cout.width(8);
                cout<<setiosflags(ios_base::left)<<setw(6)<<chess[j][i]
                    <<setiosflags(ios_base::right)<<setw(2)<<"|";
            } else {
                cout.width(8);
                cout<<"|";
            }
        }
        cout<<"\n";
    }
    printf("+");
    for(i=0;i<scale;i++){printf("-------+");}
    printf("\n");
}
int Game::trymove(){
    int i,j;
    int k;
    int movable=0;
    int lssb[4]={0,1,3,2};
    for(i=0;i<4;i++){
        Movable[i]= false;
    }
    MovableDir.erase(MovableDir.begin(),MovableDir.end());
    for(k=0;k<4;k++){
        for(i=0;i<scale;i++){
            for(j=0;j<scale;j++){
                ChessTry[i][j]=chess[i][j];
            }
        }
        move(ChessTry,k);
        Movable[k] = bool(WhetherMove);
        movable += int(Movable[k]);
    }
    for(k=0;k<4;k++){
        if(Movable[lssb[k]]!=0){
            MovableDir.append(" ");
            MovableDir+=dir[lssb[k]];
        }
    }
    return movable;
}
int Game::realmove(int dir){
    int dscore;
    dscore = move(chess,dir);
    return dscore;
}
bool Game::checkwin(int endnum){
    int i,j;
    bool win = false;
    for(i=0;i<scale;i++){
        for(j=0;j<scale;j++){
            if(chess[i][j]==endnum){
                win = true;
                break;
            }
        }
    }
    return win;
}
string Game::GetMovableDir(){
    return MovableDir;
}
void Game::CopyChess(int Chess1[5][5],int Chess2[5][5]){
    int i=0,j=0;
    for(i=0;i<scale;i++){
        for(j=0;j<scale;j++){
            Chess1[i][j]=Chess2[i][j];
        }
    }
}
bool Game::GetMovable(int dir){
    return Movable[dir];
}