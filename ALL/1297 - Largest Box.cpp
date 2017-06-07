#include<iostream>
#include<cmath>
using namespace std;
int main ()
{
    int T,t=1;
    cin>>T;
    while(T--)
    {
        double L,W,x,v;
        cin>>L>>W;
        x = ( 4*(W+L)-sqrt(16*(W+L)*(W+L)-48*W*L) ) / 24;
        v = ( W - 2 * x ) * ( L - 2 * x ) * x;
        cout<<"Case "<<t++<<": "<<v<<endl;
    }
    return 0;
}

