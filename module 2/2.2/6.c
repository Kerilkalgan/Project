#include <stdio.h>
int f(int x) 
   {
	if (x == 0)return 1;
	else return x*f(x-1);
	}

int main(void)
    {
	int x;
	printf("Данная программа рассчитывает факториал натурального числа\n");
	printf("Введите число = ");
	scanf("%d",&x);
	printf("Факториал введенного числа = %d",f(x));
	return 0;
    }
