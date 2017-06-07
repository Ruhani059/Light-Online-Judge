#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<set>
#define size 100000001
using namespace std;
unsigned int lcm_to_n[size];
unsigned int gcd (unsigned int a, unsigned int b);
unsigned int lcm (unsigned int a, unsigned int b);
int main ()
{
    unsigned int i,j,k,l=1,N;
    lcm_to_n[0]=1;
    lcm_to_n[2]=2;
    for(i=2;i < size;i++)
    {
        l = lcm(l,i);
        lcm_to_n[i]=l;
    }
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        printf("Case %d: %llu\n",t++,lcm_to_n[N]);
    }
    return 0;
}
unsigned int gcd (unsigned int a, unsigned int b)
{
    if (b==0)
        return a;
    else
        return gcd (b,a%b);
}
unsigned int lcm (unsigned int a, unsigned int b){
    return (a*b)/gcd(a,b);
}
