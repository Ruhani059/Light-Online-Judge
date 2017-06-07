#include<stdio.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        long long int a,b,c,max;
        scanf("%lld %lld %lld",&a,&b,&c);
        if (b>a && b>c) {max=b;b=a;a=max;}
        if (c>a && c>b) {max=c;c=a;a=max;}
        if(a*a==b*b+c*c)
            printf("Case %d: yes\n",t++);
        else
            printf("Case %d: no\n",t++);
    }
    return 0;
}
