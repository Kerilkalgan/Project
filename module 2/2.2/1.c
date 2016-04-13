#include <stdio.h>
int main(void) 
{
	int days;
	int year;
	int mounth;
    int day,d;
    printf("Введите количество дней, которые вы хотите конвертировать в года, месяцы и дни");
	scanf("%d",&days);
	year=days/365;
	d=days%365;
    mounth=d/30.4;// Использую среднее значение кол-ва дней в месяце для того, чтобы результат был точнее.
	day=days-365*year-30.4*mounth;
	printf("Years= %d;\n",year);
	printf("Mounths= %d;\n",mounth);
	printf("Days=%d.\n",day);
	return 0;
}
