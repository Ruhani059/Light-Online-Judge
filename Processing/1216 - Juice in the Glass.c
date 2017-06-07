#include<stdio.h>
#include<math.h>
#define pi acos(-1.0)
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        double r1,r2,h,p,ans;
        scanf("%lf %lf %lf %lf",&r1,&r2,&h,&p);
        r1 = r2 + (r1 - r2)*( p / h) ;
        ans = pi * p * ( r1 * r1 + r1 * r2 + r2 * r2 ) / 3 ;
        printf("Case %d: %0.9lf\n",t++,ans);
    }
}
