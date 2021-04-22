#include<iostream>
#include<cmath>
using namespace std;
class SavingAccounts{
private:
	int id;
	double balance;
	double rate;
	int lastDate;
	double accumulation;
public:	
	SavingAccounts(int id,int date,double rate);//构造函数
	void accumulate(int date);
    void record();
	void deposit(int date,double amount);//存款
	void withdraw(int date,double amount);//取款
	void settle(int date);//结算利息，每年1月1日自动调用
	void show();//显示账户信息
	int getId(){return id;}
	double getRate(){return rate;}
	double getBalance(){return balance;}
    double getAcc(){return accumulation;}
};
SavingAccounts::SavingAccounts(int id,int date,double rate):id(id),balance(0),rate(rate),lastDate(date),accumulation(0){}//或许可以搞一个函数重载
void SavingAccounts::accumulate(int date){
	accumulation = accumulation + balance*(date-lastDate);
}
void SavingAccounts::deposit(int date,double amount){
	accumulate(date);
    lastDate=date;
    balance += amount;
}
void SavingAccounts::withdraw(int date,double amount){
	if(balance<amount){
		cout<<"余额不足！"<<endl;
	}else{
		accumulate(date);
        lastDate=date;
        balance -= amount;
	}
}
void SavingAccounts::settle(int date){
	accumulate(date);
	balance += accumulation*rate/365;
    lastDate=date;
    accumulation=0;//do not forget
}
void SavingAccounts::show(){
	cout<<"id:"<<id<<endl;
	cout<<"rate:"<<rate<<endl;
	cout<<"balance:"<<balance<<endl;
}


int main(){
    SavingAccounts myaccount(123,1,0.015);
    cout<<myaccount.getAcc()<<endl;
	myaccount.deposit(5,5000);
    cout<<myaccount.getAcc()<<endl;
	myaccount.deposit(45,5500);
    cout<<myaccount.getAcc()<<endl;
	myaccount.settle(90);
    cout<<myaccount.getAcc()<<endl;
	myaccount.show();
	return 0;
}

