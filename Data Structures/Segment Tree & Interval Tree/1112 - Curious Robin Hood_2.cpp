#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
#define SIZE 100003

class BIT
{
public:
    int A[SIZE];
    int T[SIZE];
    int n;
    BIT(int len)
    {
        n = len;
        memset(&A,0,sizeof(A));
        memset(&T,0,sizeof(T));
    }

    int query(int idx)
    {
        int sum=0;
        while(idx>0)
        {
            sum+=T[idx];
            idx-=idx & (-idx);
        }
        return sum;
    }

    void update(int idx, int x)
    {
        while(idx<=n)
        {
            T[idx] += x;
            idx+=idx & (-idx);
        }
    }

    void show()
    {
        cout<<"\nA : ";
        for(int i=1;i<=n;i++)
            cout<<A[i]<<"\t";
        cout<<"\nT : \n";
        for(int i=1;i<=n;i++)
            cout<<T[i]<<"\t";
        cout<<"\n\n";
    }

};

int main()
{
    freopen("input.txt","r",stdin);
    int testCases, cases=1;
    scanf("%d",&testCases);
    while(testCases--)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        BIT bit(n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&bit.A[i]);
            bit.update(i,bit.A[i]);
        }
        printf("Case %d:\n",cases++);
        for(int i=0;i<q;i++)
        {
            int command;
            scanf("%d",&command);
            if(command==1)
            {
                int a;
                scanf("%d",&a);
                printf("%d\n",bit.A[a+1]);
                bit.update(a+1,-bit.A[a+1]);
                bit.A[a+1]=0;
            }
            else if(command==2)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                bit.update(a+1,b);
                bit.A[a+1]+=b;
            }
            else if(command==3)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                printf("%d\n",bit.query(b+1)-bit.query(a));
            }
        }

    }
    return 0;
}
