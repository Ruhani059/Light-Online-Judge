#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define MAX 1000002
int pi[MAX];
void copute_prifix_function(int m,char P[])
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

int kmp_matcher(int n,int m, char T[],char P[])
{
    int k=0;
    copute_prifix_function(m,P);
    int q = 0;
    for(int i=1;i<=n;i++)
    {
        while(q>0 && P[q+1]!=T[i])
            q=pi[q];
        if(P[q+1]==T[i])
            q=q+1;
        if(q==m)
        {
            k++;
//            cout<<"Pattern Occurs in "<<i-m<<" to "<<i<<endl;
            q=pi[q];
        }
    }
    return k;

}

int main()
{
    freopen("input.txt","r",stdin);
    int testCases;
    string  P,T;
    cin>>testCases;
    for(int cases=1;cases<=testCases;cases++)
    {
        cin>>T>>P;
        int i=0;
        int n = T.length();
        int m = P.length();
        char A[n+1], B[m+1];
        for(i=0;i<n;i++)
            A[i+1]=T[i];
        A[i+1]='\0';
        for(i=0;i<m;i++)
            B[i+1]=P[i];
        B[i+1]='\0';

        cout<<"Case "<<cases<<": "<<kmp_matcher(n,m,A,B)<<endl;
    }
    return 0;
}
