#include <stdio.h>
#include <stdlib.h>

void PrintMatr (int **mas, int m) 
{
  int i,j;
  for(i=0;i<m;i++) 
  {
    for(j=0;j<m;j++)
      printf("%d ", mas[i][j]);
	  printf("\n");	
  }
}
void GetMatr(int **mas, int **p,int i,int j,int m) 
{
  int ki,kj,di,dj;
  di=0;
  for(ki=0;ki<m-1;ki++)
   { 
    if (ki==i)  di=1;
    dj=0;
    for(kj=0;kj<m-1;kj++)
     { 
      if (kj==j)  dj=1;
      p[ki][kj]=mas[ki+di][kj+dj];
    }
  }
}
int Det(int **mas, int m) 
{
  int i,j,d,k,n;
  int **p;
  p = (int**)malloc(sizeof(int*)*m);
  for(i=0;i<m;i++)
    p[i] = (int*)malloc(sizeof(int)*m);
    j=0; d=0;
    k=1; 
    n=m-1;
  if (m<1)  
  {

  return 0;
						}
  if (m==1) {
    d = mas[0][0];
    return(d);
  }
  if (m==2) {
    d=mas[0][0]*mas[1][1]-(mas[1][0]*mas[0][1]);
    return(d);
  }
  if (m>2){
    for (i=0;i<m;i++) {
      GetMatr(mas,p,i,0,m);
      printf("%d ", mas[i][j]);
      PrintMatr(p,n);
      d = d + k * mas[i][0] * Det(p,n);
      k=-k;
    }
  }
  return(d);
}
