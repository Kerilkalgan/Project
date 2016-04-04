#include <stdio.h>
#include <string.h>

int main(void) 
{
    char x[254];
	printf("Введите строку у которой вы хотите узнать размер в байтах\n");
	gets(x);
	printf("В данной строчке %zd байт(а)", strlen(x));
	return 0;

}
