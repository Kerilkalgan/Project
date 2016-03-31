#include <stdio.h>
int main(void)
{
	printf("Данная программа выводит количество байт,которые отводятся под каждый тип данных\n");
	printf("Тип               Размер в байтах\n");
	printf("char                     %zd\n",sizeof (char));
	printf("int                      %zd\n",sizeof (int));
	printf("short int                %zd\n",sizeof (short int));
	printf("long int                 %zd\n",sizeof (long int));
	printf("long long int            %zd\n",sizeof (long long int));
	printf("float                    %zd\n",sizeof (float));
	printf("double                   %zd\n",sizeof (double));
	printf("long double             %zd\n",sizeof (long double));
	return 0;
}
