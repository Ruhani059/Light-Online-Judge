#include<stdio.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k,n,temp,check=0;
        scanf("%d",&n);
        int a[n][2];
        for(i=0;i<n;i++)
            for(j=0;j<2;j++)
                a[i][j]=0;

        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            for(j=0;j<i;j++)
            {
                if(a[j][0]==temp)
                {
                    a[j][1]++;
                    check=1;
                }
            }
            if(check==0)
            {
                a[i][0]=temp;
                a[i][1]++;
            }
            check=0;
        }
        double i2,i3;
        for(i=0;i<n;i++)
        {
            if( a[i][0]!=0 )
            {
                i3= a[i][0] + 1.0;
                i2 = ceil (a[i][1] / i3) * i3;
                a[i][1] = (int)  i2 ;
            }
        }
        int ans=0;
        for(i=0;i<n;i++)
            ans+=a[i][1];
        printf("Case %d: %d\n",t++,ans);

    }
    return 0;
}
