#include <stdio.h>
 
int main ( void )
{
   char c[255];
     printf("Программа.\n");
     printf("  Введите вашу сторку здесь: ");
     scanf("%s",c);
   int i=0;
   char max = c[0];
 
    while (c[i] != 0) 
    {
        if ( c[i] > max)
            max = c[i];
            i++;
    }
    printf("%s%c","Символ с наибольшим ASCII кодом в вашеей строке: ", max);
  return 0;
}





