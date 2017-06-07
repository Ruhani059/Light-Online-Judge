#include<stdio.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while (T--)
    {
        int m , n , temp , ans;
        scanf("%d %d",&m,&n);
        if( m > n )
        {
            temp = m;
            m = n;
            n = temp;
        }
        if( m == 1 )
            ans = n;
        else if ( m == 2 )
        {
            if ( n % 4 == 1 )
                ans = ( n / 4 ) * 4 + 2 ;
            else if ( n % 4 == 0 )
                ans = ( n / 4 ) * 4 ;
            else
                ans = ( ( n / 4) +1 ) * 4 ;
        }
        else
            ans = ( m * n + 1 ) / 2 ;
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}
