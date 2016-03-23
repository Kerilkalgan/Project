#include <stdio.h>
int main(void) 
{
	float v;
	float a;
	float sinx;
	int g;
	float t;
	float x;
	float Pi;
	Pi=3.1415926539;
	g=10; //Ускорение свободного падения в м/с^2.
	printf("Программа вычисляет время полета брошеного камня под некоторым углом к горизонту\n"); 
	printf("Введите начальную скорость (в м/с) = ");
	scanf("%f",&v);
	printf("Введите угол к горизонту (в градусах) = ");
	scanf("%f",&a);
	x=a*Pi/180;
	sinx=x-x*x*x/6+x*x*x*x*x/120; //Разложение функции sin в ряд Тейлора (до трёх слагаемых).
	t=2*v*sinx/g;
	printf("Время полета = %f секунд \n",t);
    return 0;

    
}
