#include <stdio.h>
#include <string.h>
int main(void) 
{
	int x=0; //переменная для кол-ва цифр
	int y=0; //переменная для суммы цифр
	int n;
    printf("Программа выводит кол-во цифр,их сумму и среднее значение введенного числа.\n");
    printf("Введите любое целое число = ");
    scanf("%d",&n);
    while (n!=0) //начинается цикл
    {
		y+=n%10;
		n/=10;
		x++;
	}
	printf("Количество цифр = %d\n",x);
	printf("Сумма цифр = %d\n",y);
	printf("Среднее значение = %lf\n",(double)y/(double)x); // используется тип double,т.к при нахождении среднего значения результатом может быть число с плавающей запятой
    return 0;
     
}

           
