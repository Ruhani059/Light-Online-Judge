#include<stdio.h>
int main()
{
    int T,j=1;
    scanf("%d",&T);
    if(T<=20000){
        while(j<=T){
            int n,a1,a2,reverse=0,count=0,i;
            scanf("%d",&n);
            if(n>=0 && n<1000000000){
                a1=n;
                while(a1!=0){
                    a2=a1%10;
                    count=count+1;
                    a1=a1/10;
                }
                a1=n;
                for (i=1;i<=count;i++){
                    a2=a1%10;
                    reverse=reverse+a2*pow(10,count-i);
                    a1=a1/10;
                }
                if(reverse==n){
                    printf("Case %d: Yes\n",j);
                }
                else{
                    printf("Case %d: No\n",j);
                }
            }
        j++;
        }
    }
    return 0;
}
