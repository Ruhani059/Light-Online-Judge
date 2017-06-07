#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define size 6
#define type unsigned int
using namespace std;

type mat_exp[size][size];

type mat_mult[size][size];

type mat_A[size][size];

type M;

void square_matrix_multiplication ( type mat_A[][size] , type mat_B[][size] );

void matrix_multiplication ( type mat_A[][size] , type mat_B[][1] );

void matrix_exponenciation ( type mat_A[][size] , type n );

int main ()
{
    type T,t=1;
    cin>>T;
    while(T--)
    {
        type a1 , b1 , c1, a2 , b2 , c2, f0 , f1 , f2 , g0 , g1 , g2 , q , i , j , k , mat_B[size][1];
        cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> f0  >> f1 >> f2 >> g0  >> g1 >> g2 >> M >> q ;
        type array[q];
        mat_B[0][0] = f2; mat_B[1][0] = f1; mat_B[2][0] = g0;
        mat_B[3][0] = g2; mat_B[4][0] = g1; mat_B[5][0] = f0;

        for (i=0;i<q;i++)
            cin>>array[i];
        cout<<"Case "<<t++<<":"<<endl;
        for (k=0;k<q;k++)
        {
            if (array[k]<=2)
            {
                if (array[k] == 0)
                    cout<<f0 % M<<" "<<g0 % M<<endl;
                else if (array[k] == 1)
                    cout<<f1 % M<<" "<<g1 % M<<endl;
                else if (array[k] == 2)
                    cout<<f2 % M<<" "<<g2 % M<<endl;
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
                mat_A[0][0] = a1; mat_A[0][1] = b1; mat_A[0][2] = c1; mat_A[1][0] = 1; mat_A[2][4] = 1;
                mat_A[3][3] = a2; mat_A[3][4] = b2; mat_A[3][5] = c2; mat_A[4][3] = 1; mat_A[5][1] = 1;
/*
                for (i=0;i<size;i++)
                {
                    for(j=0;j<size;j++)
                    {
                        cout<<mat_A[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;
*/
                matrix_exponenciation ( mat_A , (array[k] - 2) );

                matrix_multiplication ( mat_exp , mat_B );
/*
                for (i=0;i<size;i++)
                {
                    for(j=0;j<size;j++)
                    {
                        cout<<mat_exp[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;
*/
                cout<<mat_mult[0][0] % M<<" "<<mat_mult[3][0] % M<<endl;
            }
        }
    }
    return 0;
}

void square_matrix_multiplication ( type mat_A[][size] , type mat_B[][size] )
{
    type i,j,k;
    for (i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            mat_mult[i][j]=0;
            for(k=0;k<size;k++)
            {
                mat_mult[i][j] += ( mat_A[i][k] * mat_B[k][j] ) % M;
                mat_mult[i][j] = mat_mult[i][j] % M;
            }
        }
    }
}

void matrix_multiplication ( type mat_A[][size] , type mat_B[][1] )
{
    type i,j,k;
    for (i=0;i<size;i++)
    {
        for(j=0;j<1;j++)
        {
            mat_mult[i][j]=0;
            for(k=0;k<size;k++)
            {
                mat_mult[i][j] += ( mat_A[i][k] * mat_B[k][j] ) % M;
                mat_mult[i][j] = mat_mult[i][j] % M;
            }
        }
    }
}

void matrix_exponenciation ( type A[][size] , type n )
{
    type i,j,k;
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
            square_matrix_multiplication( mat_exp , mat_A );
            for (i=0;i<size;i++)
            {
                for(j=0;j<size;j++)
                {
                    mat_exp[i][j] = mat_mult[i][j];
                }
            }
        }
        square_matrix_multiplication( mat_A, mat_A );
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
