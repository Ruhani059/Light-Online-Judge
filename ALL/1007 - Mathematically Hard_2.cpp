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
#define size 5000001
#define total_prime 348513
using namespace std;
unsigned long long int phi[size];
int number[size];
int main()
{
    unsigned long long int sum=0,count=0;
    int i,j,k,sqrtN;

    for(i=0;i<size;i++)
    {
        count++;
        number[i]=i;
        phi[i]=i;
    }

    for(i=2;i<size;i++)
    {
        count++;
        if(number[i]!=1)
        {
            for(j=i;j<size;j+=i)
            {
                count++;
                while( number[j] % i == 0)
                {
                    count++;
                    number[j]=number[j]/i;
                }
                phi[j]=phi[j]*(i-1)/i;
            }
        }
    }

    phi[1]=0;

    for(i=2;i<size;i++)
    {
        count++;
        sum += phi[i]*phi[i];
        phi[i]=sum;
    }

    cout<<count<<endl;

    int T,t=1;
    cin>>T;
    while(T--)
    {
        int a,b;
        cin>>a>>b;
        printf("Case %d: %llu\n",t++,phi[b]-phi[a-1]);
    }
    return 0;
}
