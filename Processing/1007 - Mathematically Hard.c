#include<stdio.h>
#define size 5000000
int prime[size];
unsigned long int toitient_factor (unsigned long int n)
{
    unsigned long int i,score,count=0;
    for(i=1;i<=n;i++)
    {
        if (n%i!=0)
        {
            count++;
        }
    }
    score=count*count;
    return score;
}
int main ()
{
    int T,i;
    unsigned long int sum,a,b,j,score,count;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lu %lu",&a,&b);
        sum=0;
        while (a<=b)
        {
            for(count=0,j=1;j<=a;j++)
            {
                if (a%j!=0)
                {
                    count++;
                    printf("%lu ",j);
                }
            }
            printf("\n");
            score=count*count;
//            score=toitient_factor (a);
            sum=sum+score;
            printf("%lu %lu %lu\n\n",a,score,sum);
            a++;
        }
        printf("Case %d: %lu\n",i,sum);
    }
    return 0;
}
