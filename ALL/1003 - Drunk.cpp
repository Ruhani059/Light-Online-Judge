#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<map>
#include<string>
using namespace std;

#define MAX 20020

vector<int>edges[MAX];
map<string,int>my_map;

int color[MAX];
int d[MAX];
int p[MAX];
int cycle = 0;

void dfs_Visit (int u)
{
    color[u]=1;
    for(int i=0;i<edges[u].size();i++)
    {
        int v=edges[u][i];

        if(color[v]==1)
        {
//            cout<<"Cycle\n";
            cycle = 1;
        }
        if(color[v]==0)
        {
            p[v]=u;
            dfs_Visit(v);
        }
    }
    color[u]=2;
}

void dfs (int V)
{
    for(int i=0;i<=V;i++)
    {
        color[i]=0;
        d[i]=-1;
        p[i]=NULL;
    }
    for(int i=1;i<=V;i++)
    {
        if(color[i]==0)
        {
            p[i]=NULL;
            dfs_Visit(i);
        }
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
    int testCase,caseno=1;
    scanf("%d",&testCase);
    while(testCase--)
    {
        cycle = 0;
        for(int i=0;i<MAX;i++)
        {
            edges[i].clear();
        }
        my_map.clear();
        int V=0,E;
        string u,v,w;
        scanf("%d",&E);
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            if(!my_map[u]) my_map[u]=++V;
            if(!my_map[v]) my_map[v]=++V;
            edges[my_map[u]].push_back(my_map[v]);
        }
        dfs(V);
        if(cycle == 1)
            printf("Case %d: No\n",caseno++);
        else
            printf("Case %d: Yes\n",caseno++);
        /*
        for(int i=0;i<V;i++){cout<<i<<"  : ";for(int j=0;j<edges[i].size();j++){cout<<edges[i][j]<<" ";}cout<<endl;}cout<<endl;
        */
//        printf("Case %d:\n",caseno++);
    }
    return 0;
}
