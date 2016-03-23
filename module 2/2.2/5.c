#include <stdio.h>
int main(void) 
{
	float x;
	float y;
	int s,df,m;
	float d;
	printf("Программа складывает,вычитает,умножает и деление двух заданных чисел\n");
	printf("Введите первое число = ");
	scanf("%f",&x);
	printf("Введите второе число = ");
	scanf("%f",&y);
    s=x+y;
    df=x-y;
    m=x*y;
    d=x/y;
    printf("Сумма = %d\n",s);
    printf("Разность = %d\n",df);
    printf("Произведение = %d\n",m);
    printf("Частное = %f\n",d);
    return 0;
 }

