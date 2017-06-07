#include<stdio.h>
#include<math.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        long long int r1,c1,r2,c2,i,j;
        scanf("%lld %lld %lld %lld",&r1,&c1,&r2,&c2);
        i=labs(r1-r2);
        j=labs(c1-c2);
        //printf("%lld %lld\n",i,j);
        if(i%2!=j%2)
            printf("Case %d: impossible\n",t++);
        else
        {
            if(i==j)
                printf("Case %d: 1\n",t++);
            else
                printf("Case %d: 2\n",t++);
        }
    }
    return 0;
}
