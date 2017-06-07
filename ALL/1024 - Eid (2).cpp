#include<iostream>
#include<cmath>
#include<cstring>
#define size 10
using namespace std;
int gcd (int a, int b);
int lcm (int a, int b);
int gcd (int b);
int mod(int b);
void divisor(int b);
int gcd_array [size];
int mul_array [size];
int least_common_fator[size];
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
        cout<<l<<endl;
        for( i = size - 1 ; k != 0 ; i-- )
        {
            least_common_fator[i] = k % 10;
            k = k / 10;
        }
        cout<<"least_common_fator...\n";
        for(j=0;j<size;j++)
            cout<<least_common_fator[j]<<"";
        cout<<endl<<endl;
        k = l;
        for (i=2;i<N;i++)
        {
            k = l;
            l = lcm (l,number[i]);
            cout<<"lcm ("<<k<<" , "<<number[i]<<") = "<<l<<endl;
            c = 0;
            for(j=size-1;j>=0;j--)
            {
                gcd_array[j] = least_common_fator[j];
                d = least_common_fator[j] * l + c;
                c = d / 10;
                mul_array[j] = d % 10;
            }
            cout<<"least_common_fator...\n";
            for(j=0;j<size;j++)
                cout<<least_common_fator[j]<<"";
            cout<<endl<<endl;
            cout<<"gcd_array...\n";
            for(j=0;j<size;j++)
                cout<<gcd_array[j]<<"";
            cout<<endl<<endl;
            cout<<"mul_array...\n";
            for(j=0;j<size;j++)
                cout<<mul_array[j]<<"";
            cout<<endl<<endl;
            divisor(gcd(l));
            cout<<"After Calling Function...\n";
            cout<<"least_common_fator...\n";
            for(j=0;j<size;j++)
                cout<<least_common_fator[j]<<"";
            cout<<endl<<endl;
            for(j=0;j<size;j++)
            {
                mul_array[j]=0;
                gcd_array[j]=0;
            }
        }
        for( i = 0 ; ; i++ )
            if( least_common_fator[i] != 0 )
                break;
        for( j=i,k=0; j < size ; j++,k++ )
            ans[k] = least_common_fator[j] + 48;
        ans[k]='\0';
        cout<<"\nCase "<<t++<<": "<<ans<<endl;
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
    cout<<"In gcd Function...\n";
    if ( b == 0 )
    {
        int a=0;
        for(int i=size-1,j=1;i>=0;i--,j=j*10)
        {
            a += gcd_array[i]*j;
        }
        cout<<"gcd (gcd_array , "<<b<<") = "<<a<<endl;
        return a;
    }
    else
    {
        int n;
        int k = b;
        n = mod (b);
        for( int i = size - 1 ; i>=0 ; i-- )
        {
            gcd_array[i] = k % 10;
            k = k / 10;
        }
        cout<<"gcd_array in function...\n";
        for(int j=0;j<size;j++)
            cout<<gcd_array[j]<<"";
        cout<<endl<<endl;
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
    cout<<"gcd_array in mod function...\n";
    for(int j=0;j<size;j++)
        cout<<gcd_array[j]<<"";
    cout<<endl<<endl;
    cout<<"divided by "<<b<<"\nans is...\n";
    for(int j=0;j<size;j++)
        cout<<div[j]<<"";
    cout<<endl<<endl;

    cout<<"In mod Function...\ngcd_array % "<<b<<" = "<<c<<endl;
    return c;
}
void divisor(int b)
{
    int c=0,i,j;
    for (i=0;i<size;i++)
    {
        least_common_fator[i] = ( mul_array[i] + c * 10 ) / b;
        c = ( mul_array[i] + c * 10 ) % b;
    }
}
