#include<stdio.h>
#include<math.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        double R,n,r,x,y,pi;
        scanf("%lf %lf",&R,&n);
        if(n==2)
            printf("Case %d: %.10lf\n",t++,R/2);
        else
        {
            pi=acos(-1.0);
            x=pi*(n-2)/2.0/n;
            x=sin(x);
            y=2.0*pi/n;
            y=sin(y);
            x=2*x/y+1;
            r=R/x;
            printf("Case %d: %.10lf\n",t++,r);
        }
    }
    return 0;
}
