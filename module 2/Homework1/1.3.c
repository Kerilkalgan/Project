#include <stdio.h>
int main (void)
{
	int day,month,sA;
	day=9 ;
	month=11;
	sA=day;
	day=month;
	month=sA;
	printf("%d/%d",day,month );
return 0;
}