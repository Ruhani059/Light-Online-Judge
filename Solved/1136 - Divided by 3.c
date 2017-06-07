#include<stdio.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while(T--)
    {
        long long int A,B;
        scanf("%lld %lld",&A,&B);
        if((A-1)%3==2)
            A=((A-1)/3)*2+1;
        else
            A=((A-1)/3)*2;
        if((B%3==2))
            B=(B/3)*2+1;
        else
            B=(B/3)*2;
        printf("Case %d: %lld\n",t++,B-A);
    }
    return 0;
}
