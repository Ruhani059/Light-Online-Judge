#include<stdio.h>
#include<math.h>
#define size 31
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        int check_list[size][size];
        int i,j,k,n,m,x;
        char ch;
        for (i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                check_list[i][j]=0;
            }
        }
        scanf("%d %d %d",&n,&m,&k);
        for (i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                printf("%5d ",check_list[i][j]);
            }
            printf("\n");
        }
        for (i=1;i<=n;i++)
        {
            for(j=1;j<=k;j++)
            {
                scanf(" %c %d ",&ch,&x);
                if (ch == '+')
                {
                    check_list[i][x]=1;
                }
                if (ch == '-')
                {
                    check_list[i][x]=-1;
                }
            }
        }
        for (i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                printf("%5d ",check_list[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

