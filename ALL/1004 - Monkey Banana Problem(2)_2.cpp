#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 110
long long int n;
long long int dp[MAX][MAX];
long long int arr[MAX][MAX];

int main()
{
    freopen("in.txt","r",stdin);
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
        for(int k=1;k<=2*n-1;k++)
        {
            if(k<=n)
            {
                for(int i=1;i<=k;i++)
                {
                    dp[k+1-i+1][i] = max( dp[k+1-i+1][i], dp[k+1-i][i]+arr[k+1-i+1][i] );
                    dp[k+1-i][i+1] = max( dp[k+1-i][i+1], dp[k+1-i][i]+arr[k+1-i][i+1] );
                }
            }
            else
            {
                for(int i=n-1,l=0;i>=k-n;i--,l++)
                {
                    dp[n-l+1][k-n+1+l] = max( dp[n-l+1][k-n+1+l], dp[n-l][k-n+1+l]+arr[n-l+1][k-n+1+l] );
                    dp[n-l][k-n+1+l+1] = max( dp[n-l][k-n+1+l+1], dp[n-l][k-n+1+l]+arr[n-l][k-n+1+l+1] );
                }
            }
        }

        printf("Case %lld: %lld\n",caseNo++,dp[n][n]);
    }
    return 0;
}

