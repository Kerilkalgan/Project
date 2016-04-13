#include <stdio.h> 

int main() 
{ 
    printf("Таблица ASCII\n\n");
    printf("DEC  HEX  Simbolo\n");
    printf(" 00  0      NULL\n");
	printf(" 01  0x1    SOH\n");
	printf(" 02  0x2    STX\n");
	printf(" 03  0x3    ETX \n");
	printf(" 04  0x4    EOT\n ");
	printf("05  0x5    ENQ\n");
	printf(" 06  0x6    ACK\n");
	printf(" 07  0x7    BEL\n");   
	printf(" 08  0x8    BS\n");     
	printf(" 09  0x9    HL\n");
	printf(" 10  0xa    LF\n");  
	printf(" 12  0xb    FF\n");     
	printf(" 13  0xd    CR\n");     
	printf(" 14  0xe    SO\n");
	printf(" 15  0xf    SI\n");
	printf(" 16  0x10   DLE\n"); 
	printf(" 17  0x11   DC1\n");    
	printf(" 18  0x12   DC2\n");   
	printf(" 19  0x13   DC3\n");   
	printf(" 20  0x14   DC4\n");
	printf(" 21  0x15   NAK\n");  
	printf(" 22  0x16   SYN\n");
	printf(" 23  0x17   ETB\n");  
	printf(" 24  0x18   CAN\n");   
	printf(" 25  0x19   EM\n");     
	printf(" 26  0x1a   SAB\n"); 
	printf(" 27  0x1b   ESC \n");
	printf(" 28  0x1c   FS\n");
	printf(" 29  0x1d   GS\n"); 
	printf(" 30  0x1e   RS\n");
	printf(" 31  0x1f   US\n");
	printf(" 32  0x20   espacio\n");
int i; 
for (i=33;i<=126;i++)                   // Начинаю цикл для вывода с 33 символа по 126
{
    printf("%3d  %#x    %c \n",i,i,i); 
} 
    printf("127  0x7f   DEL");
		
return 0;
}




	


