#include<iostream>
#define size 31
using namespace std;
int main ()
{
    int T,t=1;
    cin>>T;
    while(T--)
    {
        int check_list[size][size],check_wish[size],ans[size],neg_wish[size];
        int i,j,w,k,n,m,x,p,neg=0;
        char ch;
        for (i=0;i<size;i++)
        {
            check_wish[i]=0;
            ans[i]=0;
            neg_wish[i]=0;
        }
        for (i=0;i<size;i++)
            for(j=0;j<size;j++)
                check_list[i][j]=0;
        cin>>n>>m>>w;
        for (i=1;i<=n;i++)
        {
            for(j=1;j<=w;j++)
            {
                cin>>ch>>x;
                if (ch == '+')
                    check_list[i][x]=1;
                if (ch == '-')
                {
                    neg_wish[i]++;
                    check_list[i][x]=-1;
                }
            }
        }
/*
        for (i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cout<<check_list[i][j]<<" ";
            }
            cout<<endl;
        }
*/
        cin>>p;
        for (i=1;i<=p;i++)
        {
            cin>>ans[i];
        }
        for (i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(check_list[i][j]==-1)
                {
                    for (k=1;k<=p;k++)
                    {
                        if( ans[k] == j )
                        {
                            neg++;
                            break;
                        }
                    }
                }
                if(check_list[i][j]==1)
                {
                    for (k=1;i<=p;k++)
                    {
                        if( ans[k] == j )
                        {
                            check_wish[i]=1;
                            break;
                        }
                    }

                }
                if( check_wish[i]==1)
                    break;
            }
            if (neg != neg_wish[i])
            {
                check_wish[i]=1;
            }
        }
        j=0;
        for (i=1;i<=n;i++)
        {
            if(check_wish[i]==1)
                j++;
        }
        if(j==n)
            cout<<"Case "<<t++<<": Yes"<<endl;
        else
            cout<<"Case "<<t++<<": No"<<endl;
    }
    return 0;
}
