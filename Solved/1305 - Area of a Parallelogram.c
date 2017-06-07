#include<stdio.h>
int main ()
{
    int T,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        double Ax,Ay,Bx,By,Cx,Cy;
        scanf("%lf %lf %lf %lf %lf %lf",&Ax,&Ay,&Bx,&By,&Cx,&Cy);
        double Dx,Dy,AB,m,c,m1,m2,hight,Area;
        Dx=Ax+Cx-Bx;
        Dy=Ay+Cy-By;
        AB=pow((Ax-Bx),2)+pow((Ay-By),2);
        AB=pow(AB,.5);
        if (Ax==Bx)
        {
            hight=Dx-Ax;
        }
        else
        {
            m=(Ay-By)/(Ax-Bx);
            c=Ay-m*Ax;
            m1=m*Dx-Dy+c;
            m2=pow((1+m*m),.5);
            hight=m1/m2;
        }
        if(hight<0){
            hight=hight*(-1);
        }
        Area=AB*hight;
        printf("Case %d: %0.0lf %0.0lf %0.0lf\n",i,Dx,Dy,Area);
    }
    return 0;
}
