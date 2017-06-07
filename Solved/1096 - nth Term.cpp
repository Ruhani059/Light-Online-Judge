#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define size 4
#define type unsigned int
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
        type n , a , b , c , i , j , k , ans;
        cin >> n >> a >> b >> c;
        if (n < 3)
        {
            cout<<"Case "<<t++<<": "<<0<<endl;
        }
        else
        {
            for (i=0;i<size;i++)
            {
                for(j=0;j<size;j++)
                {
                    mat_A[i][j] = 0;
                }
            }
            mat_A[0][0] = a;
            mat_A[0][2] = b;
            mat_A[0][3] = 1;
            mat_A[1][0] = 1;
            mat_A[2][1] = 1;
            mat_A[3][3] = 1;

            n = n - 2;

            matrix_exponenciation ( mat_A , n );

            ans = ( mat_exp[0][3] * c ) % 10007;

            cout<<"Case "<<t++<<": "<<ans<<endl;
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
                mat_mult[i][j] += ( mat_A[i][k] * mat_B[k][j] ) % 10007;
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
