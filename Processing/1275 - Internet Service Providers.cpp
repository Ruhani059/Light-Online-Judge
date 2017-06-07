#include<iostream>
using namespace std;
int main ()
{
    int T,t=1;
    cin>>T;
    while(T--)
    {
        long long int C,N,x1,x2,y1,y2;
        cin>>N>>C;
        if (N == 0)
            cout<<"Case "<<t++<<": 0"<<endl;
        else
        {
            x1 = C/(2*N)+1;
            y1 = x1 * ( C - x1 * N );
            x2 = C/(2*N);
            y2 = x2 * ( C - x2 * N );
            if (y1>y2)
                cout<<"Case "<<t++<<": "<<x1<<endl;
            else
                cout<<"Case "<<t++<<": "<<x2<<endl;
        }
    }
    return 0;
}
