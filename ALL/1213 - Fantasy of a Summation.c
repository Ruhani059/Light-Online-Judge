#include<stdio.h>
long long int b_to_the_power_n_mod_m (long long int b,long long int n,long long int m)
{
    long long int n1,n2,x,power,i,j,k;
    n1=n;
    n2=n;
    for(k=0;n1!=0;k++)
        n1=n1/2;
    long long int a[k];
    for (i=0;i<k;i++)
    {
        a[i]=n2%2;
        n2=n2/2;
    }
    x=1;
    power=b%m;
    for(i=0;i<k;i++)
    {
        if(a[i]==1)
            x=(x*power)%m;
        power=(power*power)%m;
    }
    return x;
}
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while (T--)
    {
        long long int i,n,num,k,mod,res,sum=0;
        scanf("%lld %lld %lld",&n,&k,&mod);
        res = b_to_the_power_n_mod_m ( n , k-1 , mod ) ;
        res = ( (k % mod) * res ) % mod ;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&num);
            sum+=num;
        }
        res= ( ( sum % mod ) * res ) % mod;
        printf("Case %d: %lld\n",t++,res);
    }
    return 0;
}
