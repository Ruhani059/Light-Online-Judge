#include<stdio.h>
#include<string.h>
int main ()
{
    int t=1,T;
    scanf("%d",&T);
    while(T--)
    {
        char num1[201];
        long long int n2,c=0;
        int len1;
        scanf("%s %lld",num1,&n2);
        len1=strlen(num1);
        int n1[len1],div[len1],k=0,i,j;
        if(num1[0]=='-')
        {
            k=1;
            len1=len1-1;
        }
        if(n2<0)
            n2=n2*(-1);
        for (i=k,j=0;j<len1;i++,j++)
            n1[j]=num1[i]-48;
        for (i=0;i<len1;i++)
        {
            //div[i]=(n1[i]+c*10)/n2;
            c=(n1[i]+c*10)%n2;
            //printf("%d\ni=%d\t%d\t%d\n",len1,i,div[i],c);
        }
        if (c==0)
            printf("Case %d: divisible\n",t++);
        else
            printf("Case %d: not divisible\n",t++);
    }
    return 0;
}
