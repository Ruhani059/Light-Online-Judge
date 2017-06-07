#include<stdio.h>
#include<string.h>
#include<math.h>
#define size 65
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        long long int n,sum=0,i,j,k;
        int binary[size];
        scanf("%lld",&n);
        for(i=size-1;i>=0;i--)
        {
            binary[i]=n%2;
            n=n/2;
        }
        for(i=size-1;i>=0;i--)
        {
            if(binary[i]==1 && binary[i-1]==0)
            {
                binary[i] = 0;
                binary[i-1] = 1;
                break;
            }
        }
        for(k=0;k<size;k++)
        {
            for(j=i;j<size-1;j++)
            {
                if(binary[j]==1 && binary[j+1]==0)
                {
                    binary[j] = 0;
                    binary[j+1] = 1;
                }
            }
        }
        for(i=0;i<size;i++)
            if(binary[i]!=0)
                sum+=pow(2,size-i-1);
        printf("Case %d: %lld\n",t++,sum);
    }
    return 0;
}
