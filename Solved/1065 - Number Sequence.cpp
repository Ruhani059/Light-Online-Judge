#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define size 2
#define type unsigned long long int
using namespace std;

type mat_exp[size][size];

type mat_mult[size][size];

type mat_A[size][size];

void matrix_multiplication ( type mat_A[][size] , type mat_B[][size] );

void matrix_exponenciation ( type mat_A[][size] , type n );

int main ()
{
    type T,t=1;
    cin>>T;
    while(T--)
    {
        type a , b , n , m , c , i , j , k , ans , mod;
        cin >> a >> b >> n >> m;
        mod = pow(10,m);

        if (n == 0)
        {
            cout<<"Case "<<t++<<": "<<a<<endl;
        }
        else if (n == 1)
        {
            cout<<"Case "<<t++<<": "<<b<<endl;
        }
        else
        {
            mat_A[0][0] = 1;    mat_A[0][1] = 1;    mat_A[1][0] = 1;    mat_A[1][1] = 0;

            n = n - 1;

            matrix_exponenciation ( mat_A , n );

            ans = ( mat_exp[0][0] * b + mat_exp[0][1] * a ) % 100000000;

            cout<<"Case "<<t++<<": "<<ans % mod<<endl;
        }
    }
    return 0;
}

void matrix_multiplication ( type mat_A[][size] , type mat_B[][size] )
{
    type i,j,k,N = size;
    for (i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            mat_mult[i][j]=0;
            for(k=0;k<N;k++)
            {
                mat_mult[i][j] += ( mat_A[i][k] * mat_B[k][j] )  % 100000000;
                mat_mult[i][j] = mat_mult[i][j]  % 100000000;
            }
        }
    }
}

void matrix_exponenciation ( type A[][size] , type n )
{
    type i,j,k,N = size;
    for (i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            mat_exp[i][j] = ( i==j );
        }
    }
    while (n)
    {
        if (n%2 == 1)
        {
            matrix_multiplication( mat_exp , mat_A );
            for (i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                {
                    mat_exp[i][j] = mat_mult[i][j];
                }
            }
        }
        matrix_multiplication( mat_A, mat_A );
        for (i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                mat_A[i][j] = mat_mult[i][j];
            }
        }
        n = n/2;
    }
}
