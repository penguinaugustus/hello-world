//
// Created by penguin augustus on 28/5/2021.
//

#include "log.h"
#include<ctime>

string direction[]={"上","下","左","右"};


log::log(){
    ofstream outfile;
    outfile.open("./log.txt", ios::trunc );
    if(!outfile.is_open ())
        cout << "Open file failure" << endl;
}
string log::GetTime(){
        time_t now = time(0);
        tm *ltm = localtime(&now);
        string dt = ctime(&now);
        string year=dt.substr(20,4);
        string month;
        int month_=1 + ltm->tm_mon;
        month= (char)('0' + month_/10);
        month+=(char)('0' + month_%10);
        string date=dt.substr(8,2);
        string time=dt.substr(11,8);
        string gettime=year+'/'+month+'/'+date+'/'+time;
        return gettime;
}
void log::MoveScore(string name,int dir,int dscore){
    ofstream outfile;
    outfile.open("./log.txt", ios::app|ios::out);
    if(!outfile.is_open ())
        cout << "Open file failure" << endl;
    outfile<<name<<' '<<GetTime()<<' '<<direction[dir]<<' '<<dscore<<endl;
    outfile.close();
}
void log::BonusScore(string name,double dt){
    ofstream outfile;
    outfile.open("./log.txt", ios::app|ios::out);
    if(!outfile.is_open ())
        cout << "Open file failure" << endl;
    outfile<<name<<' '<<GetTime()<<' '<<dt<<' '<<'1'<<endl;
    outfile.close();
}
