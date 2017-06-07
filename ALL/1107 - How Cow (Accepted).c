#include<stdio.h>
int main()
{
    int j=1,T;
    scanf("%d",&T);
    if(T<=50)
    {
        while (j<=T)
        {
            printf("Case %d:\n",j);
            int x1,y1,x2,y2;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            int M,i=1;
            scanf("%d",&M);
            if(M>=1 && M<=100)
            {
                while(i<=M)
                {
                    int x,y;
                    scanf("%d %d",&x,&y);
                    int A,B,C,D;
                    A=y-y1;
                    B=x-x2;
                    C=y-y2;
                    D=x-x1;
                    if (A>0 && B<0 && C<0 && D>0)
                    {
                        printf("Yes\n");
                    }
                    else
                    {
                        printf("No\n");
                    }
                    i=i+1;
//                    }
                }
                j=j+1;
            }
        }
    }
    return 0;
}

