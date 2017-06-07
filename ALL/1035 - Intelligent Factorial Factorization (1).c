#include<stdio.h>
#include<math.h>
#define size 101
int main ()
{
    int i,j,k,prime[size];
    prime[1]=0;
    for  (i=2;i<size;i++)
    {
        prime[i]=1;
    }
    for(i=2;i<sqrt(size-1)+1;i++)
    {
        if(prime[i]==1)
        {
            for(j=2*i;j<size;j+=i)
            {
                prime[j]=0;
            }
        }
    }
    int count=0;
    for(i=1;i<size;i++)
    {
        if(prime[i]==1)
        {
            count++;
        }
    }
    int prime_number[count];
    for(i=0,j=1;j<size;j++)
    {
        if(prime[j]==1)
        {
            prime_number[i++]=j;
        }
    }
    int add=0;
    int number[size][count];
    for(i=0;i<size;i++)
        for(j=0;j<count;j++)
            number[i][j]=0;

    int n;
    for(i=2;i<size;i++)
    {
        n=i;
        for(j=0;j<count;j++)
        {
            for(;n%prime_number[j]==0;)
            {
                number[i][j]++;
                n=n/prime_number[j];
            }
        }
    }
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        int num;
        scanf("%d",&num);
        int new_count[count];
        for(i=0;i<count;i++)
            new_count[i]=0;
        for(i=2;i<=num;i++)
        {
            for(j=0;j<count;j++)
            {
                new_count[j]+=number[i][j];
            }
        }
        printf("Case %d: %d =",t++,num);
        int k1=0;
        for(i=0;i<count;i++)
        {
            if(new_count[i]!=0)
            {
                if(k1!=0)
                {
                    printf(" *");
                }
                printf(" %d (%d)",prime_number[i],new_count[i]);
                k1++;
            }
        }
        printf("\n");
    }
    return 0;
}
