#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    long long int testCases,caseNo=1;
    char A[1000000],B[1000000];
    while((cin>>A>>B))
    {
        int i=0,j=0,count=0,len=0;
        while(A[len]!='\0') len++;

        while(A[i]!='\0' && B[j]!='\0')
        {
            if(B[j]==A[i])
            {
                count++;
                i++;
                j++;
            }
            else
                j++;
        }
        if(count==len)  cout<<"Yes\n";

        else    cout<<"No\n";
    }
    return 0;
}

