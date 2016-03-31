#include <stdio.h>

int main()
{
int a,i=0;
char x;
    printf("Данная программа выводит индикатор прогресса\n");
	printf("Введите прогресс в процентах = ");
    scanf("%d%c", &a,&x);
    if (x == '%')
    {
if (a>100)
{
	printf("%s","Ошибка! Вы ввели больше 100%, что в данной программе невозможно\n");
	return 0;
	}
     a=a/5; 
     printf("\nИндикатор вашего процесса: ");
     printf("[");
 while (i!=a)
  { 
    printf("%c",124);
    i++;
    }
 while (i!=20)
   {
    printf(" ");
    i++;
    }
    printf("]");
    }
else 
   {
	printf("\n%s","Ошибка!!! Вы ввели ваше число без знака %");
	}
return 0;
}
