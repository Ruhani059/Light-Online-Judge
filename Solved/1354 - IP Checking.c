#include<stdio.h>
#include<string.h>
#include<math.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        int a[4],b[4],i,j,sum,s,check=1;
        scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
        scanf("%d.%d.%d.%d",&b[0],&b[1],&b[2],&b[3]);
        for(i=0;i<4;i++)
        {
            sum=0;
            for(j=0;b[i]!=0;j++)
            {
                s=b[i]%10;
                if(s!=0)
                    sum+=s*pow(2,j);
                b[i]=b[i]/10;
            }
            if(a[i]!=sum)
                check++;
        }
        if(check==1)
            printf("Case %d: Yes\n",t++);
        else
            printf("Case %d: No\n",t++);
    }
    return 0;
}
