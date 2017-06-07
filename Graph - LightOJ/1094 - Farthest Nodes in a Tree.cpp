
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 30001

vector<int>edges[MAX];
vector<int>weights[MAX];
int node;
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
    int max = -1;
    for(int i=0;i<V;i++)
    {
        if(distance[i]>max)
        {
            node = i;
            max = distance[i];
        }
    }
//    cout<<node<<distance;
    return max;
    /*
    for(int i=0;i<V;i++)
    {
        cout<<"i = "<<i<<' '<<color[i]<<' '<<distance[i]<<' '<<parent[i]<<endl;
    }
    */
}

int main()
{
    int testCase,caseno=1;
    cin>>testCase;
    while(testCase--)
    {
        int n,u,v,w;
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
            cin>>u>>v>>w;
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
        int maxDistance = bfs(n,0);
        maxDistance = bfs(n,node);
        cout<<"Case "<<caseno++<<": "<<maxDistance<<endl;
        for(int i=0;i<MAX;i++)
        {
            edges[i].clear();
            weights[i].clear();
        }
    }
    return 0;
}
