#include<stdio.h>
#include<string.h>
int main ()
{
    int T,i1;
    scanf("%d",&T);
    for (i1=1;i1<=T;i1++)
    {
        char s[1000000];
        long int i,j,k,n,x=0;
        scanf("%s",s);
        n=strlen(s);
        for(i=0;i<n;i++)
        {
            for(j=i,k=n-1;j<=k;j++,k--)
            {
                if(s[j]!=s[k])
                {
                    x=1;
                    break;
                }
                else x=0;
            }
            if(x==0) break;
        }
        n=n+i;
        printf("Case %d: %ld\n",i1,n);
    }
    return 0;
}
