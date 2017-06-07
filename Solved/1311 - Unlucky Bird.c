#include<stdio.h>
main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        double v1,v2,v3,a1,a2,d1,d2;
        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);
        d1=0.5*((v1*v1/a1)+(v2*v2/a2));
        if(v1/a1>v2/a2)
            d2=v1*v3/a1;
        else
            d2=v2*v3/a2;
        printf("Case %d: %.10lf %.10lf\n",t++,d1,d2);
    }
}
