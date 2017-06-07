#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<map>
#include<string>
#include<stack>
using namespace std;

#define MAX 20020

vector<int>G[MAX];
stack<int>S;
map<int,int>my_map;

int color[MAX];

void dfs_Visit (int u,int condition)
{
    color[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(color[v]==0)
        {
            if(condition==1)    dfs_Visit(v,1);
            if(condition==2)    dfs_Visit(v,2);
        }
    }
    if(condition==1)
        S.push(u);
}

void dfs (int V,int condition)
{
    for(int i=0;i<=V;i++)
        color[i]=0;

    if(condition==1)
    {
        for(int i=1;i<=V;i++)
            if(color[i]==0) dfs_Visit(i,1);
    }

    if(condition==2)
    {
        while(!S.empty())
        {
            int i = S.top();    S.pop();
            if(color[i]==0)
            {
                dfs_Visit(i,2);
            }
        }
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
        }
        my_map.clear();

        int V=0,E,u,v,w;
        scanf("%d",&E);
        for(int i=0;i<E;i++)
        {
            scanf("%d",&w);
            for(int i=0;i<w;i++)
            {
                cin>>u>>v;
                if(!my_map[u]) my_map[u]=++V;
                if(!my_map[v]) my_map[v]=++V;
                G[my_map[u]].push_back(my_map[v]);
            }
        }
        dfs(V,1);
        dfs(V,2);
        int check = 1;
        for(int i=1;i<=V;i++)
        {
            if(color[i]==0)
            {
                check=0;
            }
        }
        if(check == 1)
            printf("Case %d: Yes\n",caseno++);
        else
            printf("Case %d: No\n",caseno++);
        //for(int i=1;i<=V;i++){cout<<i<<"  : ";for(int j=0;j<G[i].size();j++){cout<<G[i][j]<<" ";}cout<<endl;}cout<<endl;
    }
    return 0;
}
