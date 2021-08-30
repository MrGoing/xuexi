//测试三子棋游戏

# include "game.h"

void caidan()//游戏的进行菜单
{
	printf("\n\n\n\n\n********************************\n");
	printf("****** 1.玩游戏    0.退出 ******\n");
	printf("********************************\n");
}

void game()//整个游戏的算法实现，利用指针跳转到game.c文件
{
	char ret = 0;//接受输赢结果
	char qipan[HANG][LIE] = { 0 };//定义棋盘数组，创建棋盘。

	InitQipan(qipan, HANG, LIE);//初始化棋盘
	DaYinQipan(qipan, HANG, LIE);//在屏幕显示（打印）棋盘。
	while (1)
	{
		WanjiaXQ(qipan, HANG, LIE);//玩家下棋
		DaYinQipan(qipan, HANG, LIE);//打印棋盘
		ret = ShuYing(qipan, HANG, LIE);//判断输赢
		if (ret != 'C')
		{
			break;
		}

		DiannaoXQ(qipan, HANG, LIE);//电脑下棋
		DaYinQipan(qipan, HANG, LIE);//打印棋盘
		ret = ShuYing(qipan, HANG, LIE);//判断输赢
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢!\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢!\n");
	}
	else if (ret == 'Q')
	{
		printf("平局!\n");
	}
}

void ceshi()//测试游戏运行
{
	int xuanze = 0;
	srand((unsigned int)time(NULL));//??????空指针？  时间函数？  强转化？
	do
	{
		caidan();
		printf("请选择：");
		scanf("%d", &xuanze);
		printf("\n\n");
		switch (xuanze)//对菜单“选择”的处理，合法性的处理。
		{
		case 1:
			game();//选择1，进入游戏函数，开始游戏
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误，请重新选择！\n");
			break;
		}
	} while (xuanze);
}

int main(void)//主函数
{

	ceshi();
	
	return 0;
}