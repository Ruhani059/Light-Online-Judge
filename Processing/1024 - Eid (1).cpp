#include<iostream>
#include<cmath>
#include<cstring>
#define size 10
using namespace std;
int gcd (int a, int b);
int lcm (int a, int b);
int gcd (int b);
int mod(int b);
int least_common_fator[size];
int gcd_array [size];
int mul_array [size];
int main ()
{
    int T,t=1;
    cin>>T;
    while(T--)
    {
        int N, d, c = 0, i, j, k, l, l1;
        char ans[size];
        for(i=0;i<size;i++)
        {
            least_common_fator[i] = 0;
            gcd_array[i]=0;
            mul_array[i]=0;
        }
        cin>>N;
        int number[N];
        for(i=0;i<N;i++)
        {
            cin>>number[i];
        }
        for(i=0;i<N;i++)
        {
            cout<<number[i]<<" ";
        }
        cout<<endl;

        l = lcm(number[0],number[1]);
        k = l;
        for( i = size - 1 ; k != 0 ; i-- )
        {
            least_common_fator[i] = k % 10;
            k = k / 10;
        }
        k = l;
        //cout<<l<<endl;
        for (i=2;i<N;i++)
        {
            l = lcm (l,number[i]);
            c = 0;
            for(j=0;j<size;j++)
            {
                gcd_array[i] = least_common_fator[i];
                d = least_common_fator[i] * l + c;
                c = d / 10;
                mul_array[i] = d / 10;
            }

        }
        for( i = 0 ; ; i++ )
            if( least_common_fator[i] != 0 )
                break;
        for( j=i,k=0; j < size ; j++,k++ )
            ans[k] = least_common_fator[j] + 48;
        ans[k]='\0';
        cout<<"Case "<<t++<<": "<<ans<<endl;
    }
    return 0;
}
int lcm (int a, int b)
{
    return (a*b)/gcd(a,b);
}
int gcd (int a, int b)
{
    if (b==0)
        return a;
    else
        return gcd (b,a%b);
}
int gcd (int b)
{
    if ( b == 0 )
    {
        int a=0;
        for(int i=size-1,j=1;i>=0;i--,j=j*10)
        {
            a += gcd_array[i]*j;
        }
        return a;
    }
    else
    {
        int k = b;
        for( int i = size - 1 ; k != 0 ; i-- )
        {
            gcd_array[i] = k % 10;
            k = k / 10;
        }
        int n;
        n = mod (b);
        return gcd(n);
    }
}
int mod (int b)
{
    int c=0,div[size],i,j;
    for (i=0;i<size;i++)
    {
        div[i] = ( gcd_array[i] + c * 10 ) / b;
        c = ( gcd_array[i] + c * 10 ) % b;
    }
    return c;
}
