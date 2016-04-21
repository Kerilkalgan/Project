#include <stdio.h>
#include <assert.h>
#include "5262.c"
int main() {
  int m, i, j,x,k=0;
  float d,a;
  int **mas;
  printf("Данная программа решает СЛАУ методом Крамера\n");
  printf("Введите кол-во переменных: ");
  scanf("%d", &m);
  mas = (int**)malloc(sizeof(int*) * m);
  for(i=0;i<m;i++) {
    mas[i] = (int*)malloc(sizeof(int)*m);
    for(j=0;j<m;j++) {
      printf("  mas[%d][%d]= ",i,j);
      scanf("%d", &mas[i][j]);
    }
  }
    d = Det(mas, m);
    k++;
  assert(d!=0);
  printf("D= %f", d);
  int mas1[m];  
  printf("\nВведите столбец свободных коэффициентов:\n ");
  for(i=0;i<m;i++)
  {
	  printf("  mas1[%d]= ",i);
	  scanf ("%d",&mas1[i]);}
  for(i=0;i<m;i++)
  {   
	  
	  for(j=0;j<m;j++)
	  {
		  x=mas[j][i];
		  mas[j][i] = mas1[j];
		  mas1[j]=x;
	  }
	  a = Det(mas, m);
	  k++;	
	  printf("D%d=%f\n",i,a);
	  printf("x%d=%f\n",i, a/d);	
	  for(j=0;j<m;j++)
	  {
		  x=mas1[j];
		  mas1[j] = mas[j][i];
		  mas[j][i]=x;
	  }
	}
printf("\nКол-во запусков функций: %d",k);
  return 0;
}

