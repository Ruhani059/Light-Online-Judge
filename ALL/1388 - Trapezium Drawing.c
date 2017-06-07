#include<stdio.h>
#include<math.h>
#define pi acos(-1.0)
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        double a1,a2,b1,b2,b,c,d,c1,c2,d1,d2,a,h,s,area;
        scanf("%lf %lf %lf %lf %lf %lf %lf",&a1,&a2,&b1,&b2,&b,&c,&d);
        a = sqrt( (a1-b1)*(a1-b1) + (a2-b2)*(a2-b2) );
        s = ( d + b + c - a ) / 2.0;
        area = sqrt ( s * ( s-d ) * ( s-b ) * ( s-c+a ) );
        h = 2.0 * area / ( a-c ) ;
        c2 = a2 + h;
        d2 = b2 + h;
        c1 = b1 - sqrt ( b*b - h*h ) ;
        d1 = a1 + sqrt ( d*d - h*h ) ;
        printf("Case %d: %0.9lf %0.9lf %0.9lf %0.9lf\n",t++,c1,c2,d1,d2);
    }
}

