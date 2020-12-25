
#include "game.h"


void staring()
{
	printf("****************************************\n");
	printf("********  1.play       0.exit **********\n");
	printf("****************************************\n");
	printf("请输入您的选择：>");
}

void Load_Game()
{
	char board[ROW][COL] = { 0 };//创建棋盘数组 row*rol
	initboard(board,ROW,COL);//初始化棋盘
	displayboard(board, ROW, COL);//显示棋盘 并更新棋盘数据/
	int ret = 0;
	//玩家电脑开始走步
	while(1)
	{
		playermove(board, ROW, COL);//玩家走步  
		displayboard(board, ROW, COL);//显示棋盘 更新棋盘数据/
		ret = iswin(board, ROW, COL);
		if (ret != 3)
			break;
		computermove(board, ROW, COL);//电脑走步
		displayboard(board, ROW, COL);//显示棋盘 更新棋盘数据/
		ret = iswin(board, ROW, COL);
		if (ret != 3)
			break;
	}
	if (ret == 1)
		printf("恭喜玩家获胜！\n");
	else if(ret == 2)
		printf("恭喜电脑获胜！\n");
	else
		printf("平局！\n");
	count = 0;

}


void initboard(char board[ROW][COL], int row, int col)//初始化棋盘
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			board[i][j] = ' '; //初始化为空格  空白
	}
}

void displayboard(char board[ROW][COL], int row, int col)//显示棋盘 并更新棋盘数据
{
	for (int i = 0; i < row; i++)
	{
		int j = 0;
		for ( j = 0; j < col; j++)//打印行
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
        }
		printf("\n");
		
			for (j = 0; j < col; j++)//打印列
			{
				if (i < row - 1)
				{
					printf("---");

					//printf("---");
					if(j < col-1)
					printf("|");
				}

			}
		
		printf("\n");
	}
	//printf("\n");
}

void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;//接收坐标
	
	while (1) {
		printf("请输入你要走的坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				++count;
				break;
			}
			else if (board[x - 1][y - 1] == '#' || board[x - 1][y - 1] == '*')
				printf("该坐标已经被占用。\n");
			
		}
		else
			printf("输入坐标不合法。\n");
	}
}

void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;//接收坐标

	while (1) {
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			++count;
			printf("电脑已经走了，落子在坐标%d %d \n", x + 1, y + 1);
			break;
		}

	}
}

int iswin(char board[ROW][COL], int row, int col)//判断当前游戏状态  0表示和局  1表示玩家赢  2表示电脑赢 3表示继续
{
	if (count < 5)
		return 3;
	else if ((count % 2) == 1)
	{
		for (int i = 0; i < col; i++)
		{
			//for(int j=0;j<row;j++)
			if ((board[0][i] == '*') && (board[i][0] == '*') &&
				(board[0][i] == board[1][i] && board[0][i] == board[2][i] || board[i][0] == board[i][1] && board[i][0] == board[i][2]))//判断是否在同行或者同列
				return 1;
		}
		if ((board[1][1] == '*') &&
			((board[0][0] == '*' && board[2][2] == '*') || (board[0][2] == '*' && board[2][0] == '*')))
			return 1;
		if (count == 9)
			return 0;

	}
	else if ((count % 2) == 0)
	{
		for (int i = 0; i < col; i++)
		{
			//for(int j=0;j<row;j++)
			if ((board[0][i] == '#') && (board[i][0] == '#') &&
				(board[0][i] == board[1][i] && board[0][i] == board[2][i] || board[i][0] == board[i][1] && board[i][0] == board[i][2]))//判断是否在同行或者同列
				return 2;
		}
		if ((board[1][1] == '#') &&
			((board[0][0] == '#' && board[2][2] == '#') || (board[0][2] == '#' && board[2][0] == '#')))
			return 2;

	}
	
		return 3;


	
}

