#include<iostream>
#include<cstdio>
#include<cmath>
int main()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        long long int L,P,N,i,sqrtN;
        scanf("%lld %lld",&P,&L);
        N = P - L;
        if(L>=N)
            printf("Case %d: impossible\n",t++);
        else
        {
            sqrtN = sqrt (N);
            printf("Case %d:",t++);
            for(i=1;i<=sqrtN;i++)
                if(N%i==0 && i>L)
                    printf(" %lld",i);
            for(i=sqrtN;i>=1;i--)
                if(N%i==0 && N/i>L && N/i!=i)
                    printf(" %lld",N/i);
            printf("\n");
        }
    }
    return 0;
}
