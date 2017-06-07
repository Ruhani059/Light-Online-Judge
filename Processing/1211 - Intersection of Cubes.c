#include <stdio.h>
int max (int a, int b)
{
    if ( a > b) return a;
    else
        return b;
}
int min (int a, int b)
{
    if ( a < b) return a;
    else
        return b;
}

int main()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        int N,a=0,b=0,c=0,d=1001,e=1001,f=1001,x1,x2,y1,y2,z1,z2;
        scanf("%d",&N);
        while(N--)
        {
            scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
            a = max(a,x1);
            b = max(b,y1);
            c = max(c,z1);
            d = min(d,x2);
            e = min(e,y2);
            f = min(f,z2);
        }
        if( a >= d || b >= e || c >= f)
            printf("Case %d: 0\n",t++);
        else
            printf("Case %d: %d\n",t++,(d-a)*(e-b)*(f-c));
    }
    return 0;
}
