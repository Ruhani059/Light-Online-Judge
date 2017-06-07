#include<stdio.h>
#include<math.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        double L,W,x,v;
        scanf("%lf %lf",&L,&W);
        x = ( 4*(W+L)-sqrt(16*(W+L)*(W+L)-48*W*L) ) / 24;
        v = ( W - 2 * x ) * ( L - 2 * x ) * x;
        printf("Case %d: %0.9lf\n",t++,v);
    }
    return 0;
}

