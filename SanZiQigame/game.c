# include "game.h"

void InitQipan(char qipan[HANG][LIE], int hang, int lie)//进行初始化棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hang; ++i)
		for (j = 0; j < lie; ++j)
			qipan[i][j] = ' ';
}

void DaYinQipan(char qipan[HANG][LIE], int hang, int lie)//打印棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hang; ++i)
	{
		for (j = 0; j < lie; ++j)//打印单个格子
		{
			printf(" %c ", qipan[i][j]);
			if (j < lie - 1)//最后一个格子不打印 后分隔界限
				printf("|");
			if (j == lie - 1)//打印坐标号
				printf(" %d", i + 1);
		}
		printf("\n");
		if (i < hang - 1)//打印分隔线
		{
			for (j = 0; j < lie; ++j)
			{
				printf("---");
				if (j < lie - 1)//最后一行不打印 分割线
					printf("|");
			}
			printf("\n");
		}
		if (i == hang - 1)//打印坐标号
		{
			for (j = 0; j < lie; ++j)
			{
				printf("%2d ",j + 1);//必须用%2d  因为如果是两位数的棋盘  后面队列不齐
				if (j < lie - 1)
					printf(" ");
			}
			printf("\n                          玩家：*\n");
		}
	}
}
void WanjiaXQ(char qipan[HANG][LIE], int hang, int lie)//玩家下棋的输入
{
	int x = 0; 
	int y = 0;
	printf("\n玩家走\n");
	while (1)
	{
		printf("                          请输入棋子坐标：");
		scanf("%d%d", &x, &y);
		//判断xy合法性
		if (x >= 1 && x <= hang && y >= 1 && y <= lie)
		{
			if (qipan[x - 1][y - 1] == ' ')
			{
				qipan[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标不正确，请重新输入\n");
		}
	}
}
void DiannaoXQ(char qipan[HANG][LIE], int hang, int lie)//电脑下棋的生成
{
	int x = 0;
	int y = 0;
	printf("\n电脑走\n");
	while (1)
	{
		x = rand() % hang;
		y = rand() % lie;
		if (qipan[x][y] == ' ')
		{
			qipan[x][y] = '#';
			break;
		}
	}
}

int Pingju(char qipan[HANG][LIE], int hang, int lie)//平局的函数判定
{
	int i = 0;
	int j = 0;
	for(i = 0; i < hang; ++i)
		for (j = 0; j < lie; ++j)
		{
			if (qipan[i][j] == ' ')
				return 0;
		}
	return 1;
}

char ShuYing(char qipan[HANG][LIE], int hang, int lie)//输赢的判定  平局用跳转上一个函数
{
	int i = 0;
	for (i = 0; i < hang; ++i)
	{
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][0] != ' ')
		{
			return qipan[i][0];
		}
	}
	for (i = 0; i < lie; ++i)
	{
		if (qipan[0][i] == qipan[1][i] && qipan[1][i] == qipan[2][i] && qipan[0][i] != ' ')
		{
			return qipan[0][i];
		}
	}
	if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[1][1] != ' ')
		return qipan[1][1];
	if (qipan[2][0] == qipan[1][1] && qipan[1][1] == qipan[0][2] && qipan[1][1] != ' ')
		return qipan[1][1];
	//平局
	if (1 == Pingju(qipan, HANG, LIE))
	{
		return 'Q';
	}
	return 'C';
}