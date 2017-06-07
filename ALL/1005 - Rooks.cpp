#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    long long int testCases, caseNo=1,n,k;
    scanf("%lld",&testCases);
    while(testCases--)
    {
        long long int result=1,f=1,r,i;
        scanf("%lld %lld",&n,&k);
        for(i=n-k+1;i<=n;i++)
        {
            result*=i;
        }
        for(i=1;i<=k;i++)
        {
            result/=i;
        }
        for(i=n-k+1;i<=n;i++)
        {
            result*=i;
        }
//        cout<<i<<"\t"<<r<<endl;
        printf("Case %lld: %lld\n",caseNo++,result);

    }
    return 0;
}
