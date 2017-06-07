#include<stdio.h>
#define size 21
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        char name[n][size];
        int i,j,k,a,b,c,vol[n],max=-1,min=10000001,max_value=-1,min_value=-1;
        for(i=0;i<n;i++)
        {
            scanf("%s %d %d %d",name[i],&a,&b,&c);
            vol[i]=a*b*c;
            if(vol[i] > max)
            {
                max = vol[i];
                max_value = i;
            }
            if(vol[i] < min)
            {
                min = vol[i];
                min_value = i;
            }
        }
        if(max!=min)
        {
            printf("Case %d: %s took chocolate from %s\n",t++,name[max_value],name[min_value]);
        }
        else
        {
            printf("Case %d: no thief\n",t++);
        }
    }
    return 0;
}
