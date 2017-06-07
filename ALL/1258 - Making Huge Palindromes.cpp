#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define MAX 1000
int pi[MAX];

void compute_prifix_function(int m,char P[])
{
    pi[1]=0;
    int k = 0;
    for(int q=2;q<=m;q++)
    {
        while(k>0 && P[k+1]!=P[q])
            k=pi[k];
        if(P[k+1]==P[q])
            k=k+1;
        pi[q]=k;
    }
}

void kmp_matcher(int n,int m, char T[],char P[])
{
    compute_prifix_function(m,P);
    int q = 0;
    for(int i=1;i<=n;i++)
    {
        while(q>0 && P[q+1]!=T[i])
            q=pi[q];
        if(P[q+1]==T[i])
            q=q+1;
        if(q==m)
        {
            cout<<"Pattern Occurs in "<<i-m<<" to "<<i<<endl;
            q=pi[q];
        }
    }

}

int main()
{
    freopen("input.txt","r",stdin);
    string  P,T;
    while(cin>>T)
    {
        int i=0,j=0;
        int m,n = T.length();
        m=2*n;
        char A[m+1];
        for(i=0;i<n;i++)
            A[i+1]=T[i];

        for(j=n-2;j>=0;i++,j--)
            A[i+1]=T[j];

        A[m]='\0';

        for(int i=1;i<m;i++)
            cout<<A[i];
//        B[i+1]='\0';
        cout<<endl;

//        cout<<T<<endl<<"Length = "<<n<<endl;
        compute_prifix_function(m,A);
//        kmp_matcher(n,m,A,B);

        for(int i=1;i<=m;i++)
            cout<<pi[i]<<" ";
        cout<<endl;
    }
    return 0;
}
