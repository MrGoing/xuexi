//������������Ϸ

# include "game.h"

void caidan()//��Ϸ�Ľ��в˵�
{
	printf("\n\n\n\n\n********************************\n");
	printf("****** 1.����Ϸ    0.�˳� ******\n");
	printf("********************************\n");
}

void game()//������Ϸ���㷨ʵ�֣�����ָ����ת��game.c�ļ�
{
	char ret = 0;//������Ӯ���
	char qipan[HANG][LIE] = { 0 };//�����������飬�������̡�

	InitQipan(qipan, HANG, LIE);//��ʼ������
	DaYinQipan(qipan, HANG, LIE);//����Ļ��ʾ����ӡ�����̡�
	while (1)
	{
		WanjiaXQ(qipan, HANG, LIE);//�������
		DaYinQipan(qipan, HANG, LIE);//��ӡ����
		ret = ShuYing(qipan, HANG, LIE);//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}

		DiannaoXQ(qipan, HANG, LIE);//��������
		DaYinQipan(qipan, HANG, LIE);//��ӡ����
		ret = ShuYing(qipan, HANG, LIE);//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ!\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ!\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��!\n");
	}
}

void ceshi()//������Ϸ����
{
	int xuanze = 0;
	srand((unsigned int)time(NULL));//??????��ָ�룿  ʱ�亯����  ǿת����
	do
	{
		caidan();
		printf("��ѡ��");
		scanf("%d", &xuanze);
		printf("\n\n");
		switch (xuanze)//�Բ˵���ѡ�񡱵Ĵ����Ϸ��ԵĴ���
		{
		case 1:
			game();//ѡ��1��������Ϸ��������ʼ��Ϸ
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (xuanze);
}

int main(void)//������
{

	ceshi();
	
	return 0;
}