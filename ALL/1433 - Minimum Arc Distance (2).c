#include<stdio.h>
double power (double x,double y)
{
    double i;
    double power;
    power=1;
    for (i=1;i<=y;i=i+1){
        power=power*x;
    }
    return power;
}
double factorial (double n)
{
    double i=1,factorial_ans=1;
    while (i<=n){
        factorial_ans=factorial_ans*i;
        i=i+1;
    }
    return factorial_ans;
}
double sine_inverse (double x)
{
    double i=1,j=1,a,a1=1,b,c=0,sine_inverse_ans;
    while(i<=150){
        a=2*i+1;
        for (j=1,a1=1;j<=i;j=j+1){
            a1=a1*(2*j-1);
        }
        b=(a1/a)*(1/(power(2,i)*factorial(i)));
        c=c+b*power(x,a);
        i=i+1;
    }
    sine_inverse_ans=x+c;
    return sine_inverse_ans;
}
int main()
{
    int i=1,T;
    scanf("%d",&T);
    if(T<=100){
        while (i<=T){
            double o1,o2,a1,a2,b1,b2,m;
            scanf("%lf %lf %lf %lf %lf %lf",&o1,&o2,&a1,&a2,&b1,&b2);
            //if (o1>=1 &&o1<=10000 && o2>=1 && o2<=10000 && a1>=1 && a1<=10000 && a2>=1 && a2<=10000 && b1>=1 && b1<=10000 && b2>=1 && b2<=10000){
                double r,m1,m2,angle,x,theta,arc_distance;
                r= pow((power(o1-a1,2)+power(o2-a2,2)),.5);
                m1=(o2-a2)/(o1-a1);
                m2=(o2-b2)/(o1-b1);
                m=m1*m2;
                if(m==-1.000000){
                    theta=1.570796327;
                }
                else{
                    angle=(m1-m2)/(1+m);
                    if (angle<0){
                        angle=angle*(-1);
                    }
                    x=angle/(pow((1+angle*angle),.5));
                    theta=sine_inverse(x);
                }
                arc_distance=theta*r;
                printf("\n%lf \n%lf \n%lf \n%lf \n%lf \n%lf\n",m1,m2,m1*m2,angle,theta,arc_distance);
                printf("Case no %d : \t%lf\n",i,arc_distance);
                i=i+1;
            //}
        }
    }
    return 0;
}
