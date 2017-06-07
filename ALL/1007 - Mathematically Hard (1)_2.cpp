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
#include<ctime>
#define size 5000001
#define total_prime 348513
using namespace std;
unsigned long long int phi[size];
int number[size];
int main()
{
    unsigned long long int sum=0;
    int i,j,k,sqrtN;

    for(i=2;i<size;i++)
    {
        number[i]=1;
        phi[i]=i;
    }

    sqrtN = sqrt (size-1);

    for(i=3;i<=sqrtN;i+=2)
    {
        if(number[i]==1)
        {
            for(j=i*i;j<size;j+=i+i)
            {
                number[j]=0;
            }
        }
    }

    phi[2]=1;

    for(i=3;i<size;i+=2)
    {
        if(number[i]==1)
        {
            phi[i]=i-1;
        }
    }

    for(i=4;i<size;i+=2)
    {
        phi[i]=phi[i]/2;
    }

    for(i=3;i<=size/2;i+=2)
    {
        if(number[i]==1)
        {
            for(j=2*i;j<size;j+=i)
            {
                phi[j]=phi[j]*(i-1)/i;
            }
        }
    }

    phi[1]=0;

    for(i=2;i<size;i++)
    {
        sum += phi[i]*phi[i];
        phi[i]=sum;
    }

    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("Case %d: %llu\n",t++,phi[b]-phi[a-1]);
    }
    return 0;
}
