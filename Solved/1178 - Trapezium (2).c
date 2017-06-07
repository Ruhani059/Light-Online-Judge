#include<stdio.h>
int main()
{
    int T,i=1;
    scanf("%d",&T);
    if(T<=20){
        while(i<=T){
            double a,b,c,d,e;
            scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
            if(a>=0 && a<=200 && b>=0 && b<=200 && c>=0 && c<=200 && d>=0 && d<=200){
                if (c>a){
                    e=a;
                    a=c;
                    c=e;
                }
                double a1,b1,c1,d1,b2,d2,x,h,area;
                b2=b*b;
                d2=d*d;
                a1=(a-c)*(a-c)-(d2-b2);
                b1=4*b2*(d2-b2)+4*b2*a1;
                c1=a1*a1/b1;
                d1=1-c1;
                x=pow(d1,.5);
                h=b*x;
                area=(a+c)*h/2;
                printf("Case %d: %lf\n",i,area);
                i=i+1;
            }
        }
    }
    return 0;
}
