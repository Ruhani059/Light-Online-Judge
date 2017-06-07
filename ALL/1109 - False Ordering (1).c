#include<stdio.h>
#include<math.h>
int main ()
{
    int prime[1001],order[1001],divisor[1001],result[1001],number[1001],N=1000,i,count=0,j,k,sqrtN=sqrt(N);
    for (i=1;i<=N;i++)
    {
        order[i]=i;
        number[i]=0;
        result[i]=0;
    }

    for (i=3;i<=sqrtN;i+=2)
        if(number[i]==0)
            for(j=i*i;j<=N;j+=i+i)
                number[j]=1;

    for (i=3;i<=N;i+=2)
        if(number[i]==0)
        {
            count++;
        }
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

    return 0;
}
