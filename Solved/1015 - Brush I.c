#include<stdio.h>
int main ()
{
    int T,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        int N,a,j,sum=0;
        scanf("%d",&N);
        for(j=1;j<=N;j++)
        {
            scanf("%d",&a);
            if(a>0)
            {
                sum=sum+a;
            }
        }
        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
