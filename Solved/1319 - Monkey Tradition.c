#include<stdio.h>
long long int inverse (long long int a, long long int n);   //b*x=1(mod m), find x
int main ()
{
    long long int T , t = 1 ;
    scanf(" %lld ", &T) ;
    while(T--)
    {
        long long int n ;
        scanf ("%lld", &n);
        long long int m[n] , a[n] , y[n] , i , j , k , P = 1 , M[n] , x = 0 ;
        for ( i = 0 ; i < n ; i++ )
        {
            scanf ( "%lld %lld", &m[i], &a[i]) ;
            P = P * m[i] ;
        }
        for ( i = 0 ; i < n ; i++ )
        {
            M[i] = P / m[i] ;
        }
        for ( i = 0 ; i < n ; i++ )
        {
            y[i] = inverse ( M[i] , m[i] );
        }
        for ( i = 0 ; i < n ; i++ )
        {
            x  += (( a[i] % P ) * ( M[i] % P ) * ( y[i] % P )) % P;
        }
        x = x % P ;
        printf("Case %lld: %lld\n", t++ , x );
    }
    return 0;
}
long long int inverse (long long int a, long long int n)//b*x=1(mod m), find x
{
    long long int t , r , new_t , new_r , quotient , temp;
    t = 0;
    new_t = 1;
    r = n;
    new_r = a;
    while (new_r != 0)
    {
        quotient = r / new_r;
        temp = new_r;
        new_r= r - quotient * new_r;
        r = temp;
        temp = new_t;
        new_t= t - quotient * new_t;
        t = temp;
    }
//    if r > 1 return "a is not invertible"
    if ( t < 0 )
        t = t + n;
    return t;
}
