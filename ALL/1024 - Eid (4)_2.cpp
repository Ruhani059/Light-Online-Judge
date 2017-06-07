#include<iostream>
#include<cmath>
#include<cstring>
#define size 40000
using namespace std;
long long int gcd (long long int a, long long int b);
long long int lcm (long long int a, long long int b);
long long int gcd (long long int b);
long long int mod(long long int b);
void divisor(long long int b);
long long int gcd_array [size];
long long int mul_array [size];
long long int least_common_fator[size];
int main ()
{
    long long int T,t=1;
    cin>>T;
    while(T--)
    {
        long long int N, d, c = 0, i, j, k, l, l1;
        char ans[size];
        for(i=0;i<size;i++)
        {
            least_common_fator[i] = 0;
            gcd_array[i]=0;
            mul_array[i]=0;
        }
        cin>>N;
        long long int number[N];
        for(i=0;i<N;i++)
        {
            cin>>number[i];
        }
        l = lcm(number[0],number[1]);
        k = l;
        for( i = size - 1 ; k != 0 ; i-- )
        {
            least_common_fator[i] = k % 10;
            k = k / 10;
        }
        for (i=2;i<N;i++)
        {
            l = lcm (l,number[i]);
            c = 0;
            for(j=size-1;j>=0;j--)
            {
                gcd_array[j] = least_common_fator[j];
                d = least_common_fator[j] * l + c;
                c = d / 10;
                mul_array[j] = d % 10;
            }
            for(j=0;j<size;j++)
            {
                least_common_fator[j]=0;
            }
            divisor(gcd(l));
            for(j=0;j<size;j++)
            {
                mul_array[j]=0;
                gcd_array[j]=0;
            }
        }
        for( i = 0 ; ; i++ )
            if( least_common_fator[i] != 0 )
                break;
/*
        for( j=i,k=0; j < size ; j++,k++ )
            ans[k] = least_common_fator[j] + 48;
        ans[k]='\0';
*/
        cout<<"Case "<<t++<<": ";
        for( j=i; j < size ; j++ )
            cout<<least_common_fator[j];
        cout<<endl;
    }
    return 0;
}
long long int lcm (long long int a, long long int b)
{
    return (a*b)/gcd(a,b);
}
long long int gcd (long long int a, long long int b)
{
    if (b==0) return a;
    else return gcd (b,a%b);
}
long long int gcd (long long int b)
{
    if ( b == 0 )
    {
        long long int a=0;
        for(long long int i=size-1,j=1;i>=0;i--,j=j*10)
        {
            a += gcd_array[i]*j;
        }
        return a;
    }
    else
    {
        long long int n, k = b;
        n = mod (b);
        for( long long int i = size - 1 ; i>=0 ; i-- )
        {
            gcd_array[i] = k % 10;
            k = k / 10;
        }
        return gcd(n);
    }
}
long long int mod (long long int b)
{
    long long int c=0,div[size],i,j;
    for (i=0;i<size;i++)
    {
        div[i] = ( gcd_array[i] + c * 10 ) / b;
        c = ( gcd_array[i] + c * 10 ) % b;
    }
    return c;
}
void divisor(long long int b)
{
    long long int c=0,i,j;
    for (i=0;i<size;i++)
    {
        least_common_fator[i] = ( mul_array[i] + c * 10 ) / b;
        c = ( mul_array[i] + c * 10 ) % b;
    }
}
