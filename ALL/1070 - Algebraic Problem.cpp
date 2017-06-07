#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define size 2
#define type unsigned long long int
using namespace std;

type mat_exp[size][size], mat_mult[size][size], mat_A[size][size], i, j, k;

void matrix_multiplication ( type mat_A[][size] , type mat_B[][size] );

void matrix_exponenciation ( type mat_A[][size] , type n );

int main ()
{
    int T,t=1;
    cin>>T;
    while(T--)
    {
        type p,q,n,f0,f1,ans;
        cin >> p >> q >> n ;
        if (n == 0)
            cout<<"Case "<<t++<<": "<<2<<endl;
        else if ( n == 1)
            cout<<"Case "<<t++<<": "<<p<<endl;
        else
        {
            n = n-1;
            mat_A[0][0] = p;    mat_A[0][1] = -q;    mat_A[1][0] = 1;    mat_A[1][1] = 0;
            matrix_exponenciation ( mat_A , n );
            f0 = 2; f1=p;
            ans = mat_exp[0][0] * f1 + mat_exp[0][1] * f0 ;
            printf("Case %d: %llu\n",t++,ans);
        }
    }
    return 0;
}

void matrix_multiplication ( type mat_A[][size] , type mat_B[][size] )
{
    for (i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            mat_mult[i][j]=0;
            for(k=0;k<size;k++)
            {
                mat_mult[i][j] += mat_A[i][k] * mat_B[k][j];
            }
        }
    }
}

void matrix_exponenciation ( type A[][size] , type n )
{
    for (i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            mat_exp[i][j] = ( i==j );
        }
    }
    while (n)
    {
        if (n%2 == 1)
        {
            matrix_multiplication( mat_exp , mat_A );
            for (i=0;i<size;i++)
            {
                for(j=0;j<size;j++)
                {
                    mat_exp[i][j] = mat_mult[i][j];
                }
            }
        }
        matrix_multiplication( mat_A, mat_A );
        for (i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                mat_A[i][j] = mat_mult[i][j];
            }
        }
        n = n/2;
    }
}
