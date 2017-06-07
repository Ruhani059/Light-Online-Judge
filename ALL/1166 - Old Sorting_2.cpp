#include<bits/stdc++.h>
int main()
{
    int T,i=1;
    scanf("%d",&T);
    while(T--)
    {
        int A[100],n;
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&A[j]);
        }
        int k=0,j=1;
        while(j<=n)
        {
            if(A[j]!=j)
            {
                int temp = A[j];
                A[j]=A[temp];
                A[temp]=temp;
                k++;
            }
            else
            {
                j++;
            }
        }
        printf("Case %d: %d\n",i++,k);
    }
    return 0;
}
