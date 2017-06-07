#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define inf 9999999
#define MAX 18

int mat[MAX][MAX];
int dp[MAX][MAX];

void neighbour(int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(j!=(j+k)%n)
                {
                    dp[i][j] = max( dp[i][j], dp[i-1][(j+k)%n]+mat[i][j]);
                }
            }
        }
        for(int d=0;d<n;d++){for(int l=0;l<n;l++){cout<<dp[d][l]<<"\t";}cout<<endl;}cout<<endl;
        cout<<endl;

    }
}
int main()
{
    freopen("1047 - Neighbor House.txt","r",stdin);
    int testCases,caseNo=1,n;
    scanf("%d",&testCases);
    while(testCases--)
    {
//        for(int k=0;k<MAX;k++)for(int l=0;l<MAX;l++)dp[k][l]=9999;
        memset(mat,-1,sizeof(mat));
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(int i=0;i<n;i++)    for(int j=0;j<n;j++)    scanf("%d",&mat[i][j]);
        for(int i=0;i<n;i++)    dp[0][i] = mat[0][i];
        neighbour(n);
        int minm=-1;
        for(int i=0;i<n;i++)
        {
            if( dp[n-1][i] > minm ) minm = dp[n-1][i];
        }
        printf("Case %d: %d\n",caseNo++,minm);
    }
    return 0;
}
