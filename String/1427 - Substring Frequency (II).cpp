#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define MAX 1000001
int pi[MAX];

void compute_prefix_function (string P)
{
    int i=1, k=-1;
    pi[0] = -1;

    for (int q = 1; q < P.size(); q++) {
        while (k > -1 && P[k+1] != P[q]) {
            k = pi[k];
        }
        if( P[k+1] == P[q] )
        {
            k++;
        }
        pi[q] = k;
    }
//        for (int ll = 0; ll < pi.length; ll++) {System.out.print(pi[ll]+" ");}System.out.println("");
}

int kmp_matcher(string T, string P) {
    int knt = 0;
    int n = T.size(), m = P.size(), q=-1;
    compute_prefix_function(P);

    for (int i = 0; i < n; i++) {
//            System.out.println(i+"\t"+T.charAt(i)+"\t"+q+"\t");
        while (q > -1 && P[q+1] != T[i]) {
            q = pi[q];
        }
        if( P[q+1] == T[i] )
        {
            q++;
        }
        if(q == m-1)
        {
            knt++;
            q = pi[q];
        }
    }
    return knt;
}

int main()
{
//    freopen("input.txt","r",stdin);
    int tCases = 0;
    scanf("%d",&tCases);
    for(int i=1; i<=tCases; i++)
    {
//        memset(pi,-1,sizeof(pi));
        int nCase;
        scanf("%d",&nCase);

        char Tchar [MAX];
        scanf("%s",Tchar);
        string  PString,TString;
        TString = Tchar;
        printf("Case %d:\n",i);
        for(int ll=0;ll<nCase;ll++)
        {
            char Pchar [MAX];
            scanf("%s",Pchar);
            PString = Pchar;
            printf("%d\n",kmp_matcher(TString,PString));
        }

    }
    return 0;
}
