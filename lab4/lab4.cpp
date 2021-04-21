#include<iostream>
#include <time.h>

using namespace std;

int onlycheat=0;
int whocheat=3;

class User{
public:
	User(string);
    User();
	int getscore(){
        return score;
    }
    void inputscore(int);
    void inputname(string);
    const char* getname(){
        return username;
    }
private:
	int score;
	const char * username;
};
User::User(string name){
    username = name.c_str();
    score = 0;
}
User::User(){
    username = "nobody";
    score = 0;
}
void User::inputscore(int input){
    score=input;
}
void User::inputname(string name){
    username = name.c_str();
}

class Game{
public:
	Game(int);//构造函数
	~Game(){}//析构函数
    void start();
	void showchessboard();//打印棋盘
	void generate();//随机生成新的2
	int up(int*);
	int down(int*);
	int right(int*);
	int left(int*);
	int move(int);//接收方向指令
	void score();//计算玩家得分并显示
    int end(int);
    char direction();//判断是否只能移往一个方向
private:
	int chess[5][5];
	int scale;//棋盘规模
};
//构造函数
Game::Game(int scale_1){
	int i,j;
    for(i = 0;i < 5;i++){
        for(j = 0;j < 5;j++){
            chess[i][j]= 0;
        }
    }
    scale = scale_1;
}
//开始界面
void Game::start(){
    cout<<"---------------"<<endl;
    cout<<"游戏开始"<<endl;
    cout<<"---------------"<<endl;
    cout<<"\n"<<endl;
    cout<<"请进行模式选择："<<endl;
    cout<<"1:单人模式"<<endl;
    cout<<"2:双人模式"<<endl;
    cout<<"请输入对应模式的序号："<<endl;
}
//打印棋盘
void Game::showchessboard(){
	int i,j;
    for(j=0;j<scale;j++){
        switch(scale){
        	case 2:  cout<<"+-------+-------+"<<endl;
        	    break;
            case 3:  cout<<"+-------+-------+-------+"<<endl;
                break;
            case 4:  cout<<"+-------+-------+-------+-------+"<<endl;
                break;
            case 5:  cout<<"+-------+-------+-------+-------+-------+"<<endl;
                break;
        }
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
        switch(scale){
        	case 2:  cout<<"+-------+-------+"<<endl;
        	    break;
            case 3:  cout<<"+-------+-------+-------+"<<endl;
                break;
            case 4:  cout<<"+-------+-------+-------+-------+"<<endl;
                break;
            case 5:  cout<<"+-------+-------+-------+-------+-------+"<<endl;
                break;
        }
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

int Game::up(int*score){
	int l,i;
	int x,y;
    int move=0;
	for(y=0;y<scale;y++){     //add
                for(x=0;x<scale;x++){
                    if(chess[x][y]==0){
                        continue;
                    }else{
                        for(i=x+1;i<scale;i++){
                            if(chess[i][y]!=0){
                                if(chess[i][y]==chess[x][y]){
                                    chess[x][y]=chess[x][y]*2;
                                    *score += chess[x][y];
                                    chess[i][y]=0;
                                    move++;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            for(y=0;y<scale;y++){   //move
                l=0;
                for(x=0;x<scale;x++){
                    if(chess[x][y]!=0 && x!=l){
                        chess[l][y] = chess[x][y];
                        chess[x][y] = 0;
                        l++;
                        move++;
                    }else if(chess[x][y]!=0 && x==l){
                        l++;
                    }
                    }
                }
    return move;
}

int Game::down(int*score){
	int l,i;
	int x,y;
    int move=0;
	for(y=0;y<scale;y++){     //add
                for(x=scale-1;x>=0;x--){
                    if(chess[x][y]==0){
                        continue;
                    }else{
                        for(i=x-1;i>=0;i--){
                            if(chess[i][y]!=0){
                                if(chess[x][y]==chess[i][y]){
                                    chess[x][y]=chess[x][y]*2;
                                    *score += chess[x][y];
                                    chess[i][y]=0;
                                    move++;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            for(y=0;y<scale;y++){  //move
                l=scale-1;
                for(x=scale-1;x>=0;x--){
                    if(chess[x][y]!=0 && x!=l){
                        chess[l][y]=chess[x][y];
                        chess[x][y]=0;
                        l--;
                        move++;
                    }else if(chess[x][y]!=0 && x==l){
                        l--;
                    }
                }
            }
    return move;
}

int Game::right(int*score){
	int l,i;
	int x,y;
    int move=0;
	for(x=0;x<scale;x++){     //add
                for(y=scale-1;y>=0;y--){
                    if(chess[x][y]==0){
                        continue;
                    }else{
                        for(i=y-1;i>=0;i--){
                            if(chess[x][i]!=0){
                                if(chess[x][y]==chess[x][i]){
                                    chess[x][y]=chess[x][y]*2;
                                    *score += chess[x][y];
                                    chess[x][i]=0;
                                    move++;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            for(x=0;x<scale;x++){     //move
                l=scale-1;
                for(y=scale-1;y>=0;y--){
                    if(chess[x][y]!=0 && l!=y){
                        chess[x][l]=chess[x][y];
                        chess[x][y]=0;
                        l--;
                        move++;
                    }else if(chess[x][y]!=0 && y==l){
                        l--;
                    }
                }
            }
    return move;
}

int Game::left(int*score){
	int l,i;
	int x,y;
    int move=0;
	for(x=0;x<scale;x++) {     //add
                for (y = 0; y < scale; y++) {
                    if (chess[x][y] == 0) {
                        continue;
                    } else {
                        for (i = y + 1; i < scale; i++) {
                            if (chess[x][i]!=0) {
                                if(chess[x][y] == chess[x][i]){
                                    chess[x][y] = chess[x][y]*2;
                                    *score += chess[x][y];
                                    chess[x][i] = 0;
                                    move++;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            for(x=0;x<scale;x++){     //move
                l=0;
                for(y=0;y<scale;y++){
                    if(chess[x][y]!=0 && y!=l){
                        chess[x][l]=chess[x][y];
                        chess[x][y]=0;
                        l++;
                        move++;
                    }else if(chess[x][y]!=0 && y==l){
                        l++;
                    }
                }
            }
    return move;
}
int Game::move(int mode){
	char c;
	int a;
	while(1){
		cin>>c;
		a=(int)c;
		if(a == 119 || a == 122 || a == 100 || a ==97){
            return a;
        }else if(a==99){
            if(mode==1){
                cout<<"非法输入！单人模式没有cheat功能"<<endl;
            }else{
                if(onlycheat==0){
                    onlycheat++;
                return a;
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
int Game::end(int end){
    //1表示结束且胜利，2表示结束但未胜利，3表示未结束
    int x,y;
    //判断是否到64或2048
    for(x=0;x<scale;x++){
        for(y=0;y<scale;y++){
            if(end == 116){
                if(chess[x][y]==64){
                    return 1;
                }
            }else{
                if(chess[x][y]==2048){
                    return 1;
                }
            }
        }
    }
    //判断是否已满
    int count=0;
    for(x=0;x<scale;x++){
        for(y=0;y<scale;y++){
                if(chess[x][y]!=0){
                    count++;
                    }
                }
            }
    if(count == scale*scale){
        //判断是否可以移动
        for(x=0;x<scale-1;x++){
            for(y=0;y<scale-1;y++){
                    if(chess[x][y]==chess[x+1][y]){
                        return 3;
                    }else if(chess[x][y]==chess[x][y+1]){
                        return 3;
                    }
                }
        }
        for(x=0;x<scale-1;x++){
            if(chess[x][scale-1]==chess[x+1][scale-1]){
                return 3;
            }
        }
        for(y=0;y<scale-1;y++){
            if(chess[scale-1][y]==chess[scale-1][y+1]){
                return 3;
            }
        }
        return 2;
    }else{
        return 3;
    }
}
char Game::direction(){
    //返回值c表示可以多方向移动
    int dir;
    int x,y;
    int l;
    int i;
    int move[4]={0,0,0,0};
    //检查是否能向上移动
    for(y=0;y<scale;y++){     //add
                for(x=0;x<scale;x++){
                    if(chess[x][y]==0){
                        continue;
                    }else{
                        for(i=x+1;i<scale;i++){
                            if(chess[i][y]!=0){
                                if(chess[i][y]==chess[x][y]){
                                    return 'c';
                                }
                                break;
                            }
                        }
                    }
                }
            }
            for(y=0;y<scale;y++){   //move
                l=0;
                for(x=0;x<scale;x++){
                    if(chess[x][y]!=0 && x!=l){
                        l++;
                        move[0]++;
                        break;
                    }else if(chess[x][y]!=0 && x==l){
                        l++;
                    }
                    }
                }
    //检查是否能向下移动
    for(y=0;y<scale;y++){     //add
                for(x=scale-1;x>=0;x--){
                    if(chess[x][y]==0){
                        continue;
                    }else{
                        for(i=x-1;i>=0;i--){
                            if(chess[i][y]!=0){
                                if(chess[x][y]==chess[i][y]){
                                    return 'c';
                                }
                                break;
                            }
                        }
                    }
                }
            }
            for(y=0;y<scale;y++){  //move
                l=scale-1;
                for(x=scale-1;x>=0;x--){
                    if(chess[x][y]!=0 && x!=l){
                        l--;
                        move[1]++;
                        break;
                    }else if(chess[x][y]!=0 && x==l){
                        l--;
                    }
                }
            }
    //检查是否能向左移动
    for(x=0;x<scale;x++) {     //add
                for (y = 0; y < scale; y++) {
                    if (chess[x][y] == 0) {
                        continue;
                    } else {
                        for (i = y + 1; i < scale; i++) {
                            if (chess[x][i]!=0) {
                                if(chess[x][y] == chess[x][i]){
                                    return 'c';
                                }
                                break;
                            }
                        }
                    }
                }
            }
            for(x=0;x<scale;x++){     //move
                l=0;
                for(y=0;y<scale;y++){
                    if(chess[x][y]!=0 && y!=l){
                        l++;
                        move[2]++;
                        break;
                    }else if(chess[x][y]!=0 && y==l){
                        l++;
                    }
                }
            }
    //检查是否能向右移动
    for(x=0;x<scale;x++){     //add
                for(y=scale-1;y>=0;y--){
                    if(chess[x][y]==0){
                        continue;
                    }else{
                        for(i=y-1;i>=0;i--){
                            if(chess[x][i]!=0){
                                if(chess[x][y]==chess[x][i]){
                                    return 'c';
                                }
                                break;
                            }
                        }
                    }
                }
            }
            for(x=0;x<scale;x++){     //move
                l=scale-1;
                for(y=scale-1;y>=0;y--){
                    if(chess[x][y]!=0 && l!=y){
                        l--;
                        move[3]++;
                        break;
                    }else if(chess[x][y]!=0 && y==l){
                        l--;
                    }
                }
            }
    int d=0;
    for(i=0;i<4;i++){
        if(move[i]!=0){
            d++;
        }
    }
    cout<<d<<endl;
    if(d==1){
            if(move[0]!=0){
                return 'w';
            }else if(move[1]!=0){
                return 'z';
            }else if(move[2]!=0){
                return 'a';
            }else{
                return 'd';
            }
    }
    return 'c';
}

int main(int argc,char **argv){
    string cheat;
    //接收命令行参数
    int scale = argv[2][0]-'0';
    if (scale>5|scale<2){
        cout<<"输入错误，支持规模为2*2、3*3、4*4和5*5，请输入-s2,-s3,-s4或-s5"<<endl;
        return 0;
    }
    //创建游戏
    Game game(scale);
    //选择模式
    game.start();
    int mode;
    User user1;
    User user2;
    while(1){
    cin>>mode;
    if(mode==1){
        //创建一位用户
        cout<<"请输入用户名："<<endl;
        string username_1;
        cin>>username_1;
        user1.inputname(username_1);
        break;
    }else if(mode==2){
        //创建两位用户
        string username_1,username_2;
        cout<<"请输入用户1姓名："<<endl;
        cin>>username_1;
        cout<<"请输入用户2姓名："<<endl;
        cin>>username_2;
        user1.inputname(username_1);
        user2.inputname(username_2);
        break;
    }else{
        cout<<"非法输入！请输入1或2！"<<endl;
    }
    }
    //设置结束条件
    int endwith_2;
    string endwith;
    while(1){
    cout<<"请输入'-t'以在64结束，或输入'-c'以继续"<<endl;
    cin>>endwith;
    if(endwith == "-t" ||endwith == "-c"){
       endwith_2 = (int)endwith[1];
       break;
    }else{
        cout<<"非法输入！请重新输入"<<endl;
    }
    }
    //开始游戏
    int dir;
    int end;
    int score1=0;
    int score2=0;
    int turn=0;
    int turn_1=0;
    int stop=0;
    while(1){
        //随机生成新的2
        if(turn==turn_1){
            game.generate();
        }else{
            turn_1--;
        }
        //打印棋盘
        game.showchessboard();
        //显示分数
        if(mode==1){
            cout<<"当前用户得分为："<<score1+score2<<endl;
        }else{
            cout<<user1.getname()<<"当前得分为："<<score1<<endl;
            cout<<user2.getname()<<"当前得分为："<<score2<<endl;
        }
        //判断游戏是否结束
        end=game.end(endwith_2);
        if(end==1||end==2){
            cout<<"游戏结束!"<<endl;
            break;
        }
        //提示轮到谁
        if(mode==2){
            if(turn%2==0){
                cout<<"轮到"<<user1.getname()<<"了"<<endl;
            }else{
                cout<<"轮到"<<user2.getname()<<"了"<<endl;
                
            }
        }
        //cheat
        if(whocheat==turn%2){
            char direction;
            direction=game.direction();
            //cout<<"direction:"<<direction<<endl;
            if(direction!='c'){
                cout<<cheat<<"同意请按"<<direction<<endl;
                }
            }
        //移动
        int move;
        if(turn%2==1){//用户2的操作
            while(1){
            dir = game.move(mode);
            switch(dir){
                case 119: move=game.up(&score2);break;
                case 122: move=game.down(&score2);break;
                case 100: move=game.right(&score2);break;
                case 97: move=game.left(&score2);break;
                case 99: cin>>cheat; whocheat=0;turn--;break;
            }
                if(move!=0){
                    break;
                }
            }
        }else{//用户1的操作
            while(1){
            dir = game.move(mode);
            switch(dir){
                case 119: move=game.up(&score1);break;
                case 122: move=game.down(&score1);break;
                case 100: move=game.right(&score1);break;
                case 97: move=game.left(&score1);break;
                case 99: cin>>cheat; whocheat=1;turn--; break;
        }
                if(move!=0){
                    break;
                }
            }
        }
        turn++;
        turn_1++;
        //cout<<"turn"<<turn<<endl;
        //cout<<cheat<<endl;
    }
    //宣布获胜者
        if(mode==1){
            if(end==1){
                cout<<"你赢了！"<<endl;
            }else{
                cout<<"你输了！"<<endl;
            }
        }else{
            if(score1>score2){
                cout<<user1.getname()<<"赢了"<<endl;
            }else if(score1<score2){
                cout<<user2.getname()<<"赢了"<<endl;
            }else{
                cout<<"平局"<<endl;
            }
        }
    return 0;
}
