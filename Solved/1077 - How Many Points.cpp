#include<iostream>
using namespace std;
long long int GCD (long long int a, long long int b)
{
    if(b==0) return a;
    else
        return GCD (b,a%b);
}
int main ()
{
    int T,t=1;
    cin>>T;
    while(T--)
    {
        long long int Ax,Ay,Bx,By;
        cin>>Ax>>Ay>>Bx>>By;
        Ax=Ax-Bx;
        Ay=Ay-By;
        if (Ax<0) Ax=-Ax;
        if (Ay<0) Ay=-Ay;
        cout<<"Case "<<t++<<": "<<GCD(Ax,Ay)+1<<endl;
    }
    return 0;
}
