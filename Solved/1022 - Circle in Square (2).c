#include<stdio.h>
#include<math.h>
int main ()
{
    int T,i;
    scanf("%d",&T);
    if(T<=1000){
        for(i=1;i<=T;i++){
            double r,pi,ans;
            scanf("%lf",&r);
            if(r>0 && r<=1000){
                pi=2*acos(0.0);
                ans=r*r*(4-pi);
                printf("Case %d: %0.2lf\n",i,ans);
            }
        }
    }
    return 0;
}
