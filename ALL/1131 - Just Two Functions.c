#include<stdio.h>
int main ()
{
    int k,T;
    scanf("%d",&T);
    for (k=1;k<=T;k++)
    {
        unsigned long int a1,a2,b1,b2,c1,c2,f0,f1,f2,g0,g1,g2;
        scanf("%lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu",&a1,&b1,&c1,&a2,&b2,&c2,&f0,&f1,&f2,&g0,&g1,&g2);
        unsigned long int i,M,q;
        scanf("%lu %lu",&M,&q);
        unsigned long int n[q];
        for (i=0;i<q;i++)
        {
            scanf("%lu",&n[i]);
        }
        unsigned long int a=n[i-1];
        unsigned long int f[a];
        unsigned long int g[a];
        f[0]=f0;
        f[1]=f1;
        f[2]=f2;
        g[0]=g0;
        g[1]=g1;
        g[2]=g2;
        for (i=3;i<=a;i++)
        {
            f[i]=a1*f[i-1]+b1*f[i-2]+c1*g[i-3];
            g[i]=a2*g[i-1]+b2*g[i-2]+c2*f[i-3];
        }
        printf("Case %d:\n",k);
        unsigned long int j,fn,gn;
        for (j=0;j<q;j++)
        {
            fn=f[n[j]]%M;
            gn=g[n[j]]%M;
            printf("%lu %lu\n",fn,gn);
        }
    }
    return 0;
}
