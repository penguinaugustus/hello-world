#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include<iostream>
#include<string>
using namespace std;

int two[4][4];
int k = 0;
char command[5];
int fin = 1;
int empty;
int mode;
int score1=0,score2=0;
int turn=0;
char username1[30];
char username2[30];
int x;

int paint();
int InitializeTwo();
int GetChar();
int Update();
int play(int a,int *score);
int Finish();
int Mode();

int main()
{
    Mode();
    InitializeTwo();
    Update();
    Update();
    //选择结束点
    printf("enter '-t' to end with 64\n");
    printf("enter '-c' to continue\n");
    scanf("%s",command);
    int y;
    y = strcmp(command,"-t");
    if(y){
        x=2048;
    }else{
        printf("the game will end when 64 is generated\n");
        x=64;
    }
    printf("Now start the game.\n");
    if(mode==2){
        printf("%s first\n",username1);
    }
    paint();
    //更新并运行
    while(1){
        GetChar();
        Finish();
        if(fin==0){
           break;
        }
        if(empty==0){
            if(mode==1){
                printf("you lose!\n");
            }else{
                if(score1>score2){
                    printf("%s win!\n",username1);
                }else if(score1<score2){
                    printf("%s win!\n",username2);
                }else{
                    printf("level the score!\n");
                }
            }
            break;
        }
    }
    return 0;
}


int InitializeTwo(){
    int i,j;
    for(i = 0;i < 4;i++){
        for(j = 0;j < 4;j++){
            two[i][j]= 0;
        }
    }
    return 0;
}

int paint(){
    int i;
    printf("\n");
    printf("+---------------+---------------+---------------+---------------+\n");
    printf("|");
    for(i = 0;i<4;i++) {
        if (two[0][i] != 0) {
            if(two[0][i]>100 && two[0][i]<1000){
                printf("%d         \t|", two[0][i]);
            }
            else if(two[0][i]>1000){
                printf("%d        \t|", two[0][i]);
            }else{
                printf("%d\t\t|", two[0][i]);
            }
        } else {
            printf("\t\t|");
        }
    }
    printf("\n");

    printf("+---------------+---------------+---------------+---------------+\n");
    printf("|");
    for(i = 0;i<4;i++) {
        if (two[1][i] != 0) {
            if(two[1][i]>100&&two[1][i]<1000){
                printf("%d         \t|", two[1][i]);
            }
            else if(two[1][i]>1000){
                printf("%d        \t|", two[1][i]);
            }else{
                printf("%d\t\t|", two[1][i]);
            }
        } else {
            printf("\t\t|");
        }
    }
    printf("\n");

    printf("+---------------+---------------+---------------+---------------+\n");
    printf("|");
    for(i = 0;i<4;i++) {
        if (two[2][i] != 0) {
            if(two[2][i]>100&&two[2][i]<1000){
                printf("%d         \t|", two[2][i]);
            }
            else if(two[2][i]>1000){
                printf("%d        \t|", two[2][i]);
            }else{
                printf("%d\t\t|", two[2][i]);
            }
        } else {
            printf("\t\t|");
        }
    }
    printf("\n");

    printf("+---------------+---------------+---------------+---------------+\n");
    printf("|");
    for(i = 0;i<4;i++) {
        if (two[3][i] != 0) {
            if(two[3][i]>100&&two[3][i]<1000){
                printf("%d         \t|", two[3][i]);
            }
            else if(two[3][i]>1000){
                printf("%d        \t|", two[3][i]);
            }else{
                printf("%d\t\t|", two[3][i]);
            }
        } else {
            printf("\t\t|");
        }
    }
    printf("\n");


    printf("+---------------+---------------+---------------+---------------+\n");
    return 0;
}

int GetChar(){
    char c1;
    int a;
    c1 = getchar();
    a = (int)c1;
    //printf("%d",a);
    if(a == 119 || a == 122 || a == 100 || a ==97){
        if(mode==1){
            play(a,&score1);
            printf("the score is %d\n",score1);
            Update();
            paint();
        }else{
            if(turn==0){
                play(a,&score1);
                printf("\n");
                printf("the score of %s is %d\n",username1,score1);
                Update();
                paint();
                printf("%s's turn\n",username2);
                turn++;
            }else{
                play(a,&score2);
                printf("\n");
                printf("the score of %s is %d\n",username2,score2);
                Update();
                paint();
                printf("%s's turn\n",username1);
                turn--;
            }
        }
    }
/*  else if(a == 113){
        break;
    }
    */
    else if(a == 10){

    }
    else{
        printf("in valid input!\n");
    }
    return 0;
}

int Update(){
    srand( (unsigned)time( NULL ) );
    while(1){
        int i,j;
        i = rand()%4;
        j = rand()%4;
        if( two[i][j] == 0){
            two[i][j] = 2;
            break;
        }
    }
    return 0;
}

int play(int a,int* score){
    int x,y;
    int i;
    int l;
    //printf("%d",a);
    switch(a){
        case 119:
        {    //向上移动
            for(y=0;y<4;y++){     //add
                for(x=0;x<4;x++){
                    if(two[x][y]==0){
                        continue;
                    }else{
                        for(i=x+1;i<4;i++){
                            if(two[i][y]!=0){
                                if(two[i][y]==two[x][y]){
                                    two[x][y]=two[x][y]*2;
                                    *score += two[x][y];
                                    two[i][y]=0;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            for(y=0;y<4;y++){   //move
                l=0;
                for(x=0;x<4;x++){
                    if(two[x][y]!=0 && x!=l){
                        two[l][y] = two[x][y];
                        two[x][y] = 0;
                        l++;
                    }else if(two[x][y]!=0 && x==l){
                        l++;
                    }
                    }
                }
            break;
        }
        case 122:
        {    //向下移动
            //printf("down");
            for(y=0;y<4;y++){     //add
                for(x=3;x>=0;x--){
                    if(two[x][y]==0){
                        continue;
                    }else{
                        for(i=x-1;i>=0;i--){
                            if(two[i][y]!=0){
                                if(two[x][y]==two[i][y]){
                                    two[x][y]=two[x][y]*2;
                                    *score += two[x][y];
                                    two[i][y]=0;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            for(y=0;y<4;y++){  //move
                l=3;
                for(x=3;x>=0;x--){
                    if(two[x][y]!=0 && x!=l){
                        two[l][y]=two[x][y];
                        two[x][y]=0;
                        l--;
                    }else if(two[x][y]!=0 && x==l){
                        l--;
                    }
                }
            }
            break;
        }
        case 100:
        {  //向右移动
        //    printf("right");
            for(x=0;x<4;x++){     //add
                for(y=3;y>=0;y--){
                    if(two[x][y]==0){
                        continue;
                    }else{
                        for(i=y-1;i>=0;i--){
                            if(two[x][i]!=0){
                                if(two[x][y]==two[x][i]){
                                    two[x][y]=two[x][y]*2;
                                    *score += two[x][y];
                                    two[x][i]=0;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            for(x=0;x<4;x++){     //move
                l=3;
                for(y=3;y>=0;y--){
                    if(two[x][y]!=0 && l!=y){
                        two[x][l]=two[x][y];
                        two[x][y]=0;
                        l--;
                    }else if(two[x][y]!=0 && y==l){
                        l--;
                    }
                }
            }
            break;
        }
        case 97:
        {     //向左移动
           // printf("left");
            for(x=0;x<4;x++) {     //add
                for (y = 0; y < 4; y++) {
                    if (two[x][y] == 0) {
                        continue;
                    } else {
                        for (i = y + 1; i < 4; i++) {
                            if (two[x][i]!=0) {
                                if(two[x][y] == two[x][i]){
                                    two[x][y] = two[x][y]*2;
                                    *score += two[x][y];
                                    two[x][i] = 0;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            for(x=0;x<4;x++){     //move
                l=0;
                for(y=0;y<4;y++){
                    if(two[x][y]!=0 && y!=l){
                        two[x][l]=two[x][y];
                        two[x][y]=0;
                        l++;
                    }else if(two[x][y]!=0 && y==l){
                        l++;
                    }
                }
            }
            break;
        }
    }
    return 0;
}

int Finish(){
    int i,j;
    empty=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(two[i][j]==x){
                if(mode==1){
                    printf("you win!\n");
                }else{
                    if(score1>score2){
                        printf("%s win!\n",username1);
                    }else if(score1<score2){
                        printf("%s win!\n",username2);
                    }else{
                        printf("level the score!\n");
                    }
                }
                fin = 0;
                return 0;
            }
            else if(two[i][j]==0){
                empty++;
            }
        }
    }

    return 0;
}

int Mode(){
    printf("---------------");
    printf("游戏开始");
    printf("---------------\n");
    printf("\n");
    printf("请进行模式选择：\n");
    printf("1:单人模式\n");
    printf("2:双人模式\n");
    printf("请输入对应模式的序号：\n");
    while(1){
    cin>>mode;
    if(mode == 1){
        break;
    }else if(mode ==2){
        cout<<"please input the name of user1:"<<endl;
        cin>>username1;
        cout<<"please input the name of user2:"<<endl;
        cin>>username2;
        break;
    }
    else{
        printf("invalid input!\n");
    }
    }
    return 0;
}


