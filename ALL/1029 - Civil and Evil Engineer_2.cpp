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
#define MAX 110

struct weight
{
    int u,v,w;
    weight(int a,int b,int c){u=a;v=b;w=c;}
};

vector<weight>vv[MAX];

int color[MAX];
int d[MAX];
int p[MAX];

struct min_pq
{
    int u,w;
    min_pq(int a,int b){u=a;w=b;}
    bool operator < ( const min_pq &p ) const{return w > p.w;}
};

struct max_pq
{
    int u,w;
    max_pq(int a,int b){u=a;w=b;}
    bool operator < ( const max_pq &p ) const{return w < p.w;}
};

void MST_prim(int V,int s)
{
    priority_queue<min_pq>Q;
    for(int i=0;i<=V;i++){color[i]=0;d[i]=99999;p[i]=-1;} //initialization

    color[s]=1;d[s]=0;p[s]=NULL;
    Q.push( min_pq ( s , d[s] ) );

    while(!Q.empty())
    {
        min_pq top = Q.top();Q.pop();
        int u = top.u;
        color[u]=1;
//        cout<<"u \t=\t"<<u<<endl;
        for(int i=0;i<vv[u].size();i++)
        {
            weight temp1=vv[u][i];
            int v=temp1.v;
    //        cout<<u<<"\t"<<v<<"\t="<<temp1.w<<endl;
            if( color[v]==0 && d[v] > temp1.w)
            {
                d[v]=temp1.w;
                p[v]=u;
                Q.push( min_pq ( v , d[v] ) );
//                cout<<u<<"\t"<<v<<"\t=\t"<<temp1.w<<endl;
            }
        }
    }
}
void LST_prim(int V,int s)
{
    priority_queue<max_pq>Q;
    for(int i=0;i<=V;i++){color[i]=0;d[i]=-99999;p[i]=-1;} //initialization

    color[s]=1;d[s]=0;p[s]=NULL;
    Q.push( max_pq ( s , d[s] ) );

    while(!Q.empty())
    {
        max_pq top = Q.top();Q.pop();
        int u = top.u;
        color[u]=1;
//        cout<<"u \t=\t"<<u<<endl;
        for(int i=0;i<vv[u].size();i++)
        {
            weight temp1=vv[u][i];
            int v=temp1.v;
    //        cout<<u<<"\t"<<v<<"\t="<<temp1.w<<endl;
            if( color[v]==0 && d[v] < temp1.w)
            {
                d[v]=temp1.w;
                p[v]=u;
                Q.push( max_pq ( v , d[v] ) );
        //        cout<<u<<"\t"<<v<<"\t=\t"<<temp1.w<<endl;
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
        while(1)
        {
            cin>>u>>v>>w;
            if(u==0 && v==0 && w==0) break;
            weight temp1(u,v,w);
            weight temp2(v,u,w);
            vv[u].push_back(temp1);
            vv[v].push_back(temp2);
        }
        for(int j=0;j<=V;j++)
        {
            for(int i=0;i<vv[j].size();i++)
            {
                weight temp = vv[j][i];
//                cout<<temp.u<<"\t"<<temp.v<<" = \t"<<temp.w<<"\t"<<endl;
            }
        }

        MST_prim(V,0);
        int sum=0;
        for(int i=0;i<=V;i++){sum+=d[i];}
        LST_prim(V,0);
        for(int i=0;i<=V;i++){sum+=d[i];}
        //int check = 1;
        //for(int i=1;i<=V;i++){if(color[i]==0){check = 0;break;}}    //checking connectivity
        //if(check==0){cout<<"Case "<<caseNo++<<": -1\n";}            //impossible
        //else{                                                                                        //minimum sum
        if(sum%2!=0)
            cout<<"Case "<<caseNo++<<": "<<sum<<"/2"<<endl;
        else
            cout<<"Case "<<caseNo++<<": "<<sum/2<<endl;
        //}
    }
    return 0;
}
