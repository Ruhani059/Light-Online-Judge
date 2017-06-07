#include<iostream>
#include<cstdio>
#include<vector>
#include<fstream>
#include<queue>
using namespace std;
#define MAX 10001 //maximum node

vector<int>edges[MAX];
int d[MAX];
int result[MAX];

void dfsVisit(int u)
{
    result[u]++;
    d[u] = 1;
    for(int i=0;i<edges[u].size();i++)
    {
        int v = edges[u][i];
        if(d[v]==0)  dfsVisit(v);
    }
}

void dfs(int V, int source)
{
    for(int i=1;i<=V;i++)    d[i]=0;
    dfsVisit(source);
}

int main()
{
    freopen("input.txt","r",stdin);
    int testCases,k,n,m,x,y;
    cin>>testCases;
    for(int cases = 1 ; cases<=testCases ; cases++)
    {
        for(int i=0;i<MAX;i++)
        {
            edges[i].clear();
            result[i]=0;
        }
        cin>>k>>n>>m;
        int searchedArray[k];
        for(int i=0;i<k;i++){cin>>searchedArray[i];}

        for(int i=0;i<m;i++){cin>>x>>y;edges[x].push_back(y);}

        for(int i=0;i<k;i++){dfs(n,searchedArray[i]);}

        int count = 0;
        for(int i=1;i<=n;i++)
            if(result[i]==k)    count++;

        cout<<"Case "<<cases<<": "<<count<<endl;
    }
    return 0;
}

