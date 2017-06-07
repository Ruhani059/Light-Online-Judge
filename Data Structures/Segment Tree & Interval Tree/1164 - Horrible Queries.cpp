#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
#define SIZE 100005

class BST
{
public:
    long long int A[SIZE];
    long long int sum[SIZE*3];
    long long int prop[SIZE*3];
    long long int n;
    BST(long long int len)
    {
        n = len;
        for(long long int i=1;i<SIZE;i++) A[i]=0;
        for(long long int i=1;i<SIZE*3;i++)
        {
            sum[i]=0;
            prop[i]=0;
        }
    }
    long long int query(long long int index, long long int b,long long int e, long long int i, long long int j,long long int carry=0)
    {
        if(e<i || j<b) return 0;
        if(i<=b && e<=j) return sum[index]+(e-b+1)*carry;
        long long int left = 2*index;
        long long int right = 2*index+1;
        long long int mid = (b+e)/2;
        long long int min1 = query(left,b,mid,i,j,carry+prop[index]);
        long long int min2 = query(right,mid+1,e,i,j,carry+prop[index]);
        return min1 + min2;
    }

    void update(long long int index, long long int b,long long int e, long long int i, long long int j, long long int newVal)
    {
        if(j<b || e<i)  return;
        if(i<=b && e<=j)
        {
            sum[index]+=(e-b+1)*newVal;
            prop[index]+=newVal;
            return;
        }
        long long int left = 2*index;
        long long int right = 2*index+1;
        long long int mid = (b+e)/2;
        update(left,b,mid,i,j,newVal);
        update(right,mid+1,e,i,j,newVal);
        sum[index]=sum[left]+sum[right] +prop[index]*(e-b+1);
    }
};
int main()
{

//    freopen("input.txt","r",stdin);
    long long int testCases, cases=1;
    scanf("%lld",&testCases);
    while(testCases--)
    {
        long long int n,q;
        scanf("%lld %lld",&n,&q);
        BST bst(n);
        printf("Case %lld:\n",cases++);
        for(long long int i=0;i<q;i++)
        {
            long long int command;
            scanf("%lld",&command);
            if(command==0)
            {
                long long int x,y,v;
                scanf("%lld %lld %lld",&x,&y,&v);
                bst.update(1,1,n,x+1,y+1,v);
//                prlong long intf("%d\n",indexValue);
            }
            else if(command==1)
            {
                long long int x,y;
                scanf("%lld %lld",&x,&y);
                printf("%lld\n",bst.query(1,1,n,x+1,y+1,0));
            }
        }
    }
    return 0;
}
