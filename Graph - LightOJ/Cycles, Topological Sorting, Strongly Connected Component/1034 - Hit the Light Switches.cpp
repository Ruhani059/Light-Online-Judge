#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<map>
#include<string>
#include<stack>
using namespace std;

#define MAX 10020

vector<int>edges[MAX];
stack<int>S;
int color[MAX];
int count=0;

void dfs_Visit (int u,int condition)
{
    color[u]=1;
    for(int i=0;i<edges[u].size();i++)
    {
        int v=edges[u][i];
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
                count++;
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
        count=0;
        for(int i=0;i<MAX;i++)
            edges[i].clear();

        int V,E,u,v,w;
        scanf("%d %d",&V,&E);
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            edges[u].push_back(v);
        }
        dfs(V,1);
        dfs(V,2);
        printf("Case %d: %d\n",caseno++,count);
    }
    return 0;
}
