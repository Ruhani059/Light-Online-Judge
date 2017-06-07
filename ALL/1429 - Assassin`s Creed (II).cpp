#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<map>
#include<string>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;

#define MAX 1010

vector<int>G[MAX];
int color[MAX];
int kount;
int taken[MAX];
int result;

struct node
{
    int v,k;
    node(int a,int b){v=a;k=b;}
    bool operator < (const node &p) const {return k>p.k;}
};

vector<node>vv;

void dfs_Visit (int u)
{
    color[u] = 1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(color[v]==0)
        {
            kount++;
            dfs_Visit(v);
        }
    }

}

void dfs (int V)
{
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            color[j] = 0;
        }
        dfs_Visit(i);
        node temp(i,kount);
        vv.push_back(temp);
        kount = 0;

    }
}

void dfs_Visit_mod(int u)
{
    taken[u]=1;
    color[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];
        if(color[v]==0)
        {
            dfs_Visit_mod(v);
        }
    }
}

void dfs_mod(int V)
{
    int knew=0,kold=0;
    for(int i=1;i<=V;i++)
    {
        knew = 0;
        for(int j=1;j<=V;j++)   color[j] = 0;
        node temp = vv[i-1];
        int v = temp.v;
        dfs_Visit_mod(v);
        for(int j=1;j<=V;j++)
        {
            if(taken[j]==1) knew++;
        }
        if(knew>kold)   result++;

        kold = knew;
    }
}


int main()
{
    freopen("input.txt","r",stdin);
    int testCase,caseno=1;
    scanf("%d",&testCase);
    while(testCase--)
    {
        for(int i=0;i<MAX;i++)
        {
            G[i].clear();
            taken[i]=0;
        }
        result = 0;
        vv.clear();
        kount = 0;

        int V,E,u,v,w;
        scanf("%d %d",&V,&E);

        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            G[u].push_back(v);
        }

        dfs(V);
        sort(vv.begin(),vv.end());
        dfs_mod(V);
        printf("Case %d: %d\n",caseno++,result);
    }
    return 0;
}
