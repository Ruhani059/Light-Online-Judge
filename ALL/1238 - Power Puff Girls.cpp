#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<queue>
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
#define MAX 25

char Graph[MAX][MAX];
queue<int>Q1;
queue<int>Q2;
queue<int>Q3;
int color[MAX][MAX];
int d[MAX][MAX];
int count=0;
int dirX[]={0,0,-1,1};
int dirY[]={1,-1,0,0};

int bfs (queue<int>Q,int V,int E)
{
    memset(color,0,sizeof(color));
    memset(d,0,sizeof(d));
    while(!Q.empty())
    {
        int i = Q.front();  Q.pop();
        int j = Q.front();  Q.pop();
        color[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int x = i+dirX[k];
            int y = j+dirY[k];
            if( (x>=0 && x<V) && (y>=0 && y<E) && (Graph[x][y]!='m' && Graph[x][y]!='#' ) && color[x][y]==0)
            {
                color[x][y]=1;
                d[x][y] = d[i][j] + 1;
                if(Graph[x][y]=='h')
                    return d[x][y];
                Q.push(x);  Q.push(y);
            }
        }
    }
}

int main()
{
    freopen("1238 - Power Puff Girls.txt","r",stdin);
    int testCase,caseno=1;
    cin>>testCase;
    while(testCase--)
    {
        memset(Graph,'\0',sizeof(Graph));

        int V,E,source;
        cin>>V>>E;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<E;j++)
            {
                cin>>Graph[i][j];
                if(Graph[i][j]=='a')    {Q1.push(i); Q1.push(j);}
                if(Graph[i][j]=='b')    {Q2.push(i); Q2.push(j);}
                if(Graph[i][j]=='c')    {Q3.push(i); Q3.push(j);}
            }
        }
        int result = bfs(Q1,V,E);
        result = max(result,bfs(Q2,V,E));
        result = max(result,bfs(Q3,V,E));

        cout<<"Case "<<caseno++<<": "<<result<<endl;
        Q1.pop();Q1.pop();Q2.pop();Q2.pop();Q3.pop();Q3.pop();
    }
    return 0;
}
