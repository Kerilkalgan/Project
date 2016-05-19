#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct phonebook
{
	char nameperson[30];
	char hisnumber[15];
	struct phonebook *after;
	struct phonebook *prior;
};
   struct phonebook *head; // глава списка, указатель на первый элемент списка
   struct phonebook *last; // указатель на послелующий элемент
   struct phonebook *find (char *);
   void show(void), add(void), quest(void);
   void readfile(void), savefile(void);
   void delete(struct phonebook **, struct phonebook **);
   void store(struct phonebook *i, struct phonebook **head, struct phonebook **last);
   void inputs(char *, char *, int), display(struct phonebook *);
   int st (void);
int main(void) 
{
  head = last = NULL;
  while(1) 
    {
        switch(st()) 
        {
            case 1: show();
              break;
            case 2: add();
              break;
            case 3: delete( &head, &last );
              break;
            case 4: quest();
              break;
            case 5: readfile();
              break;
            case 6: savefile();
              break;
            case 7: exit(0);           
        }
    }
    return 0;
} 
int st (void) 
{
	char q[80];
	int a;
	printf("\nТелефонная книга\n\n");
	printf(" Возможные функции:\n  1-вывод списка контактов\n  2-добавление нового контакта\n  3-удаление контакта\n  4-поиск контакта\n  5-чтение файла\n  6-сохранение в файл\n  7-выход из программы");
	do 
	  {
	    printf(" \nВведите 1...7: ");
        fgets(q, sizeof(q), stdin);
        a=atoi(q);
      }
       while(a<1 || a>7);
       return a; 
   }     
void add (void) 
{
  struct phonebook *data;
    data = (struct phonebook *)malloc( sizeof(struct phonebook));
    if(!data) 
     {
       printf("\nнет свободной памяти");
       return;
     }
		inputs("Введите имя: ", data -> nameperson,30);
		inputs("Введите его(её) номер: ", data -> hisnumber,15);
		store(data, &head, &last);

}				
void inputs(char *prompt, char *s, int count)
{
    char p[255];
    do 
    {
        printf("%s", prompt);
        fgets(p, 254, stdin);
        if(strlen(p)>count) 
        printf("\n Введена слишком длинная строка\n");
    }
        while(strlen(p)>count);
        p[strlen(p)-1]=0;
        strcpy(s, p);
}
	void delete(struct phonebook **head, struct phonebook **last) // данная функция удаляет контакты
{
    struct phonebook *data;
    char s[100];
    inputs("Введите имя которое вы хотите удалить: ", s, 30);
    data=find(s);
    if(data) 
    {
        if(*head==data) 
        {
            *head=data->after;
            if(*head) (*head)->prior=NULL;
            else *last=NULL;
        }
        else 
        {
            data->prior->after=data->after;
            if(data!=*last)
               data->after->prior=data->prior;
            else
               *last=data->prior;
        }
        free(data);
    }
}	
struct phonebook *find( char *nameperson) // фунция выполняет поиск заданного имени
{
    struct phonebook *data;
    data=head;
    while(data) 
    {
        if(!strcmp(nameperson, data->nameperson)) 
        return data;
        data=data->after;
    }
    printf("Такого имени нет в вашей телефонной книге\n");
    return NULL;
}

void store(struct phonebook *i, struct phonebook **head, struct phonebook **last) // упорядочиваю полученный список
{
    struct phonebook *x, *y;
    if(*last==NULL) 
    {
        i->after=NULL;
        i->prior=NULL;
        *last=i;
        *head=i;
        return;
    }
        y= *head;
        x=NULL;
          while(y) 
          {
            if(strcmp(y->nameperson, i->nameperson)<0) 
            {
              x=y;
              y=y->after;
            }
              else  
              {
                if(y->prior) 
                {
                 y->prior->after=i;
                 i->after=y;
                 i->prior=y->prior;
                 y->prior=i;
                 return;
                }
                 i->after=y;
                 i->prior=NULL;
                 y->prior=i;
                 *head=i;
                 return;
             }
          }
           x->after=i;
           i->after=NULL;
           i->prior=x;
           *last=i;
}
void show(void)
{
    struct phonebook *data;
    data=head;
    while(data) 
    {
        display(data);
        data=data->after;
    }
}
void display(struct phonebook *data) //вывод на экран
{
    printf("%s\n", data->nameperson);
    printf("%s\n", data->hisnumber);
  
}
void quest(void) //поиск имени в списке
{
    char nameperson[30];
    struct phonebook *data;
    printf("введите имя: \n");
    scanf("%s", nameperson);
    data=find(nameperson);
    if(!data) printf("не найдено\n");
    else display(data);
}

void savefile(void) //сохранение в файле
{
    struct phonebook *data;
    FILE *fp;
    fp=fopen("phonebook.txt", "wb");
    if(!fp) {
        printf("нельзя открыть файл\n");
        exit (1);
    }
    printf("\nсохранение в файле\n");
    data=head;
    while(data) {
        fwrite(data, sizeof(struct phonebook), 1, fp);
        data=data->after;
    }
    fclose(fp);
}
void readfile()//чтение из файла
{
    struct phonebook *data;
    FILE *fp;
    fp=fopen("phonebook.txt", "r");
    if (fgetc(fp)==EOF)
    {printf("Пусто");}
    rewind(fp);
    while(head)
     {
        data=head->after;
        free(head);
        head=data;
    }
    head=last=NULL;
    printf("\nчтение из файла\n");
    while(!feof(fp)) 
    {
        data =(struct phonebook *)malloc( sizeof(struct phonebook));
        if (!data)
         {
            printf("нет свободной памяти\n");
            return;
        }
        if(1 !=fread(data, sizeof(struct phonebook), 1, fp))
         break;
        store(data, &head, &last);
    }
    fclose(fp);
}
