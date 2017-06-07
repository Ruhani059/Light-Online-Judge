#include<stdio.h>
#include<math.h>
int main()
{
    int t=1,T;
    scanf("%d",&T);
    while (T--)
    {
        double ox,oy,ax,ay,bx,by,r,x1,x2,y1,y2,x,arc_distance;
        scanf("%lf %lf %lf %lf %lf %lf",&ox,&oy,&ax,&ay,&bx,&by);
        x1=ax-ox;
        y1=ay-oy;
        x2=bx-ox;
        y2=by-oy;
        r=pow((x1*x1+y1*y1),0.5);
        if (x1*x2==0 && y1*y2==0)
        {
            arc_distance=r*acos(0.0);
        }
        else
        {
            x=atan2((x2*y1-x1*y2),(x1*x2+y1*y2));
            if(x<0)
                x=-x;
            arc_distance=r*x;
        }
        printf("Case %d: %.08lf\n",t++,arc_distance);
    }
    return 0;
}
