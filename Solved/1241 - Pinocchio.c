#include<stdio.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while (T--)
    {
        int n,i,a,b,count=0;
        scanf("%d",&n);
        a=2;
        for(i=0;i<n;i++)
        {
            b=a;
            scanf("%d",&a);
            count += ceil ( (a-b)/5.0 );
        }
        printf("Case %d: %d\n",t++,count);
    }
    return 0;
}
