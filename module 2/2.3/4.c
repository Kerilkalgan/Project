#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void) 

{
	float a,b,c;
	float x,y,d;
	float D;
	printf("Данная программа находит корни квадратного уравнения вида ax^2+bx+c=0\n");
	printf("Введите a = ");
	scanf("%f",&a);
	printf("Введите b = ");
	scanf("%f",&b);
	printf("Введите c = ");
	scanf("%f",&c);
	D=b*b-4*a*c;
	d=pow(D,1/2);
	x=(-b-d)/(2*a);
	y=(-b+d)/(2*a);

    if (D<0)
    {
		printf("Ошибка, дискреминант <0\n");
	}
	if (D==0)
	{
		printf("Ваше уравнение имеет единственное решение x = %.3f", -b/(2*a));
		}
	if (D>0)
	{
		printf("Ваше уравнение имеее два корня x(1) = %.3f и x(2) = %.3f",x,y);
		}
		
	return 0;
}
