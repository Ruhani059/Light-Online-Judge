#include<stdio.h>
#include<string.h>
#define size 200
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        char name1[size],name2[size],n1[size],n2[size],temp;
        scanf(" %[^\n]",name1);
        scanf(" %[^\n]",name2);
        int i, j, k, len1, len2;
        len1=strlen(name1);
        len2=strlen(name2);
        for(i=0,j=0;i<len1;i++)
        {
            if ( ( name1[i]>='A' && name1[i]<='Z' ) || ( name1[i]>='a' && name1[i]<='z' ) )
                n1[j++]=name1[i];
        }
        n1[j]='\0';
        for(i=0,j=0;i<len2;i++)
        {
            if ( ( name2[i]>='A' && name2[i]<='Z' ) || ( name2[i]>='a' && name2[i]<='z' ) )
                n2[j++]=name2[i];
        }
        n2[j]='\0';
        len1=strlen(n1);
        len2=strlen(n2);
        for(i=0;i<len1;i++)
        {
            if ( n1[i]>='A' && n1[i]<='Z' )
            {
                n1[i] = n1[i] - 'A' + 'a' ;
            }
        }
        for(i=0;i<len2;i++)
        {
            if ( n2[i]>='A' && n2[i]<='Z' )
            {
                n2[i] = n2[i] - 'A' + 'a' ;
            }
        }
        for(i=0;i<len1;i++)
        {
            for(j=i;j<len1;j++)
            {
                if(n1[i]>n1[j])
                {
                    temp=n1[i];
                    n1[i]=n1[j];
                    n1[j]=temp;
                }
            }
        }
        for(i=0;i<len2;i++)
        {
            for(j=i;j<len2;j++)
            {
                if(n2[i]>n2[j])
                {
                    temp=n2[i];
                    n2[i]=n2[j];
                    n2[j]=temp;
                }
            }
        }
        if(!strcmp(n1,n2))
            printf("Case %d: Yes\n",t++);
        else
            printf("Case %d: No\n",t++);
    }
    return 0;
}
