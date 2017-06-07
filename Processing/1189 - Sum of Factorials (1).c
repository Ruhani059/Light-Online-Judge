#include<stdio.h>
#include<math.h>
#define size 21
int main ()
{
    long long int T,t=1,number,fact[size],i,j,k,ans_array[size],n,posibility=1;
    fact[0]=1;
    for(i=1;i<size;i++)
        fact[i]=i*fact[i-1];
/*
    for(i=0;i<size;i++)
        printf("factorial %2lld = %25lld\n",i,fact[i]);
    printf("\n");
*/
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&number);
        n=number;
        posibility = 1;
        for(i=0;i<size;i++)
            ans_array[i]=0;
        while(n)
        {
            for(i=0;fact[i]<=n;i++){}
            i--;
            if (n==2 && ans_array[2]==1)
            {
                ans_array[0]=1;
                ans_array[1]=1;
                j = 0;
                break;
            }
            n = n - fact[i];
            if(ans_array[i]==1)
            {
                posibility = 0;
                break;
            }
            ans_array[i]=1;
            j = i;
        }
/*
        for(i=0;i<size;i++)
        {
            printf("%3lld",i);
        }
        printf("\n");

        for(i=0;i<size;i++)
        {
            printf("%3lld",ans_array[i]);
        }
        printf("\n");
*/
        if (posibility == 0)
            printf("Case %lld: impossible\n",t++);
        else
        {
            printf("Case %lld: %lld!",t++,j);
            for(i=j+1;i<size;i++)
                if(ans_array[i]==1)
                    printf("+%lld!",i);
            printf("\n");
        }
    }
    return 0;
}
