#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<cstring>
using namespace std;
#define SIZE 100003

int value=0;
class BST
{
public:
    char A[SIZE];
    int val[SIZE*3];
    int n;
    BST(char arr[], int len)
    {
        n = len;
        memset(&val,0,sizeof(val));
        for(int i=0;i<n;i++)
        {
            A[i+1]=arr[i];
        }
    }
    void update(int index, int b,int e,int i,int j)
    {
        if(i>e || j<b) return;
        if(i<=b && j>=e)    val[index]++;
        else
        {
            int left = 2*index;
            int right = 2*index+1;
            int mid = (b+e)/2;
            update(left,b,mid,i,j);
            update(right,mid+1,e,i,j);
        }
    }

    void query(int index, int b,int e, int i)
    {
        if(b==e and b==i)
        {
            value=index;
            return;
        }
        if(b==e and b!=i) return;
        if(i>=b && i<=e)
        {
            int left = 2*index;
            int right = 2*index+1;
            int mid = (b+e)/2;
            query(left,b,mid,i);
            query(right,mid+1,e,i);
            return;
        }
    }
    int query2()
    {
        int k=0;
        for(int i=value;i>=1;i/=2)
        {
            k+=val[i];
        }
        return k;
    }
    void show()
    {
        for(int i=1;i<=2*n+1;i++)
        {
            cout<<i<<" = "<<val[i]<<"\t";
        }
    }
};
int main()
{

    freopen("input.txt","r",stdin);
    int testCases, cases=1;
    char A[SIZE],ch[2];
    scanf("%d",&testCases);
    while(testCases--)
    {
        int n,q;
        scanf("%s",A);
        n = strlen(A);
        scanf("%d",&q);
        BST bst(A,n);
        printf("Case %d:\n",cases++);
        for(int i=0;i<q;i++)
        {
            scanf("%s",ch);
            if(ch[0]=='I')
            {
                int a1,a2;
                scanf("%d %d",&a1,&a2);
                bst.update(1,1,n,a1,a2);
            }
            if(ch[0]=='Q')
            {
                int a1;
                scanf("%d",&a1);
                bst.query(1,1,n,a1);
                int gf=bst.query2();
                if(gf%2==0) printf("%c\n",A[a1-1]);
                else
                {
                    if(A[a1-1]=='0')    printf("1\n");
                    else printf("0\n");
                }

            }
        }
    }
    return 0;
}
