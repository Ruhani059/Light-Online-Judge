#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

#define MAX 20010

vector<int>edges[MAX];
queue<int>Q;
int color[MAX];
int partition[MAX];
int check[MAX];         //checking if source is counted before.
int result=0;
int max(int a,int b){if(a>=b)return a;return b;}

void bfsVisit(int source)
{
    int lykan=0,vampire=0;
    color[source]=1;
    partition[source]=1;
    Q.push(source);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0;i<edges[u].size();i++)
        {
            if(u==source && check[source]==0) lykan++;
            check[source]=1;
            int v = edges[u][i];
            if(color[v]==0)
            {
                color[v]=1;
                partition[v] = 3 - partition[u];
                if(partition[v]==1) lykan++;
                if(partition[v]==2) vampire++;
                //cout<<u<<"\t"<<v<<"\t"<<partition[v]<<"\tlykan "<<lykan<<"\tvampire "<<vampire<<endl;
                Q.push(v);
            }
        }
    }
    result+=max(lykan,vampire);
}


void bfs ()
{
    for(int i=0;i<MAX;i++)
    {
        color[i]=0;
        partition[i]=0;
        check[i]=0;
    }
    for(int i=1;i<MAX;i++)
    {
        if(color[i]==0)
            bfsVisit(i);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int testCase,caseno=1;
    scanf("%d",&testCase);
    while(testCase--)
    {
        for(int i=0;i<MAX;i++){edges[i].clear();}
        result=0;
        int V,E,u,v,s;
        scanf("%d",&E);
        for(int i=0;i<E;i++)
        {
            scanf("%d %d",&u,&v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        bfs();
        cout<<"Case "<<caseno++<<": "<<result<<endl;
    }
    return 0;
}

