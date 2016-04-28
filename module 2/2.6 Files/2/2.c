#include <string.h>
#include <stdio.h>
#include <stdlib.h>

FILE *file1,*file2;
 
  char *encode(char *word, char *key) 
    {	
      int i,len = strlen(word);
      char* res = (char*)malloc(sizeof(char) * (len + 1));     
      for (i = 0; i < len; i++)
          res[i] = word[i] ^ key[i]; 
          res[len] = '\0';
      return res;
    }
     
int main()
  {	
	  char line[1000];
	   file1 = fopen("yourtext.txt","r");
	   file2 = fopen("results.txt","w");
	   fscanf(file1,"%s",line);
	  char * result = encode(line, "13423/1");
	   fprintf(file2,"Ваше слово зашифровано:\n\n");
	   fprintf(file2,"   %s",result);
	     printf("%s\n", result);
	   result = encode(result, "13423/1");
	   fprintf(file2,"\n\nВаше слово расшифровано:\n\n");
	   fprintf(file2,"   %s",result);
	     printf("%s\n", result); 
	    
	    fclose(file1);
	    fclose(file2);
      return 0;
  }
