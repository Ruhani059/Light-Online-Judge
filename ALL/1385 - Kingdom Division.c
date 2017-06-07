#include<stdio.h>
int main ()
{
    int T, t = 1;
    scanf("%d",&T);
    while ( T-- )
    {
        double a,b,c,p,q;
        scanf("%lf %lf %lf", &a, &b, &c);
        p = a * c / b;
        if ( b - p <= 0)
            printf("Case %d: -1\n", t++ );
        else
        {
            q = ( ( ( c + p ) * ( a + p ) ) / ( b - p ) );
            printf("Case %d: %0.10lf\n", t++ , p+q);
        }
    }
    return 0;
}
