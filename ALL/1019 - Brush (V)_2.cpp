#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define MAX 501

vector<int>edges[MAX];
vector<int>weights[MAX];

int min(int a, int b){if(a<b)  return a; else return b;}
int max(int a, int b){if(a>b)  return a; else return b;}

void bfs (int V, int source)
{
    queue<int>Q;
    int distance[MAX];
    for(int i=0;i<MAX;i++)
    {
        distance[i]=99999999;
    }
    distance[source]=0;
    Q.push(source);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0;i<edges[u].size();i++)
        {
            int v = edges[u][i];
            if(distance[v]>distance[u]+weights[u][i])
            {
                distance[v]=distance[u]+weights[u][i];
                Q.push(v);
            }
        }
    }

    if(distance[V]==99999999) printf("Impossible\n");
    else printf("%d\n",distance[V]);
}

int main()
{
    int testCase,caseno=1;
    scanf("%d",&testCase);
    while(testCase--)
    {
        for(int i=0;i<MAX;i++)
        {
            edges[i].clear();
            weights[i].clear();
        }
        int V,E,u,v,w;
        scanf("%d %d",&V,&E);
        for(int i=0;i<E;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            edges[u].push_back(v);
            edges[v].push_back(u);
            weights[u].push_back(w);
            weights[v].push_back(w);
        }
        printf("Case %d: ",caseno++);
        bfs(V,1);
    }
    return 0;
}

