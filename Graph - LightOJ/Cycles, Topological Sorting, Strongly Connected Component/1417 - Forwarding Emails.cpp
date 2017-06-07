#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<map>
#include<string>
#include<stack>
using namespace std;

#define MAX 50020

vector<int>G[MAX];
vector<int>GT[MAX];
vector<int>Gnew[MAX];
vector<int>GnewT[MAX];
stack<int>S;
map<int,int>my_map;
queue<int>Q;
int color[MAX];
int count=0;
int maxCount = -1;
int node;

void dfs_Visit (vector <int>G[],int u,int condition)
{
    color[u]=1;
    if(condition==1)
    {
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            if(color[v]==0)
                dfs_Visit(G,v,1);
        }
        S.push(u);
    }
    if(condition==2)
    {
        for(int i=0;i<GT[u].size();i++)
        {
            int v=GT[u][i];
            if(color[v]==0)
            {
                cout<<v<<"\t";
                my_map[v]=count;
                dfs_Visit(GT,v,2);
            }
        }
    }
}

void dfs (vector <int>G[],int V,int condition)
{
    for(int i=0;i<=V;i++)
        color[i]=0;

    if(condition==1)
    {
        for(int i=1;i<=V;i++)
            if(color[i]==0) dfs_Visit(G,i,1);
    }

    if(condition==2)
    {
        while(!S.empty())
        {
            int i = S.top();    S.pop();
            if(color[i]==0)
            {
                count++;
                cout<<"\ncomponent"<<count<<"  : "<<i<<"\t";
                my_map[i]=count;
                dfs_Visit(GT,i,2);
                cout<<endl;
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
        count=0;node=-1;maxCount=-1;
        for(int i=0;i<MAX;i++)
        {
            G[i].clear();
            GT[i].clear();
            Gnew[i].clear();
            GnewT[i].clear();
        }
        my_map.clear();
        int V,E,u,v,w;
        scanf("%d",&V);
        for(int i=0;i<V;i++)
        {
            cin>>u>>v;
            G[u].push_back(v);
            GT[v].push_back(u);
        }
        dfs(G,V,1);
        dfs(GT,V,2);
        for(int i=1;i<=V;i++)
        {
            u = my_map[i];
            for(int j=0;j<G[i].size();j++)
            {
                v = my_map[ G[i][j] ];
                if(u!=v)
                {
                    Gnew[u].push_back(v);
                    Gnew[v].push_back(u);
                }
            }
        }
        int a=count;
        count=0;
        dfs(Gnew,a,1);
        for(int i=1;i<=a;i++){cout<<i<<" : ";for(int j=0;j<Gnew[i].size();j++){cout<<Gnew[i][j]<<" ";}cout<<endl;}
        dfs(GnewT,a,2);


        printf("Case %d: %d\t%d\n",caseno++,count,node);
    }
    return 0;
}
