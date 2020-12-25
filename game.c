
#include "game.h"


void staring()
{
	printf("****************************************\n");
	printf("********  1.play       0.exit **********\n");
	printf("****************************************\n");
	printf("����������ѡ��>");
}

void Load_Game()
{
	char board[ROW][COL] = { 0 };//������������ row*rol
	initboard(board,ROW,COL);//��ʼ������
	displayboard(board, ROW, COL);//��ʾ���� ��������������/
	int ret = 0;
	//��ҵ��Կ�ʼ�߲�
	while(1)
	{
		playermove(board, ROW, COL);//����߲�  
		displayboard(board, ROW, COL);//��ʾ���� ������������/
		ret = iswin(board, ROW, COL);
		if (ret != 3)
			break;
		computermove(board, ROW, COL);//�����߲�
		displayboard(board, ROW, COL);//��ʾ���� ������������/
		ret = iswin(board, ROW, COL);
		if (ret != 3)
			break;
	}
	if (ret == 1)
		printf("��ϲ��һ�ʤ��\n");
	else if(ret == 2)
		printf("��ϲ���Ի�ʤ��\n");
	else
		printf("ƽ�֣�\n");
	count = 0;

}


void initboard(char board[ROW][COL], int row, int col)//��ʼ������
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			board[i][j] = ' '; //��ʼ��Ϊ�ո�  �հ�
	}
}

void displayboard(char board[ROW][COL], int row, int col)//��ʾ���� ��������������
{
	for (int i = 0; i < row; i++)
	{
		int j = 0;
		for ( j = 0; j < col; j++)//��ӡ��
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
        }
		printf("\n");
		
			for (j = 0; j < col; j++)//��ӡ��
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
	int x = 0, y = 0;//��������
	
	while (1) {
		printf("��������Ҫ�ߵ�����:>");
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
				printf("�������Ѿ���ռ�á�\n");
			
		}
		else
			printf("�������겻�Ϸ���\n");
	}
}

void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;//��������

	while (1) {
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			++count;
			printf("�����Ѿ����ˣ�����������%d %d \n", x + 1, y + 1);
			break;
		}

	}
}

int iswin(char board[ROW][COL], int row, int col)//�жϵ�ǰ��Ϸ״̬  0��ʾ�;�  1��ʾ���Ӯ  2��ʾ����Ӯ 3��ʾ����
{
	if (count < 5)
		return 3;
	else if ((count % 2) == 1)
	{
		for (int i = 0; i < col; i++)
		{
			//for(int j=0;j<row;j++)
			if ((board[0][i] == '*') && (board[i][0] == '*') &&
				(board[0][i] == board[1][i] && board[0][i] == board[2][i] || board[i][0] == board[i][1] && board[i][0] == board[i][2]))//�ж��Ƿ���ͬ�л���ͬ��
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
				(board[0][i] == board[1][i] && board[0][i] == board[2][i] || board[i][0] == board[i][1] && board[i][0] == board[i][2]))//�ж��Ƿ���ͬ�л���ͬ��
				return 2;
		}
		if ((board[1][1] == '#') &&
			((board[0][0] == '#' && board[2][2] == '#') || (board[0][2] == '#' && board[2][0] == '#')))
			return 2;

	}
	
		return 3;


	
}

