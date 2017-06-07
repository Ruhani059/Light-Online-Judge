#include<stdio.h>
#include<math.h>
#define size 100001
int main ()
{
    int T,j,t=1,i;
    double temp=0,digit[size];
    digit[0]=0.2;
    //digit1[1]=0.2;
    for(i=1;i<size;i++)
    {
        for(j=10*(i-1)+1;j<=10*i;j++)
            temp+=log10(j);
        digit[i]=temp;
        //printf("%lf ",digit[i]);
    }
/*    for(i=0;i<100;i++)
        printf("log(%d)==%lf\n",10*i,digit[i]);
*/
    scanf("%d",&T);
    while(T--)
    {
        double ans;
        int n,base,k,d,int_ans;
        scanf("%d %d",&n,&base);
        d=n/10;
        //printf("%d\n",n/10);
        ans=digit[d];
        //printf("\nlog(%d)==%lf\n",d,digit[d]);
        for(k=d*10+1;k<=n;k++)
            ans+=log10(k);
        ans=ans/log10(base);
        //printf("%lf\n",ans);
        ans=ceil(ans);
        int_ans=(int)ans;
        //printf("%lf\n",ans);
        printf("Case %d: %d\n",t++,int_ans);
    }
    return 0;
}
