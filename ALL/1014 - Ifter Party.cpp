#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<set>
#include<ctime>
#define size 10001
#define total_prime 348513
int main()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        long long int ans[size],L,P,N,count1=0,count2=size-1,i,j,k,sqrtN;
        scanf("%lld %lld",&P,&L);
        N = P - L;
        if(L>=N)
            printf("Case %d: impossible\n",t++);
        else
        {
            sqrtN = sqrt (N);
            for(i=1;i<=sqrtN;i++)
            {
                if(N%i==0)
                {
                    if (i>L)
                        ans[count1++]=i;
                    if (N/i>L && N/i!=i)
                        ans[count2--]=N/i;
                }
            }
            printf("Case %d:",t++);
            for(i=0;i<count1;i++)
                printf(" %lld",ans[i]);
            for(i=count2+1;i<size;i++)
                printf(" %lld",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
