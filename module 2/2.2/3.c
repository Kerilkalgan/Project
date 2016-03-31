#include <stdio.h>


int main(void) 
{
    int x ;
	printf("Введите строку у которой вы хотите узнать размер в байтах\n");
	scanf("%s",x);
	printf("В данной строчке %zd байт(а)", sizeof x);
	return 0;

}
