#include<stdio.h>
#define size 51
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        int a[size][2] , i , j , k , n , temp , check = 0;
        for(i=0;i<size;i++)
        {
            a[i][0]=-1;
            a[i][1]=0;
        }
        scanf("%d",&n);
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
        for(i=0;i<n;i++)
        {
            if(a[i][1]!=0)
            {
                j = a[i][0] + 1;
                a[i][0] = a[i][1] / j ;
                if ( a[i][1] % j != 0 )
                    a[i][0]++;
                a[i][1]=a[i][0]*j;
            }
        }
        int ans=0;
        for(i=0;i<n;i++)
            ans+=a[i][1];
        printf("Case %d: %d\n",t++,ans);

    }
    return 0;
}
