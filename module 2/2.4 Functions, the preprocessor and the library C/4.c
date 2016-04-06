#include <stdio.h>
#define M(q,w) if (q>w) {printf("             %d\n",q);}else {printf("             %d\n",w);}
int main(void) 

{
	int n;
	printf("Введите здесь ваше число N = ");
	scanf("%d",&n);
    int i=1,x0 = 1, y0=11,a = 2, c = 4, g=5,g0=9;
    printf(" Номер    Пара чисел    Большее из них\n");
    for(i = 1; i<=n; i++) 
{ 
	printf("   %d",i);
    x0 = ((a*x0+c) % g);
    y0=((a*y0+c) % g0); 
    printf("         %d и %d", x0,y0); 
    M(x0,y0);
    a=a+5;
    c++;
    
}	
return 0;
}
