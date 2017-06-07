#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define inf 1<<28
#define MAX 100

int n;
int mat[MAX][MAX];
int dp[MAX][MAX];
int r=3,c=3;

int neighbour(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<3)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        int ret=-inf;
            ret=min( ret , neighbour(i+1,j+1)+mat[i][j]);
            ret=min( ret , neighbour(i+1,j+2)+mat[i][j]);
            ret=min( ret , neighbour(i+1, j-1)+mat[i][j]);
            ret=min( ret , neighbour(i+1, j-2)+mat[i][j]);
            dp[i][j]=ret;

        return dp[i][j];
//        cout<<"For : neighbour("<<i<<","<<j<<")"<<endl;
//        for(int k=0;k<r;k++){for(int l=0;l<c;l++){cout<<dp[k][l]<<"\t";}cout<<endl;}cout<<endl;
    }
    else return 0; //if outside the array
}
int main()
{
//	READ("in");
    freopen("1047 - Neighbor House.txt","r",stdin);
    int testCases,caseNo=1;
    scanf("%d",&testCases);
    while(testCases--)
    {
        memset(dp,-1,sizeof(dp));
        memset(mat,-1,sizeof(mat));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)   scanf("%d",&mat[i][j]);
        }
        neighbour(0,0);
        int minm=999999999;
        for(int i=0;i<n;i++)
        {
            if(mat[0][i]<minm)  minm=mat[0][i];
        }
        printf("Case %d: %d\n",caseNo++,minm);
    }
    return 0;
}
