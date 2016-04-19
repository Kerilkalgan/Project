#include <stdio.h>

int main(void) 
{	
	int i,h=0,v=100;
	float R,G,B,H,D,max,min,S;	
	printf("Данная программа конвертирует цвет из пространства RGB в пространство HSV\n");
	printf("Для этого достаточно задать координаты цвета, это могут быть числа от 0 до 255\n");
	while (i=1,i!=50)
	{
	printf("\n\n   Введите их здесь (например, 23 56 255):");
	scanf("%f %f %f",&R,&G,&B);
	if (R>255 || G>255 || B>255)
	{
		printf("Ошибка!!!Возможно вы ввели координату(ы) > 255\n");
	    return 0;
		}
	if (R==255 && G==255 && B==255)
	{
		printf(" Hue(H): %d\n Saturation(S): %d%%\n Value(V): %d%%\n Цвет белый", h,h,v);
		return 0;
		}
	if (R==0 && G==0 && B==0)
	{		
		printf(" Hue(H): %d\n Saturation(S): %d%%\n Value(V): %d%%\n Цвет черный", h,h,h);
	    return 0;
		}	
	// Выбор max и min
	if (R>G && R>B) max = R;
	if (G>R && G>B) max = G;
	if (B>G && B>R) max = B;
	if (R<G && R<B) min = R;
	if (G<R && G<B) min = G;
	if (B<G && B<R) min = B;
    D=max-min;
    if (R==G && R==B && G==B)
    {H=0;}
    if (R>G && R>B && G>=B)
    {H=(60*(G-B)/D)+0;}
    if (R>G && R>B && G<B)
    {H=(60*(G-B)/D)+360;}
    if (G>B && G>R)
    {H=(60*(B-R)/D)+120;}
    if (B>R && B>G)
	{H=(60*(R-G)/D)+240;}
	if (G==0 && R==0 && B==0)
	{S=0;}
	else 
	{S=1-min/max;}
	printf(" Hue(H): %f\n Saturation(S): %f%%\n Value(V): %f%%\n", H, S*100,max*100/255);	
	if (H==0 || H==359)
	printf(" Оттенок красный");
	if (H>0 && H<30)
	printf(" Оттенок между красным и оранжевым");
	if (H==30)
	printf(" Оттенок оранжевый");
	if (H>30 && H<60)
	printf(" Оттенок между оранжевым и жёлтым");
	if (H==60)
	printf(" Оттенок жёлтый");
	if (H>60 && H<120)
	printf(" Оттенок между желтым и зеленым");
	if (H==120)
	printf(" Оттенок зелёный");
	if (H>120 && H<180)
	printf(" Оттенок между зелёным и голубым");
	if (H==180)
	{printf(" Оттенок голубой");}
	if (H>180 && H<240)
	{printf(" Оттенок между голубым и синим");}
	if (H==240)
	printf(" Оттенок голубой");
	if (H>240 && H<270)
	printf(" Оттенок между синим и фиолетовым");
	if (H==270)
	printf(" Оттенок фиолетовый");
	if (H>270 && H<300)
	printf(" Оттенок между фиолетовым и розовым");
	if (H==300)
	printf(" Оттенок розовый");
	if (H>300 && H<359)
	printf(" Оттенок между розовым и красным");
	}
	i++;
return 0;
}
