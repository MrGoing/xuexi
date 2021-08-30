# include "game.h"

void InitQipan(char qipan[HANG][LIE], int hang, int lie)//���г�ʼ������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hang; ++i)
		for (j = 0; j < lie; ++j)
			qipan[i][j] = ' ';
}

void DaYinQipan(char qipan[HANG][LIE], int hang, int lie)//��ӡ����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hang; ++i)
	{
		for (j = 0; j < lie; ++j)//��ӡ��������
		{
			printf(" %c ", qipan[i][j]);
			if (j < lie - 1)//���һ�����Ӳ���ӡ ��ָ�����
				printf("|");
			if (j == lie - 1)//��ӡ�����
				printf(" %d", i + 1);
		}
		printf("\n");
		if (i < hang - 1)//��ӡ�ָ���
		{
			for (j = 0; j < lie; ++j)
			{
				printf("---");
				if (j < lie - 1)//���һ�в���ӡ �ָ���
					printf("|");
			}
			printf("\n");
		}
		if (i == hang - 1)//��ӡ�����
		{
			for (j = 0; j < lie; ++j)
			{
				printf("%2d ",j + 1);//������%2d  ��Ϊ�������λ��������  ������в���
				if (j < lie - 1)
					printf(" ");
			}
			printf("\n                          ��ң�*\n");
		}
	}
}
void WanjiaXQ(char qipan[HANG][LIE], int hang, int lie)//������������
{
	int x = 0; 
	int y = 0;
	printf("\n�����\n");
	while (1)
	{
		printf("                          �������������꣺");
		scanf("%d%d", &x, &y);
		//�ж�xy�Ϸ���
		if (x >= 1 && x <= hang && y >= 1 && y <= lie)
		{
			if (qipan[x - 1][y - 1] == ' ')
			{
				qipan[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("���겻��ȷ������������\n");
		}
	}
}
void DiannaoXQ(char qipan[HANG][LIE], int hang, int lie)//�������������
{
	int x = 0;
	int y = 0;
	printf("\n������\n");
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

int Pingju(char qipan[HANG][LIE], int hang, int lie)//ƽ�ֵĺ����ж�
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

char ShuYing(char qipan[HANG][LIE], int hang, int lie)//��Ӯ���ж�  ƽ������ת��һ������
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
	//ƽ��
	if (1 == Pingju(qipan, HANG, LIE))
	{
		return 'Q';
	}
	return 'C';
}