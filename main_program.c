
#include"game.h"

int main()
{
	int input=0;
	srand((unsigned int)(time(NULL)));
	do {
		staring();//����
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Load_Game();
			break;
		case 0:
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input != 0);
	printf("���˳���Ϸ��>\n");
	
	return 0;
}