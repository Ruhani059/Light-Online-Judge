#include<stdio.h>
int main ()
{
    int T,i=1;
    scanf("%d",&T);
    if(T<=25){
        while(i<=T){
            int a,b,n;
            scanf("%d",&n);
            if (n>=0 && n<=20){
                a=n/2;
                b=n-a;
                printf("%d %d\n",a,b);
                i=i+1;
            }
        }
    }
    return 0;
}
