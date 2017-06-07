#include<stdio.h>
#include<string.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        int n,i,sum=0,N;
        scanf("%d",&N);
        printf("Case %d:\n",t++);
        for (i=1;i<=N;i++)
        {
            char st[10];
            scanf("%s",st);
            if(strcmp(st,"donate")==0)
            {
                scanf("%d",&n);
                sum+=n;
            }
            else if(strcmp(st,"report")==0)
                printf("%d\n",sum);
        }
    }
    return 0;
}
