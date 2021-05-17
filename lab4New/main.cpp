#include <iostream>
#include <string>
#include<vector>
#include "Game.hpp"
#include "User.hpp"
#include "God.hpp"
enum direction{up,down,right,left};

using namespace std;

int main(int argc,char ** argv) {
    int scale = argv[2][0]-'0';
    if (scale>5|scale<2){
        cout<<"输入错误，支持规模为2*2、3*3、4*4和5*5，请输入-s2,-s3,-s4或-s5"<<endl;
        return 0;
    }
    God god(scale);
    god.play();
    return 0;
}
