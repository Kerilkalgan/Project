#include <stdio.h>
#include <string.h>
int main(void) 
{
	char x[254];
	printf("Введите строку у которой вы хотите узнать размер в байтах\n");
	scanf("%s",x);
	printf("%d",strlen(x));
	return 0;

}
