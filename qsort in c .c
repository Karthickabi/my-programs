#include <stdio.h>
#include<stdlib.h>
int c(const void *a, const void *b)
{int **a1=(int **)a,**b1=(int **)b;
return a1[0][0]-b1[0][0]==0?a1[0][1]-b1[0][1]:a1[0][0]-b1[0][0];
}
int main()
{int **a=malloc(sizeof(int*)*5),n=5;
for(int i=0;i<5;i++)
a[i]=malloc(sizeof(int)*2);
for(int i=0;i<5;i++)
scanf("%d %d",&a[i][0],&a[i][1]);
qsort(a,n,sizeof(a[0]),c);
for(int i=0;i<n;i++)
printf("%d %d\n",a[i][0],a[i][1]);
}
