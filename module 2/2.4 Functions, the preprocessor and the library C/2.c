#include <stdio.h>
#include <math.h>
#include <assert.h>
int main (void) 
{
	float x,y;
	char a;
	printf("Калькулятор.(программа дополнена функцией assert)\n");
	printf("%s","\n   Здесь вы можете реализовать такие команды для двух чисел как: +,-,*,/,%,^.\n");
	printf("   Введите своё выражение (например 7+9,8^16,...): ");
	scanf("%f %c %f", &x, &a, &y);
  
    if ( a == '+')
    {
		printf("Ответ:%f",x+y);
	}
	if ( a == '-')
	{
		printf("Ответ:%f",x-y);
	}
    if ( a == '*')
    {
		printf("Ответ:%f",x*y);
	}
    if ( a == '/')
    
    {
	  assert ( y!=0);
	  printf("Ответ:%f",x/y);
	}
	if ( a == '%')
	{
		int a=x,b=y;
        assert (y!=0);
		printf("Ответ:%d",a%b);
		}
    if ( a == '^')
	{
		printf("Ответ: %lf", pow(x,y) );
	}
	return 0;
}
