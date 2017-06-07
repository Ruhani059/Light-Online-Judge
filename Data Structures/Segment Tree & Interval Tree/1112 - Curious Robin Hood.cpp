
#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
#define SIZE 100003

int indexValue=-222;
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
            T[index]=T[left]+T[right];
        }
    }

    int query(int index, int b,int e, int i, int j)
    {
        if(e<i || j<b) return 0;
        if(i<=b && e<=j) return T[index];
        else
        {
            int left = 2*index;
            int right = 2*index+1;
            int mid = (b+e)/2;
            int min1 = query(left,b,mid,i,j);
            int min2 = query(right,mid+1,e,i,j);
            return min1 + min2;
        }
    }

    void update(int index, int b,int e, int i, int newVal)
    {
        if(i>e || i<b)
            return;
        if(b==i && i==e)
        {
            if(newVal==0)
            {
                indexValue=T[index];
                T[index]=0;
            }
            else T[index]+=newVal;
            return;
        }
        int left = 2*index;
        int right = 2*index+1;
        int mid = (b+e)/2;
        update(left,b,mid,i,newVal);
        update(right,mid+1,e,i,newVal);
        T[index]=T[left]+T[right];
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
        BST bst(A,n);
        bst.init(1,1,n);
        printf("Case %d:\n",cases++);
        for(int i=0;i<q;i++)
        {
            int command;
            scanf("%d",&command);
            if(command==1)
            {
                int a;
                scanf("%d",&a);
                bst.update(1,1,n,a+1,0);
                printf("%d\n",indexValue);
            }
            else if(command==2)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                bst.update(1,1,n,a+1,b);
            }
            else if(command==3)
            {
                int a,b;
                scanf("%d %d",&a,&b);
                printf("%d\n",bst.query(1,1,n,a+1,b+1));
            }
        }
    }
    return 0;
}
