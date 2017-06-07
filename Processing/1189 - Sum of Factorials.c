#include<stdio.h>
#include<math.h>
#define size 20
int main ()
{
    long long int T,t=1,number,fact[size],i,index,j,k;
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
        int ans_array[size],n,posibility=1;
        for(i=0;i<size;i++)
        {
            ans_array[i]=0;
        }
        scanf("%lld",&number);
        n=number;
        j=0;

        while(n)
        {
            for(i=0;fact[i]<=n;i++)
            {

            }
            i--;
            n = n - fact[i];
            if(ans_array[i]==1)
            {
                posibility = 0;
                break;
            }
            ans_array[i]=1;
        }
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
        index=i;
        for(i=0;i<=index;i++)
        {
            for(i=0;i<=index;i++)
            {

            }
        }

        //printf("Case %lld: %\n",t++);
    }
    return 0;
}
