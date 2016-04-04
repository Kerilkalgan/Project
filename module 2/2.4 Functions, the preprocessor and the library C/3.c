#include <stdio.h>
int f(int n) 
    {
	if (n == 1|| n == 2) return 1;
        int k =f(n - 1) + f(n - 2);
        return k;
    }
int main(void) 
{
  int n,i;
      printf("Данная программа вычисляет числа Фибоначчи\n");
      printf("Введите N = ");
      scanf("%d", &n);
      printf("\nПорядковые номера:   Числа Фибоначчи:\n");
  for (i=1;i<=n;i++)
	{
  if ( i>=10)
	{
  for ( i=10;i<=n;i++)
	{
		printf("            %d                  %d\n",i,f(i));
		}
        return 0;
		}
	    printf("            %d                   %d\n",i,f(i));
	    }
  
   return 0;
}
