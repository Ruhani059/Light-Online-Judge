#include<stdio.h>
#include<math.h>
long long int H ( int n )
{
    long long int res = 0,i;
    for( i = 1; i <= n; i++ )
        res = res + n / i;
    return res;
}
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        long long int  n;
        scanf("%lld",&n);
        printf("Case %d: %d\n",t++,H(n));
    }
    return 0;
}

