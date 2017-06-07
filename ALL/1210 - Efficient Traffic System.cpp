#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<map>
#include<string>
#include<stack>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 20020

vector<int>G[MAX];
vector<int>GT[MAX];
vector<int>Gnew[MAX];
stack<int>S;
map<int,int>my_map;
int color[MAX];
int component=0;

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
                my_map[v]=component;
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
                component++;
                my_map[i]=component;
                dfs_Visit(GT,i,2);
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
        component=0;
        for(int i=0;i<MAX;i++)
        {
            G[i].clear();
            GT[i].clear();
            Gnew[i].clear();
        }
        my_map.clear();
        int V,E,u,v,w;
        scanf("%d %d",&V,&E);
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            G[u].push_back(v);
            GT[v].push_back(u);
        }
        for(int i=1;i<=V;i++){cout<<i<<" : ";for(int j=0;j<G[i].size();j++){cout<<G[i][j]<<" ";}cout<<endl;}cout<<endl;
        dfs(G,V,1);
        dfs(GT,V,2);
        vector<int>::iterator ita;
        for(int i=1;i<=V;i++)
        {
            u = my_map[i];
            for(int j=0;j<G[i].size();j++)
            {
                v = my_map[ G[i][j] ];
                ita = find(Gnew[u].begin(),Gnew[u].end(),v);
                if(u!=v && ita==Gnew[u].end())
                        Gnew[u].push_back(v);
            }
        }

        for(int i=1;i<=component;i++){cout<<i<<" : ";for(int j=0;j<Gnew[i].size();j++){cout<<Gnew[i][j]<<" ";}cout<<endl;}

        if(component==1)    printf("Case %d: 0\n",caseno++);
        else
        {
            int road =0, roadFlag = 0;
            for(int i=1;i<component;i++)
            {
                for(int j=0;j<Gnew[i].size();j++)
                    if(Gnew[i][j]==i+1)
                        roadFlag=1;
                if(roadFlag==0) road++;
                roadFlag=0;
            }
            for(int i=0;i<Gnew[component].size();i++)  if(Gnew[component][i]==1)  roadFlag=1;
            if(roadFlag==0) road++;
            printf("Case %d: %d\n",caseno++,road);
        }
    }
    return 0;
}
