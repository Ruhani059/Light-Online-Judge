#include<stdio.h>
#include<string.h>
#include<math.h>
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        long long int a1,a2,a3,a4,sum=0,binary_len,j,k,s,i,temp;
        scanf("%lld",&a1);
        a4=a3=a2=a1;
        for(binary_len=1;a2!=0;binary_len++)
            a2=a2/2;
        int b[binary_len];
        b[0]=0;
        for(j=binary_len-1;j>0;j--)
        {
            b[j]=a3%2;
            a3=a3/2;
        }
        for(i=0;i<binary_len;i++)
            printf("%d",b[i]);
        printf("\n");
        for(j=binary_len-1;j>=0;j--)
        {
            if(b[j]==1 && b[j-1]==0)
            {
                temp=b[j];
                b[j]=b[j-1];
                b[j-1]=temp;
                break;
            }
        }
        for(s=0;s<=binary_len-j;s++)
        {
            for(k=j;k<binary_len;k++)
            {
                if(b[k]==1 && b[k+1]==0)
                {
                    temp=b[k];
                    b[k]=b[k+1];
                    b[k+1]=temp;
                }
            }
        }
        for(i=0;i<binary_len;i++)
            printf("%d",b[i]);
        printf("\n");

        for(j=0;j<binary_len;j++)
            if(b[j]!=0)
                sum+=b[j]*pow(2,binary_len-j-1);
        printf("Case %d: %lld\n",t++,sum);
    }
    return 0;
}
