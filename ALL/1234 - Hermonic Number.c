#include<stdio.h>
#define size 100001
int main ()
{
    double sum = 0.0, ans , pseudo_harmonic_number[size];
    long long int i , j , k , T , t = 1;
    pseudo_harmonic_number[0]=0;
    for ( i = 1 ; i < size ; i++ )
    {
        k = 1000 * i;
        for ( j = 1000 * ( i - 1 ) +1 ; j <= k ; j++ )
        {
            sum += 1.0 / j ;
        }
        pseudo_harmonic_number[i] = sum ;
    }
    scanf("%lld",&T);
    while ( T-- )
    {
        long long int n,d;
        scanf("%lld", &n);
        d = n / 1000 ;
        ans = pseudo_harmonic_number[d];
        for ( i = ( d * 1000 ) +1 ; i <= n ; i++ )
        {
            ans += 1.0 / i ;
        }
        printf("Case %lld: %0.10lf\n", t++ , ans);
    }
    return 0;
}
