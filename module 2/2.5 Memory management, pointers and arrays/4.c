#include <stdio.h>
 
int flag1 = 0,flag2 = 0, flag3 = 0;
 int exchange(char ckobka)
   {   switch (ckobka)
      {   case '(' : return  1;
          case '[' : return  2;
          case '{' : return  3;
          case '<' : return  4;
          case ')' : return -1;
          case ']' : return -2;
          case '}' : return -3;
          case '>' : return -4;  
          case (char)34 :                
          flag1 = ((flag1 == 0) ? 1 : 0); // если истинно 1, если ложно 0, аналогично и другие                                 
          return ((flag1 == 0) ? -5 : 5);
          case (char)39 :                 
          flag2 = ((flag2 == 0) ? 1 : 0); 
          return ((flag2 == 0) ? -6 : 6);
          case (char)96 :                 
          flag3 = ((flag3 == 0) ? 1 : 0); 
          return ((flag3 == 0) ? -7 : 7); 
          default     : return 0;
      }
   } 
int main(void)
{
    char line[255],c;
    int s[255];
    int cEx, i = 0, found = 0,j=0;
    printf("Данная программа проверяет баланс скобок и кавычек во введенной вами строке.\n");
    printf("   Введите здесь свою строку: ");
    scanf("%s",line);
    do
    {   c = line[j++];
        cEx = exchange(c);
        if(cEx>0)
         {   s[i] = cEx;
             i++;
         }
             if(cEx<0)
             {     if(i>0 && (s[i-1]+cEx)==0)
                   i--;
                   else
                {   found = 1;
                    break;
                }
            }
    }
    while (c);
        if(!i && !found)
        printf("   Баланс соблюден");
        else
        printf("   Баланс не соблюден"); 
        return 0;
}
