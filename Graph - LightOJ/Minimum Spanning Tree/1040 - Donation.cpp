#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define MAX 100

struct weight
{
    int u,v,w;
    weight(int a,int b,int c){u=a;v=b;w=c;}
};
vector<weight>vv[MAX];

int color[MAX];
int d[MAX];
int p[MAX];

struct node
{
    int u,w;
    node(int a,int b){u=a;w=b;}
    bool operator < ( const node &p ) const{return w > p.w;}
};

void MST_prim(int V,int s)
{
    priority_queue<node>Q;
    for(int i=1;i<=V;i++){color[i]=0;d[i]=99999;p[i]=-1;} //initialization

    color[s]=1;d[s]=0;p[s]=NULL;
    Q.push( node ( s , d[s] ) );

    while(!Q.empty())
    {
        node top = Q.top();Q.pop();
        int u = top.u;
        color[u]=1;
        for(int i=0;i<vv[u].size();i++)
        {
            weight temp=vv[u][i];
            int v=temp.v;
            if( color[v]==0 && d[v] > temp.w)
            {
                d[v]=temp.w;
                p[v]=u;
                Q.push( node ( v , d[v] ) );
            }
        }
    }
}

int main ()
{
    freopen("prim's_MST.txt","r",stdin);
    int testCases,caseNo=1;
    cin>>testCases;
    while(testCases--)
    {
        int V,E,u,v,w,total_weight=0;
        cin>>V;
        for(int i=0;i<MAX;i++){vv[i].clear();}              //clear vector
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                cin>>w;
                if(w!=0){
                    total_weight+=w;
                    weight temp1(i,j,w);
                    weight temp2(j,i,w);
                    vv[i].push_back(temp1);
                    vv[j].push_back(temp2);
                }
            }
        }
        MST_prim(V,1);
        int check = 1;
        for(int i=1;i<=V;i++){if(color[i]==0){check = 0;break;}}    //checking connectivity
        if(check==0){cout<<"Case "<<caseNo++<<": -1\n";}            //impossible
        else{                                                                                        //minimum sum
            int sum=0;
            for(int i=1;i<=V;i++){sum+=d[i];}
            cout<<"Case "<<caseNo++<<": "<<total_weight-sum<<endl;
        }
    }
    return 0;
}
