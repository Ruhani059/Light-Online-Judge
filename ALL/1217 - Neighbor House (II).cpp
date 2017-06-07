#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define inf 9999999
#define MAX 23

int n;
int mat[MAX][6];
int dp[MAX][6];
int r=3,c=3;

int neighbour(int i,int j)
{
//    if(dp[i][j]!=9999) return dp[i][j];
        if(i>=0 && i<n && j>=0 && j<3)
        {
//            if(dp[i][j]!=9999) return 1;
    //        int ret=inf;
                dp[i][j] = min( dp[i-1][(j+1)%3+mat[i][j]] , dp[i-1][(j+2)%3]+mat[i][j]);
//                cout<<1<<endl;
    //            for(int k=0;k<r;k++){for(int l=0;l<3;l++){cout<<dp[k][l]<<"\t";}cout<<endl;}cout<<endl;
                neighbour(i,j+1);

                neighbour(i+1,(j+1)%3);
                neighbour(i+1,(j+2)%3);
//                return 1;
        //        dp[i+1][j-1] = min( dp[i+1][j-1] , neighbour(i+1, j-1)+mat[i][j]);
            //    dp[i+1][j-2] = min( dp[i+1][j-2] , neighbour(i+1, j-2)+mat[i][j]);
    //            dp[i][j]=ret;

    //        for(int k=0;k<r;k++){for(int l=0;l<c;l++){cout<<dp[k][l]<<"\t";}cout<<endl;}cout<<endl;
    //        return 1;
    //        cout<<"For : neighbour("<<i<<","<<j<<")"<<endl;
        //    for(int k=0;k<r;k++){for(int l=0;l<c;l++){cout<<dp[k][l]<<"\t";}cout<<endl;}cout<<endl;
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
//        int a=1;
//        memset(dp,9999,sizeof(dp));
                for(int k=0;k<MAX;k++)for(int l=0;l<MAX;l++)dp[k][l]=99999999;
//                for(int k=0;k<r;k++){for(int l=0;l<c;l++){cout<<dp[k][l]<<"\t";}cout<<endl;}cout<<endl;
        memset(mat,-1,sizeof(mat));
    //            for(int k=0;k<r;k++){for(int l=0;l<c;l++){cout<<mat[k][l]<<"\t";}cout<<endl;}cout<<endl;
        scanf("%d",&n);
        r=n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)   scanf("%d",&mat[i][j]);
        }
        //for(int k=0;k<r;k++){for(int l=0;l<c;l++){cout<<mat[k][l]<<"\t";}cout<<endl;}cout<<endl;
        for(int i=0;i<3;i++)
        {
            dp[0][i] = mat[0][i];
        }
        neighbour(1,0);
        int minm=999999;
        for(int i=0;i<3;i++)
        {
            if( dp[n-1][i] <minm ) minm = dp[n-1][i];
        }
        printf("Case %d: %d\n",caseNo++,minm);
//        for(int k=0;k<n;k++){for(int l=0;l<3;l++){cout<<dp[k][l]<<"\t";}cout<<endl;}cout<<endl;
    }
    return 0;
}
