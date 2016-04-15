#include <stdio.h>
#include <string.h>
int main(void)
{
    char st[256];
    printf("Программа выводит символы впорядке их встречаемости в введенной вами строке\n");
    printf("вывод символов происходит от самого встречаемого к менее встречаемому\n\n");
    printf("    Введите здесь свою строку: ");
    scanf("%s",st);
    printf("    Ваши символы: ");
char a[]="qwertyuiopasdfghjklzxcvbnm`~!@#$%^&*(){}[];'\"\\/,.<>";

    int b[52]={0},i,j,dl;
    dl=strlen(st);
    for(i=0;i!=dl;i++)
    {
        for(j=0;j<52;j++)
        {
            if(a[j]==st[i])
               b[j]=b[j]+1;
                           }
                       }
           for(i=0;i<=dl;i++)
           {
           for(j=0;j<52;j++) 
           {
           if(b[j]!=0 && b[j]==i)
           {
           printf("%c ",a[j]);
           }
                    
        }
        }
    return( 0);
}
