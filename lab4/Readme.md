//运行环境：所有常用c++编译器（clion、g++、dev c++等）
//如何编译运行程序：在终端直接将唯一的cpp文件使用g++等编译器打开;
                                    输入.\lab4.exe -s 3 (mac上输入.\a.out -s 3) 支持规格为2、3、4、5

//游戏操作：
w-上
a-左
d-右
z-下

//输入-t将终止条件改为64
//cheat功能：两个用户u1,u2对局的情况下，如果u1在输入移动命令之前，输入“c [要求参数]”(在c和要求参数间用空格隔开，要求参 数是无空格的字符串，例如:“c 给u1发红包”)，那么在接下来u2的操作中，如果出现了只有一个方向能够移动的情况，比如只能输入'w'，系统先提示u2:" [要求参数] 同意请按’w'"(例如:“给u1发红包 同意请按'w'”)。这时候如果u2用户输入了'w'之外无 效的键，u2需要继续输入，只到输入‘w’为止。之后游戏正常进行，同时该cheat命令失效。
(注意:一盘游戏中，u1、u2无论谁发起过一次cheat功能，后面c命令就无法使用)

