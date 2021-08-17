#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,c=0;
    scanf("%d%d",&a,&b);
    while(a<b)
    {
        b=b&1?b+1:b>>1;
        c++;
    }
    c+=a-b;
    printf("%d",c);
}
//minimum operation to n
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,c=0;
    scanf("%d",&a);
    while(a)
    {
        a=a&1?a-1:a>>1;
        c++;
    }
    printf("%d",c);
}
