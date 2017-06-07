#include<cstdio>
#include<cstdlib>
#include<queue>
#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
#define MAX 28

struct node
{
    char ch;    int i,j;
    node(char c,int a,int b){ch=c;i=a;j=b;}
    bool operator < ( const node &p ) const { return ch < p.ch; }
};

char Graph[MAX][MAX];
vector<node>source;
queue<int>Q1;
int color[MAX][MAX];
int d[MAX][MAX];
int dirX[]={0,0,-1,1};
int dirY[]={1,-1,0,0};

int bfs(queue<int>Q,int V,char s)
{
    memset(color,0,sizeof(color));  memset(d,0,sizeof(d));
    while(!Q.empty())
    {
        int i = Q.front();  Q.pop();
        int j = Q.front();  Q.pop();
        color[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int x = i+dirX[k], y = j+dirY[k];
            if( (x>0 && x<=V) && (y>0 && y<=V) && (Graph[x][y]=='.' || (Graph[x][y]>='A' && Graph[x][y]<=s+1) ) && color[x][y]==0)
            {
                color[x][y]=1;
                d[x][y]=d[i][j]+1;
                if(Graph[x][y]==s+1)    return d[x][y];
                Q.push(x);  Q.push(y);
            }
        }
    }
    return -1;
}

int main()
{
    freopen("input.txt","r",stdin);
    int testCase,caseno=1;
    scanf("%d",&testCase);
    while(testCase--)
    {
        memset(Graph,'\0',sizeof(Graph));   source.clear();
        int V,k=0;
        scanf("%d",&V);
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                scanf(" %c",&Graph[i][j]);
                if(Graph[i][j] >= 'A' && Graph[i][j]<='Z')
                {
                    node temp(Graph[i][j],i,j);
                    source.push_back(temp);
                    k++;
                }
            }
        }
        sort(source.begin(),source.end());
        int sum=0,a=0;
        for(int i=0;i<k-1;i++)
        {
            node temp = source.at(i);
            Q1.push(temp.i);    Q1.push(temp.j);
            a = bfs(Q1,V,temp.ch);
            Q1.pop();   Q1.pop();
            if(a==-1)   break;
            sum+=a;
        }
        if(a==-1)   printf("Case %d: Impossible\n",caseno++);
        else    printf("Case %d: %d\n",caseno++,sum);
    }
    return 0;
}
