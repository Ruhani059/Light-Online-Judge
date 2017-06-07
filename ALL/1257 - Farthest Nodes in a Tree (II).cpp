#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 30001

vector<int>edges[MAX];
vector<int>weights[MAX];
int check_bfs[MAX];
int max_distance[MAX];

int bfs (int V, int source)
{
    queue<int>Q;
    int color[V];
    int distance[V];
    int parent[V];
    for(int i=0;i<V;i++)
    {
        color[i]=0;
        distance[i]=-1;
        parent[i]=-1;
    }
    color[source]=1;
    distance[source]=0;
    parent[source]=NULL;
    Q.push(source);
    while(!Q.empty())
    {
        int u = Q.front();
        for(int i=0;i<edges[u].size();i++)
        {
            int v = edges[u][i];
            if(color[v]==0)
            {
                color[v]=1;
                distance[v]=distance[u]+weights[u][i];
                parent[v]=u;
                Q.push(v);
            }
        }
        color[u]=2;
        Q.pop();
    }
    int max = -1,node;
    for(int i=0;i<V;i++)
    {
        if(distance[i]>max)
        {
            max=distance[i];
            node = i;
        }
    }
    for(int i=0;i<V;i++)
    {
        if(distance[i]>max_distance[i])
            max_distance[i]=distance[i];
    }
    cout<<source<<" : ";
    for(int i=0;i<V;i++)
    {
        cout<<max_distance[i]<<"\t";
    }
    cout<<endl;
//    cout<<node<<distance;
    return node;
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
            check_bfs[i]=0;
            max_distance[i]=-1;
        }
        int n,u,v,w;
        scanf("%d",&n);
        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            edges[u].push_back(v);
            edges[v].push_back(u);
            weights[u].push_back(w);
            weights[v].push_back(w);
        }
        /*
        for(int i=0;i<V;i++)
        {
            cout<<i<<"  : ";
            for(int j=0;j<edges[i].size();j++)
            {
                cout<<edges[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        */
        printf("Case %d:\n",caseno++);
        check_bfs[0]=1;
        int node = bfs(n,0);
//        check_bfs[node]=1;
        while(check_bfs[node]==0)
        {
            check_bfs[node]=1;
            node = bfs(n,node);
        }

        for(int i=0;i<n;i++)
        {
            printf("%d\n",max_distance[i]);
        }

    }
    return 0;
}

