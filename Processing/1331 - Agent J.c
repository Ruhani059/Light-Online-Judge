#include<stdio.h>
#include<math.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        double r1,r2,r3,a,b,c,s,area,A,B,C,area1,area2,area3;
        scanf("%lf %lf %lf",&r1,&r2,&r3);
        a = r1 + r2;
        b = r2 + r3;
        c = r3 + r1;
        s = (a + b + c) / 2.0;
        area = sqrt( s * (s-a) * (s-b) * (s-c) );
        A = acos ( ( b*b+c*c-a*a ) / ( 2.0*b*c ) );
        B = acos ( ( a*a+c*c-b*b ) / ( 2.0*a*c ) );
        C = acos ( ( b*b+a*a-c*c ) / ( 2.0*b*a ) );
        area1 = r1*r1*B/2.0;
        area2 = r2*r2*C/2.0;
        area3 = r3*r3*A/2.0;
        area = area - area1 - area2 - area3;
        printf("Case %d: %.9lf\n",t++,area);
    }
    return 0;
}
