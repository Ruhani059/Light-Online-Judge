#include<stdio.h>
#include<math.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        long long int s,i1,j,x=1,y=1;
        double i2;
        scanf("%lld",&s);
        i1=sqrt(s);
        i2=sqrt(s);
        if(i1==i2)
        {
            if(i1%2==0)
                x=i1;
            else
                y=i1;
        }

        else
        {
            i1++;
            j=i1*(i1-1)+1;
            x=y=i1;
            if(i1%2==0)
            {
                if(j>=s)
                    x=i1-(j-s);
                else
                    y=i1-(s-j);
            }
            else
            {
                if(j>=s)
                    y=i1-(j-s);
                else
                    x=i1-(s-j);
            }
        }
        printf("Case %d: %lld %lld\n",t++,x,y);
    }
    return 0;
}
