#include<stdio.h>
#define size 21
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        int n,P,Q,i,j,temp,sum=0;
        scanf("%d %d %d",&n,&P,&Q);
        int egg[n];
        for(i=0;i<n;i++)
            scanf("%d",&egg[i]);
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                if(egg[j]<egg[i])
                {
                    temp=egg[i];
                    egg[i]=egg[j];
                    egg[j]=temp;
                }
            }
        }
//        for(i=0;i<n;i++)
//            printf("%d ",egg[i]);
        for(i=0;i<n;i++)
        {
            sum+=egg[i];
            if(sum>Q || i>P-1)
                break;
        }
        printf("Case %d: %d\n",t++,i);
    }
    return 0;
}
