#include<stdio.h>
#include<math.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        long long int W,M=0,N=0,j;
        scanf("%lld",&W);
        if(W%2!=0)
            printf("Case %d: Impossible\n",t++);
        else
        {
            for(j=2;j<=W;j+=2)
            {
                if(W%j==0 && (W/j)%2!=0)
                {
                    N=W/j;          //odd
                    M=j;            //even
                    break;
                }
            }
            printf("Case %d: %lld %lld\n",t++,N,M);
        }
    }
    return 0;
}
