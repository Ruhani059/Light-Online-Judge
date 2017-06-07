#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 110
long long int n;
long long int dp[MAX][MAX];
long long int arr[MAX][MAX];

void max_banana(long long int i,long long int j)
{
    if(i>n || j>n)   return;
    if(i==n && j==n)    return;

    long long int val1=dp[i][j]+arr[i+1][j];
    dp[i+1][j]=max(dp[i+1][j],val1);
    max_banana(i+1,j);

    long long int val2=dp[i][j]+arr[i][j+1];
    dp[i][j+1]=max(dp[i][j+1],val2);
    max_banana(i,j+1);
}
int main()
{
    freopen("in.txt","r",stdin);
    memset(dp,-1,sizeof(dp));
    memset(arr,-1,sizeof(arr));
    long long int testCases,caseNo=1;
    scanf("%lld",&testCases);
    while(testCases--)
    {
        memset(dp,-1,sizeof(dp));
        memset(arr,-1,sizeof(arr));
        scanf("%lld",&n);
        for(int k=1;k<=2*n-1;k++)
        {
            if(k<=n)    for(int i=1;i<=k;i++)   scanf("%lld",&arr[k+1-i][i]);
            else    for(int i=n-1,l=0;i>=k-n;i--,l++)   scanf("%lld",&arr[n-l][k-n+1+l]);
        }
        dp[1][1]=arr[1][1];
        max_banana(1,1);
        printf("Case %lld: %lld\n",caseNo++,dp[n][n]);
    }
    return 0;
}
