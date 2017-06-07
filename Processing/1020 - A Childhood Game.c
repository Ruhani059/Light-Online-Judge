#include<stdio.h>
#include<string.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        char name[10];
        long long int n,i,j,k,d,digit,number=0;
        scanf("%lld %s",&n,name);
        if(strcmp(name,"Alice")==0)
        {
            if(n%2!=0)
                printf("Case %d: Bob\n",t++);
            else
                printf("Case %d: Alice\n",t++);
        }
        else if(strcmp(name,"Bob")==0)
        {
            if(n%2==0)
                printf("Case %d: Bob\n",t++);
            else
                printf("Case %d: Alice\n",t++);
        }
    }
    return 0;
}
