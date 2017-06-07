#include<stdio.h>
int main ()
{
    int T,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        unsigned long int n,m,sum;
        scanf("%d %d",&n,&m);
        sum=n*m/2;
        printf("Case %d: %lu\n",i,sum);
    }
    return 0;
}
