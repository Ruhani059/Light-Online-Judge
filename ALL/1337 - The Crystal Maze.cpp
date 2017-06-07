#include<cstdio>
#include<cstdlib>
#include<queue>
#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;
#define MAX 510

struct node
{
    int i,j;
    node(int a,int b){i=a;j=b;}
};

char Graph[MAX][MAX];
queue<int>Q1;
int color[MAX][MAX];
int d[MAX][MAX];
int p[MAX][MAX];
int count=0;
int dirX[]={0,0,-1,1};
int dirY[]={1,-1,0,0};
stack<node>S;

void bfs(queue<int>Q,int V,int E)
{
    while(!Q.empty())
    {
        int i = Q.front();  Q.pop();
        int j = Q.front();  Q.pop();
        color[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int x = i+dirX[k];
            int y = j+dirY[k];
            if( (x>0 && x<=V) && (y>0 && y<=E) && Graph[x][y]!='#' && color[x][y]==0)
            {
                color[x][y]=1;
                node temp(x,y);
                S.push(temp);
                if(Graph[x][y]=='C')    count++;
                Q.push(x);  Q.push(y);
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
        memset(Graph,'\0',sizeof(Graph));   memset(color,0,sizeof(color));  memset(d,0,sizeof(d));  memset(p,0,sizeof(p));

        int V,E,k;
        scanf("%d %d %d",&V,&E,&k);
        for(int i=1;i<=V;i++)
            for(int j=1;j<=E;j++)
                scanf(" %c",&Graph[i][j]);
//                cin>>Graph[i][j];

        printf("Case %d:\n",caseno++);
        for(int i=0;i<k;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            Q1.push(u); Q1.push(v);
            if(p[u][v]==1)
                printf("%d\n",d[u][v]);
            else
            {
                node temp(u,v);
                S.push(temp);
                bfs(Q1,V,E);
                while(!S.empty())
                {
                    node temp1= S.top();    S.pop();
                    p[temp1.i][temp1.j]=1;
                    d[temp1.i][temp1.j]=count;
                }
                printf("%d\n",d[u][v]);
                count=0;
            }
            while(!Q1.empty()){Q1.pop();Q1.pop();}
        }
    }
    return 0;
}
