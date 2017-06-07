#include<stdio.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("Case %d: %d\n",t++,a+b);
    }
    return 0;
}
