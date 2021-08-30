# define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define HANG 3
# define  LIE 3

void InitQipan(char qipan[HANG][LIE], int hang, int lie);
void DaYinQipan(char qipan[HANG][LIE], int hang, int lie);
void WanjiaXQ(char qipan[HANG][LIE], int hang, int lie);
void DiannaoXQ(char qipan[HANG][LIE], int hang, int lie);
char ShuYing(char qipan[HANG][LIE], int hang, int lie);