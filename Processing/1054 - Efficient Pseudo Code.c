#include<stdio.h>
#include<math.h>
#define mod_m % 1000000007
int main ()
{
    long long int T , t = 1 ;
    scanf( "%lld", &T );
    while (T--)
    {
        long long int b , n , n1 , n2 , m , x , power , i , j , k , i1 , i2 ;
        scanf( "%lld %lld", &b , &n );
        n2 = n1 = n;
        for( k = 0 ; n1 != 0 ; k++)
            n1=n1/2;
        long long int a[k] ;
        for ( i = 0 ; i<k ; i++ )
        {
            a[i] = n % 2 ;
            n = n / 2 ;
        }
        x=1;
        power = b mod_m ;
        for( i = 0 ; i < k ; i++)
        {
            if( a[i] == 1)
            {
                x = ( x * power ) mod_m ;
            }
            power = ( power * power ) mod_m ;
        }
        printf("\n\n\nAns: %lld^%lld (mod 1000000007) = %lld\n\n\n",b,n2,x);

        i1 = sqrt ( x ) ;

        printf("root = %lld\n",i1);

        long long int sum = 0;

        for( i = 1 ; i <= i1 ; i++ )
        {
            if ( x % i == 0)
            {
                sum += i + x / i ;
                printf ( "%lld %lld ",i,x/i);
            }
        }
        printf("\nsum = %lld\n",sum);
        if ( i1 * i1 == x)
            sum -= i1;
        sum = sum mod_m ;
        printf("\nsum = %lld\n",sum);

    }
    return 0;
}

