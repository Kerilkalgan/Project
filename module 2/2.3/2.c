#include <stdio.h>
char* change(char* s)
 {
    char* a, *b;
    for(a = b = s; *a; *a = *b) 
    {
        if(*b!= *(b + 1))
        a++;
        b++;
    }
    return s;
}

int  main(void) 
  {
  char s [254];
  printf("Программа удаляет стоящие подряд одинаковые символы из произвольной строки\n");
  printf("Введите здесь произвольную сторку: ");
  scanf("%s",s);
  printf("\n%s", change(s));
  return 0;
}
