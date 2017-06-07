#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int testCase=0,cases=0;
    scanf("%d",&testCase);
    while(testCase--)
    {
        int k,n,ans=0;
        scanf("%d",&k);
        if(k>1)
        {
            while(k--)
            {
                scanf("%d",&n);
                ans=ans^n;
//                cout<<ans<<endl;
            }
            if(ans==0)
                printf("Case %d: Bob\n",++cases);
            else
                printf("Case %d: Alice\n",++cases);
        }
        else
        {
            scanf("%d",&n);
            if(n==1)
                printf("Case %d: Bob\n",++cases);
            else
                printf("Case %d: Alice\n",++cases);
        }
    }
    return 0;
}
