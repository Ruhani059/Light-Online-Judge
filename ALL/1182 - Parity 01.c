#include<stdio.h>
int main()
{
    int T,i;
    unsigned long int n,mod,sum;
    scanf("%d",&T);
    for(i=1;i<=T;i=i+1)
    {
        sum=0;
        scanf("%lu",&n);
        while(n!=0)
        {
            mod=n%2;
            sum=sum+mod;
            n=n/2;
        }
        if(sum%2!=0)
        {
            printf("Case %d: odd\n",i);
        }
        else
        {
            printf("Case %d: even\n",i);
        }
    }
    return 0;
}
