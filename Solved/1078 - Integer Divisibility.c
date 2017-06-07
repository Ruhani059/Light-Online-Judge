#include<stdio.h>
#include<math.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        long long int n,i,j,k,d,digit,number=0;
        scanf("%lld %lld",&n,&d);
        for(j=1;;j++)
        {
            number=((number%n)*(10%n))%n+d%n;
            if(number%n==0)
                break;
            //printf("%lld\n",number);
        }
        printf("Case %d: %lld\n",t++,j);
    }

    return 0;
}

