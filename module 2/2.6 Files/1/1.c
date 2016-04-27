#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{	
  char line[100000];
  char **words;
  char* words2;
  int amount = 1,*chastota,exist = 0,i = 0,d,j;
   FILE *file1;
   FILE *file2;  
  file1=fopen("yourtext.txt","r");
  file2=fopen("results.txt", "w");
  fscanf(file1,"%s",line);
  fprintf(file2,"Слова из вашего текста в порядке встречаемости (от самого встречаемого к менее):\n\n");
  fprintf(file2,"            слова      их встечаемость в тексте\n");
   words = (char**)malloc(amount * sizeof(char*));
   words[amount-1] = (char*)malloc(sizeof(char) * strlen(line) + 1);
   strcpy(words[amount-1], line);

   chastota = (int*)malloc(sizeof(int) * amount);
   chastota[amount-1] = 1;

while (fscanf(file1,"%s",line) !=EOF)
{	
	for(i = 0; i < amount; ++i)
	{   		
		if(strcmp(words[i],line) == 0)
		{
			chastota[i]++;
			exist = 1;
		}
	}
	if(!exist)
	{
		amount++;
		words = (char**)realloc(words, amount * sizeof(char*));
		words[amount-1] = (char*)malloc(sizeof(char) * strlen(line) + 1);
		strcpy(words[amount-1], line);

		chastota = (int*)realloc(chastota, sizeof(int) * amount);
		chastota[amount-1] = 1;
	}
	exist = 0;
}
   fclose(file1);
     for(i = 0; i < amount; ++i)
       {
	     printf("%s-%d\n", words[i], chastota[i]);
	     d=i+1;	
       }

        for (j=0; j<=d-1;j++)
          {
            for (i=0;i<=d-j-1;i++)
              {
	           if (chastota[i] > chastota[i+1])
	             {
		         int tmp = chastota[i];
		         words2 = words[i]; 
	             chastota[i]=chastota[i+1];
	             words[i]=words[i+1];
	             words[i+1]=words2;
	             chastota[i+1] = tmp;
                 }
              }
	     printf("                  %d - %s \n", chastota[i],words[i]);
	     fprintf(file2, "%1.d) %14s %17d\n",j+1,words[i],chastota[i]);
        }
    fclose(file2);
    printf("кол-во слов = %d",d);
    return 0;
}
