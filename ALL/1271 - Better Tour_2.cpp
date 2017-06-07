#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cstdlib>
using namespace std;
#define MAX 50010

vector<int>G[MAX];
int color[MAX];
int p[MAX];
queue<int>Q;
stack<int>S;

void bfs (int V,int s,int d)
{
    memset(color,0,sizeof(color));
    memset(p,0,sizeof(p));
    color[s]=1;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();  Q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v = G[u][i];
            if(color[v]==0)
            {
                color[v]=1;
                p[v]=u;
                Q.push(v);
            }

        }
    }

}

void path (int u,int v)
{
    S.push(v);
    while(p[v]!=u)
    {
        v=p[v];
        S.push(v);
    }
    S.push(u);
    while(!S.empty())
    {
        if(S.size()==1)
        {
            printf("%d\n",S.top()); S.pop();
        }
        else
        {
            printf("%d ",S.top());  S.pop();
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
        for(int i=0;i<MAX;i++)  G[i].clear();
        int V,E,u,v,w,s,d;
        scanf("%d",&V);
        scanf("%d",&u);
        s = u;
        for(int i=1;i<V;i++)
        {
            scanf("%d",&v);
            G[u].push_back(v);
            G[v].push_back(u);
            u = v;
        }
        for(int i=0;i<MAX;i++)  sort(G[i].begin(),G[i].end());
        d=u;
        printf("Case %d:\n",caseno++);
        bfs(V,s,d);
        path(s,d);
    }
    return 0;
}

