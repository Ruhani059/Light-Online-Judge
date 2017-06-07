#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define MAX 25

vector<int>G[MAX];
char Graph[MAX][MAX];
queue<int>Q;
int color[MAX][MAX];
int d[MAX];
int count=0;
int dirX[]={0,0,-1,1};
int dirY[]={1,-1,0,0};

int bfs (int V,int E)
{
    int count=1;
    memset(color,0,sizeof(color));
    while(!Q.empty())
    {
        int i = Q.front();  Q.pop();
        int j = Q.front();  Q.pop();
        color[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int x = i+dirX[k];
            int y = j+dirY[k];
            if( (x>=0 && x<V) && (y>=0 && y<E) && Graph[x][y]=='.' && color[x][y]==0)
            {
                color[x][y]=1;
                count++;
                Q.push(x);  Q.push(y);
            }
        }
    }
    return count;
}

int main()
{
    freopen("input.txt","r",stdin);
    int testCase,caseno=1;
    cin>>testCase;
    while(testCase--)
    {
        memset(Graph,NULL,sizeof(Graph));
        for(int i=0;i<MAX;i++)
        {
            G[i].clear();
        }

        int V,E,source;
        cin>>V>>E;
        for(int i=0;i<E;i++)
        {
            for(int j=0;j<V;j++)
            {
                cin>>Graph[i][j];
                if(Graph[i][j]=='@')
                {
                    Q.push(i);
                    Q.push(j);
                }
            }
        }
        cout<<"Case "<<caseno++<<": "<<bfs(E,V)<<endl;
    }
    return 0;
}
