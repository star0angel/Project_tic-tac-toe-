
#include"game.h"

int main()
{
	int input=0;
	srand((unsigned int)(time(NULL)));
	do {
		staring();//开场
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Load_Game();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择。\n");
			break;
		}
	} while (input != 0);
	printf("已退出游戏。>\n");
	
	return 0;
}