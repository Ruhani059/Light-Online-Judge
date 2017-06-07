#include<stdio.h>
int main()
{
    int case_no=1,Test_Case;
    scanf("%d",&Test_Case);
    if(Test_Case<=50){
        while (case_no<=Test_Case){
            printf("Case No : %d\n",case_no);
            int x1,y1,x2,y2;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            int M,i=1;
            scanf("%d",&M);
            if(M>=1 && M<=100){
                while(i<=M){
                    int x,y;
                    scanf("%d %d",&x,&y);
                    if(x>=0 && x<= 1000 && y>=0 && y<= 1000){
                        int A,B,C,D;
                        A=y-y1;
                        B=x-x2;
                        C=y-y2;
                        D=x-x1;
                        if (A>0 && B<0 && C<0 && D>0){
                            printf("Yes\n");
                        }
                        else{
                            printf("No\n");
                        }
                        i=i+1;
                    }
                }
                case_no=case_no+1;
            }
        }
    }
    return 0;
}

