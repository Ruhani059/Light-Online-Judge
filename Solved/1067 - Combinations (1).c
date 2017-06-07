#include<stdio.h>
#define size 100001
#define mod_m % 1000003
#define modulo 1000003

long long int pseudo_factorial[size];

long long int inverse (long long int b, long long int m);    //b*x=1(mod m), find x

long long int nCr (long long int n, long long int r);

long long int factorial (long long int n);

int main ()
{
    long long int i , j , fact=1 , T , t=1 , mult;
    pseudo_factorial [0] = 1;
    for ( i = 1 ; i < size ; i++)
    {
        mult = 10 * i;
        for( j = 10 * ( i-1 ) + 1 ; j <= mult ; j++ )
        {
            fact = ( ( fact mod_m) * j ) mod_m;
        }
        pseudo_factorial [i] = fact;
    }
    scanf("%lld",&T);
    while(T--)
    {
        long long int n , r;
        scanf ("%lld %lld",&n,&r);
        printf ("Case %lld: %lld\n",t++,nCr(n,r));
//        printf("\n%lld\n",inverse(n,r));
    }
    return 0;
}
long long int factorial (long long int n)
{
    long long int i , ans , k;
    i = n / 10;
    ans = pseudo_factorial [i];
    for( k = i * 10 + 1; k <= n ; k++)
    {
        ans = ( ( ans mod_m ) * k ) mod_m;
    }
    return ans;
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
long long int nCr (long long int n, long long int r)
{
    long long int a , b , c , ans;
    a = factorial ( n );
    b = factorial ( r );
    c = factorial ( n-r );
    b = ( b * c ) mod_m;
    c = inverse ( b , modulo );
//    printf("\n%lld\n",c);
    ans = ( a * c ) mod_m;
    return ans;
}
