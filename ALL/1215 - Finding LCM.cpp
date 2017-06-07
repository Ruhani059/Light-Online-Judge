#include<iostream>
#include<cmath>
#define size 1000
using namespace std;
long long int gcd (long long int a, long long int b);
long long int lcm (long long int a, long long int b);
int main ()
{
    int T,t=1;
    cin>>T;
    while(T--)
    {
        long long int a,b,L,c,g,l,check = 0,i,j,k,factor[size];
        double s;
        cin>>a>>b>>L;
        l = lcm(a,b);
        s = sqrt (L);
        for(i=0;i<size;i++)
        {
            factor[i]=0;
        }
        for(i=1,j=0,k=size-1;i<=s;i++)
        {
            if(L%i==0)
            {
                factor[j++]=i;
                factor[k--]=L/i;
            }
        }
        if ( L % l != 0)
            cout<<"Case "<<t++<<": impossible"<<endl;
        else
        {
            for (j=0;j<1;j++)
            {
                for(i=0;i<j;i++)
                {
                    g = lcm(l,factor[i]);
                    if (g == L)
                    {
                        check = 1;
                        break;
                    }
                }
                if (check == 1)
                {
                    break;
                }
                for(i=k+1;i<size;i++)
                {
                    g = lcm(l,factor[i]);
                    if (g == L)
                    {
                        check = 1;
                        break;
                    }
                }

            }
            if (check == 1)
            {
                cout<<"Case "<<t++<<": "<<factor[i]<<endl;
            }
            else
            {
                cout<<"Case "<<t++<<": impossible"<<endl;
            }
        }
    }
    return 0;
}
long long int lcm (long long int a, long long int b)
{
    return (a*b)/gcd(a,b);
}
long long int gcd (long long int a, long long int b)
{
    if (b==0)
        return a;
    else
        return gcd (b,a%b);
}
