#include <stdio.h>
int main(void) 
{
	int days;
	int year;
	int mounth;
    int day;
    int x;
    printf("Введите количество дней, которые вы хотите конвертировать в года, месяцы и дни");
	scanf("%d",&days);
	year=days/365;
    x=days-365*year;
    mounth=x/30;
	day=days-365*year-30*mounth;
	printf("Years= %d;\n",year);
	printf("Mounths= %d;\n",mounth);
	printf("Days=%d.\n",day);
	return 0;
}