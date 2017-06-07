#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define inf 9999999
#define MAX 21

int mat[MAX][4];
int dp[MAX][4];

void neighbour(int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            dp[i][j] = min( dp[i-1][(j+1)%3]+mat[i][j] , dp[i-1][(j+2)%3]+mat[i][j]);
        }
    }
}
int main()
{
    freopen("1047 - Neighbor House.txt","r",stdin);
    int testCases,caseNo=1,n;
    scanf("%d",&testCases);
    while(testCases--)
    {
        for(int k=0;k<MAX;k++)for(int l=0;l<4;l++)dp[k][l]=9999;
        memset(mat,-1,sizeof(mat));
        scanf("%d",&n);
        for(int i=0;i<n;i++)    for(int j=0;j<3;j++)    scanf("%d",&mat[i][j]);
        for(int i=0;i<3;i++)    dp[0][i] = mat[0][i];
        neighbour(n);
        int minm=999999;
        for(int i=0;i<3;i++)
        {
            if( dp[n-1][i] <minm ) minm = dp[n-1][i];
        }
        printf("Case %d: %d\n",caseNo++,minm);
    }
    return 0;
}
