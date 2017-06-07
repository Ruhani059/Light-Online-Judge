#include<stdio.h>
#include<math.h>
#define size 10001
int main ()
{
    int number[size],N=size-1,i,count=1,j,k,sqrtN=sqrt(N);
    for (i=0;i<size;i++)
    {
        number[i]=1;

    }
    for (i=3;i<=sqrtN;i+=2)
        if(number[i]==1)
            for(j=i*i;j<size;j+=i+i)
                number[j]=0;

    for (i=3; i<size ;i+=2)
        if(number[i]==1)
            count++;

    int prime_number[count];
    prime_number[0]=2;
    printf("%d\n",count);

    for (i=3,j=1;i<size;i+=2)
        if(number[i]==1)
            prime_number[j++]=i;
/*
    for (i=0;i<count;i++)
        printf("%d ",prime_number[i]);
    printf("\n");
*/
    int prime_factor[size];
    for(i=0;i<size;i++)
/*
    result[1]=1;
    for(i=999,j=2,k=1;i>=3;i-=2)
        if(number[i]==0)
            result[j++]=i;
    result[j]=2;
    prime[1]=2;
    for(i=3,k=2;i<=N;i+=2)
        if(number[i]==0)
            prime[k++]=i;
    int c[count+2],div,s;
    divisor[1]=1;
    for(j=2;j<=N;j++)
    {
        for(s=0;s<=count+1;s++)
            c[s]=1;
        div=1;
        i=j;
        for(k=1;i!=1;k++)
        {
            while(i%prime[k]==0)
            {
                c[k]++;
                i=i/prime[k];
            }
            div*=c[k];
        }
        divisor[j]=div;
    }
    int temp;
    for(i=2;i<=N;i++)
    {
        for(j=i;j<=N;j++)
        {
            if(divisor[j]<divisor[i])
            {
                temp=order[j];
                order[j]=order[i];
                order[i]=temp;
                temp=divisor[j];
                divisor[j]=divisor[i];
                divisor[i]=temp;
            }

        }
    }
    for(i=2;i<=N;i++)
    {
        for(j=i;j<=N;j++)
        {
            if(divisor[j]==divisor[i] && order[j]>order[i])
            {
                temp=order[j];
                order[j]=order[i];
                order[i]=temp;
            }

        }
    }
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        int num;
        scanf("%d",&num);
        printf("Case %d: %d\n",t++,order[num]);
    }
*/
    return 0;
}
