#include<stdio.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    if(T<=25){
        for(i=1;i<=T;i=i+1){
            double AB,AC,BC,ratio;
            scanf("%lf %lf %lf %lf",&AB,&AC,&BC,&ratio);
            double s,s1,ABC,BDEC,ADE,a,b,c,DE,d,AD;
            s=(AB+AC+BC)/2;
            s1=s*(s-AB)*(s-AC)*(s-BC);
            ABC=pow(s1,.5);
            BDEC=ABC/(ratio+1);
            ADE=ABC-BDEC;
            a=(2*ABC)/BC;
            b=2*ABC-BC*a;
            c=BC*2*ADE;
            d=b*b+4*a*c;
            DE=(b+pow(d,.5))/(2*a);
            AD=(AB*BC*ADE)/(DE*ABC);
            printf("Case %d: %0.9lf\n",i,AD);
        }
    }
    return 0;
}
