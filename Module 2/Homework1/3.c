#include <stdio.h>
int main (void)
{
	int day,month,x;
	day=9 ;
	month=11;
	x=day;
	day=month;
	month=x;
	printf("%d/%d",day,month );
return 0;
}