#include <windows.h> 
#include <stdio.h>

#define I 10
#define J 10

int maze_array[I][J]={{0,0,0,0,0,0,0,0,0,0},  //初始化迷宫
					  {0,1,1,0,1,1,1,0,1,0},  //1代表可行进的路，0代表墙
					  {0,1,1,0,1,1,1,0,1,0},
					  {0,1,1,1,1,0,0,1,1,0},
					  {0,1,0,0,0,1,1,1,1,0},
					  {0,1,1,1,0,1,1,1,1,0},
					  {0,1,0,1,1,1,0,1,1,0},
					  {0,1,0,0,0,1,0,0,1,0},
					  {0,0,1,1,1,1,1,1,5,0},
					  {0,0,0,0,0,0,0,0,0,0}};  

void Maze_move(int Upmove, int Leftmove);  //走迷宫函数,参数分别为上下移动及左右移动

void Maze_print();  //打印迷宫

int x_position=1;
int y_position=1;  //定位起点为（1，1）

int main()
{
	//指定CMD显示的方式为英文，即可以正常显示ASCII码128-255中的字符；
	//如果想要显示中文，那么 SetConsoleOutputCP(936);
	SetConsoleOutputCP(437); // 使用该函数需要 #include <windows.h>

	Maze_print();  //打印初始迷宫

	Maze_move(0,0); //进入迷宫函数
	return 0;
}

void Maze_move(int Upmove, int Leftmove){
	x_position+=Upmove; 
	y_position+=Leftmove;  //行进

	if(maze_array[x_position][y_position]==5){      //判断是否到达了终点
		Maze_print();     //打印完成的迷宫
		printf("You Have Reached The Destination!\n");
		return;
	}
	maze_array[x_position][y_position]=-1;  //标记行进的路

	//以下为是否能前进的判断
	if(maze_array[x_position+1][y_position]>0)
		Maze_move(1,0);  //向下移动一格
	if(maze_array[x_position-1][y_position]>0)
		Maze_move(-1,0); //向上移动一格
	if(maze_array[x_position][y_position-1]>0)
		Maze_move(0,-1); //向左移动一格
	if(maze_array[x_position][y_position+1]>0)
		Maze_move(0,1); //向右移动一格

	//无法移动则消除标记退回上一格
	maze_array[x_position][y_position]=1;
	x_position-=Upmove;
	y_position-=Leftmove;   
}

void Maze_print(){
	int i,j;
	for(i=0;i<I;i++){
		for(j=0;j<J;j++){
			if(maze_array[i][j]==0)
				printf("%c", 254);  //判断为0则打印墙壁字符
			else if(maze_array[i][j]==1)
				printf("  ");  //判断为1或5则打印空格字符
			else if(maze_array[i][j]==-1)
				printf("%c ", 153);  //判断为-1则打印标记行走字符
			else if(maze_array[i][j]==5)
				printf("%c", 251);  //判断为2则打印到达终点字符
		}
		printf("\n"); //每行换行
	}
}
