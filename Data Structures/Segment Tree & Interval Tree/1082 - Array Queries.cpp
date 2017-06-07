#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
#define SIZE 100003

class BST
{
public:
    int A[SIZE];
    int T[SIZE*3];
    int n;
    BST(int arr[], int len)
    {
        n = len;
        for(int i=0;i<n;i++)
        {
            A[i+1]=arr[i];
        }
    }
    void init(int index, int b, int e)   //b=begin and e=end
    {
        if(b==e) T[index]=A[b];
        else
        {
            int left = 2*index;
            int right = 2*index+1;
            int mid = (b+e)/2;
            init(left,b,mid);
            init(right,mid+1,e);
            T[index]=min(T[left],T[right]);
        }
    }
    int query(int index, int b,int e, int i, int j)
    {
        if(i>e || j<b) return 999999999;
        if(i<=b && j>=e) return T[index];
        else
        {
            int left = 2*index;
            int right = 2*index+1;
            int mid = (b+e)/2;
            int min1 = query(left,b,mid,i,j);
            int min2 = query(right,mid+1,e,i,j);
            return min(min1,min2);
        }
    }
    void show()
    {
        int k=0;
        for(int i=0;i<=n/2;i++)
        {
            for(int j=i;j<=n/2;j++)
            {
                cout<<"  ";
            }
            for(int j=1;j<=pow(2,i);j++)
            {
                cout<<T[++k]<<"   ";
            }
            cout<<"\n\n";
        }
    }
};
int main()
{

//    freopen("input.txt","r",stdin);
    int testCases, cases=1,A[SIZE];
    scanf("%d",&testCases);
    while(testCases--)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
        }
        BST b(A,n);
        b.init(1,1,n);
        printf("Case %d:\n",cases++);
        for(int i=0;i<q;i++)
        {
            int a,c;
            scanf("%d %d",&a,&c);
            printf("%d\n",b.query(1,1,n,a,c));
        }
    }
    return 0;
}
