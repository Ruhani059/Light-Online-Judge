#include<stdio.h>
int set_month (char month[]);
int leap_year (int a, int b);
int main ()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        char month1[10] , month2[10];
        int m1,m2,d1,d2,y1,y2;
        scanf("%s %d, %d",month1,&d1,&y1);
        scanf("%s %d, %d",month2,&d2,&y2);
        m1=set_month(month1);
        m2=set_month(month2);
        int carry = 0,leap;
        if( ( y1%4==0 && y1%100!=0 )  || ( y1%400 == 0 )  )
        {
            if( m1 > 2) carry++;
        }
        if( ( y2%4==0 && y2%100!=0 )  || ( y2%400 == 0 )  )
        {
            if( m2 == 2 && d2 < 29) carry++;
            else if ( m2 < 2) carry++;
        }
        int s1,s2,s3;
        s1 = leap_year(y1,y2);
        if( y1 % 100 != 0)
            y1 = y1 + 100 - y1 % 100;
        y2 = y2 - y2 % 100;
        y1 = y1 / 100;
        y2 = y2 / 100;
        s3 = y2 - y1 + 1;
        if (s3 < 0)
            s2 = 0;
        else
        {
            s2 = leap_year(y1,y2);
            s2 = s3 - s2;
        }
        leap = s1 - s2 - carry;
        printf("Case %d: %d\n",t++,leap);
    }
    return 0;
}
int leap_year (int a, int b)
{
    if( a % 4 != 0)
        a = a + 4 - a % 4;
    b = b - b % 4;
    if (b-a >= 0)
        return (b-a)/4 + 1;
    else
        return 0;
}
int set_month (char month[])
{
    if ( !strcmp(month,"January") ) return 1;
    else if ( !strcmp(month,"February") ) return 2;
    else if ( !strcmp(month,"March") ) return 3;
    else if ( !strcmp(month,"April") ) return 4;
    else if ( !strcmp(month,"May") ) return 5;
    else if ( !strcmp(month,"June") ) return 6;
    else if ( !strcmp(month,"July") ) return 7;
    else if ( !strcmp(month,"August") ) return 8;
    else if ( !strcmp(month,"September") ) return 9;
    else if ( !strcmp(month,"October") ) return 10;
    else if ( !strcmp(month,"November") ) return 11;
    else if ( !strcmp(month,"December") ) return 12;
}
