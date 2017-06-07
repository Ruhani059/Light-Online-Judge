#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define MAX 1000001
int pi[MAX];

void compute_prefix_function (string P)
{
//        System.out.println(P);
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

bool kmp_matcher(string T, string P) {
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
//                System.out.println(i-(m-1));
            return true;
        }
    }
    return false;
}

string rev (string T)
{
    string R;
    R = T.at(T.length()-1);
    for (int i = 1; i < T.length(); i++) {
        R += T.at(T.length()-i-1);
    }
//    cout<<T<<"\t"<<R<<endl;
    return R;
}

int main()
{
    freopen("input.txt","r",stdin);
    int tCases = 0;
    scanf("%d",&tCases);
    for(int i=1; i<=tCases; i++)
    {
//        memset(pi,-1,sizeof(pi));
        char Tchar [MAX];
        scanf("%s",Tchar);
        string  PString,TString;
        TString = Tchar;
        PString = rev(TString);

//        cout<<TString<<"\t"<<rev(TString)<<"\t"<<TString.length()<<"\t"<<PString.size()<<endl;


        if(kmp_matcher(TString,PString))
        {
//                System.out.println("No");
            printf("Case %d: %d\n",i,TString.length());
        }
        else
        {
//                System.out.println("Yes");
            int count = 0;
            bool flag = false;
            for (int j = 0; j < TString.length(); j++)
            {
                if(TString.at(j) == TString.at(TString.length()-1))
                {
                    count ++;
//                        System.out.println("No");
                    int len = ( TString.length() - j ) / 2;
//                    cout<<j<<"\t"<<len<<"\t"<<TString.length()<<"\t"<<TString.length()-len<<endl;
//                    cout<<TString.substr(j, len)<<endl;
//                    cout<< rev(TString.substr(TString.length()-len , len) )<<endl;
//                        System.out.println(j+"\t"+len);
//                        if( kmp_matcher( TString.substring(j, TString.length()), reverse(TString.substring(j, TString.length()))) )
//                    if( len!= 0 && kmp_matcher( TString.substring(j, j+len), reverse(TString.substring(TString.length() - len, TString.length()))) )
//                    if( kmp_matcher( TString.substr(j, TString.length()-j), rev(TString.substr(j, TString.length()-j))) )
                    if( len !=0 && kmp_matcher( TString.substr(j, len), rev(TString.substr(TString.length()-len , len))) )
                    {

//                            int count = j+PString.length();
                        printf("Case %d: %d\n",i,j+TString.length());
                        flag = true;
                        break;
                    }
                }
            }
            if(!flag)
            {
                printf("Case %d: %d\n",i,2*TString.length()+1);
            }
//                System.out.println(count);
        }


    }
    return 0;
}
