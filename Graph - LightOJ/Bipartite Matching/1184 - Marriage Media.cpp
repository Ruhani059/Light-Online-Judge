#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 105

struct node1
{
    int no,h,a,m,status;
    bool operator < ( const node1 &p ) const{return a < p.a;}
  //  node1(int x,int b,int c) {h=x;a=b;m=c;status = 0;}
};
struct node2
{
    int no,h,a,m,status;
    bool operator < ( const node1 &p ) const{return h < p.h;}
  //  node1(int x,int b,int c) {h=x;a=b;m=c;status = 0;}
};
node1 vertex1[MAX];
node2 vertex2[MAX];
vector<node1>tempNode;
vector<node1>G1[MAX];
vector<node2>G2[MAX];
map<int,node1>my_map1;
map<int,node2>my_map2;
int k=0;

int mod(int a)
{
    if(a<0) return -a;
    else return a;
}

void bfsVisit (int u)
{
    vertex1[u];
    for(int i=1;i<G1[u].size();i++)
    {
        node1 temp = G1[u][i];
        int v = temp.no;
        if(vertex1[v].status==0 && vertex1[u].status==0)
        {
            if(vertex1[u].m==vertex1[v].m &&  mod(vertex1[u].h-vertex1[v].h)<=12 && mod(vertex1[u].a-vertex1[v].a)<=5 )
            {
                cout<<u<<" and "<<v<<" = \t"<<vertex1[u].a-vertex1[v].a<<"\t";
                k++;
                vertex1[u].status =1;
                vertex1[v].status = 1;
            }
        }
    }

}

void bfs(int V,int E)
{
    for(int i=V+1;i<=V+E;i++)
    {
        if(vertex1[i].status==0)
        {
            bfsVisit(i);
        }
    }
    for(int i=1;i<=V;i++)
    {
        if(vertex1[i].status==0)
        {
            bfsVisit(i);
        }
    }

}

int main()
{
   // freopen("input.txt","r",stdin);
    int testCase,caseno=1;
    scanf("%d",&testCase);
    while(testCase--)
    {
        k=0;
        for(int i=0;i<MAX;i++)
        {
            G1[i].clear();
        }
        my_map1.clear();

        int i,j,V,E,u,v,w;
        scanf("%d %d",&V,&E);
        for(i=1;i<=V;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            vertex1[i].h=u;  vertex1[i].a=v;  vertex1[i].m=w;  vertex1[i].status=0; vertex1[i].no=i;
            my_map1[i]=vertex1[i];
            tempNode.push_back(my_map1[i]);
//           G2[i].push_back(my_map1[i]);
        }
        sort(tempNode.begin(),tempNode.end());
        for(i=1;i<=V;i++)
        {
            G1[i].push_back(tempNode.at(i-1));
        }
        tempNode.clear();

        for(;i<=E+V;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            vertex1[i].h=u;  vertex1[i].a=v;  vertex1[i].m=w;  vertex1[i].status=0; vertex1[i].no=i;
            my_map1[i]=vertex1[i];
            tempNode.push_back(my_map1[i]);
//            G2[i].push_back(my_map1[i]);
        }
        sort(tempNode.begin(),tempNode.end());
        for(int i=V+1,j=0;i<=V+E;i++,j++)
        {
            G1[i].push_back(tempNode.at(j));
        }
        tempNode.clear();

  //      sort(vertex1[1].a,vertex1[V+E].a);
        for(i=1;i<=V;i++)
        {
            for(j=V+1;j<=V+E;j++)
            {
                if(vertex1[i].m==vertex1[j].m)
                {
                    G1[i].push_back(my_map1[j]);
                    G1[j].push_back(my_map1[i]);
                }
            }
        }
        for(i=1;i<=V+E;i++)
        {
            sort(G1[i].begin()+1,G1[i].end());
        }
        for(i=1;i<=V+E;i++)
        {
            cout<<i<<" :\t";
            for(j=0;j<G1[i].size();j++)
            {
                node1 temp= G1[i][j];
                cout<<temp.no<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
        bfs(V,E);
    //    int k = 0;
        for(int i=1;i<=V+E;i++)
        {
            if(vertex1[i].status==1)
            {
//                k++;
            }
        }
        /*
        for(int i=0;i<V;i++){cout<<i<<"  : ";for(int j=0;j<G[i].size();j++){cout<<G[i][j]<<" ";}cout<<endl;}cout<<endl;
        */
        printf("Case %d: %d\n",caseno++,k);
    }
    return 0;
}
