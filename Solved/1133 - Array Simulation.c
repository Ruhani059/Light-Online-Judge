#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        int m,n,i,j;
        scanf("%d %d",&n,&m);
        int a[n],x,y,temp;
        char z[2];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=m;i++)
        {
            scanf("%s",z);
            z[1]='\0';
            //printf("%s \tmara kha\n",z);
            if(strcmp(z,"S")==0)
            {
                scanf("%d",&x);
                //printf(" S mara kha\n");
                for(j=0;j<n;j++)
                    a[j]=a[j]+x;
            }
            else if(strcmp(z,"M")==0)
            {
                scanf("%d",&x);
                //printf(" M mara kha\n");
                for(j=0;j<n;j++)
                    a[j]=a[j]*x;
            }
            else if(strcmp(z,"D")==0)
            {
                scanf("%d",&x);
                //printf(" D mara kha\n");
                for(j=0;j<n;j++)
                    a[j]=a[j]/x;
            }
            else if(strcmp(z,"R")==0)
            {
                //printf(" R mara kha\n");
                for(j=0;j<n/2;j++)
                {
                    temp=a[j];
                    a[j]=a[n-1-j];
                    a[n-1-j]=temp;
                }
            }
            else if(strcmp(z,"P")==0)
            {
                //printf(" P mara kha\n");
                scanf("%d %d",&x,&y);
                temp=a[x];
                a[x]=a[y];
                a[y]=temp;
            }
        }
        printf("Case %d:\n",t++);
        for(i=0;i<n;i++)
        {
            printf("%d",a[i]);
            if(i!=n-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
