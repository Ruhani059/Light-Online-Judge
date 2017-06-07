
#include<stdio.h>
int main ()
{
    int T,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        int a,b,c,time,exit,ans;
        scanf("%d %d",&a,&b);
        if(a==0 && b==0)
        {
            ans=0;
        }
        else
        {
            exit=19;
            if(a<b)
            {
                time=b*4;
            }
            else if (a>b)
            {
                c=a-b+a;
                time=c*4;
            }
            else if (a=b)
            {
                time=b*4;
            }
            ans=time+exit;
        }
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
