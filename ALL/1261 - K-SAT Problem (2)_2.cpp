#include<iostream>
#define size 100
using namespace std;
int main ()
{
    int check_list[size][size],check_wish[size],ans[size],neg_wish[size];
    int T,t=1,i,j,w,k,n,m,x,p,neg;
    char ch;
    cin>>T;
    while(T--)
    {
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
                {
                    if (check_list[i][x]==-1)
                    {
                        check_list[i][x]=2;
                    }
                    else
                    {
                        check_list[i][x]=1;
                    }
                }
                if (ch == '-')
                {
                    if (check_list[i][x]==1)
                    {
                        check_list[i][x]=2;
                    }
                    else if (check_list[i][x]==0)
                    {
                        neg_wish[i]++;
                        check_list[i][x]=-1;
                    }
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
        if (p == 0)
        {
            j=1;
            for(i=1;i<=n;i++)
            {
                if(neg_wish[i]==0)
                {
                    j=0;
                    break;
                }
            }
            if(j==1)
                cout<<"Case "<<t++<<": Yes"<<endl;
            else
                cout<<"Case "<<t++<<": No"<<endl;
        }
        else
        {
            for (i=1;i<=p;i++)
            {
                cin>>ans[i];
            }
            for (i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)
                {
                    if(check_list[i][j]==2)
                    {
                        check_wish[i]=1;
                        break;
                    }
                }
            }
            neg = 0;
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
                        for (k=1;k<=p;k++)
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
    /*
            for (i=1;i<=n;i++)
            {
                cout<<check_wish[i]<<" ";
            }
            cout<<endl;
            for (i=1;i<=n;i++)
            {
                cout<<neg_wish[i]<<" ";
            }
            cout<<endl;
            for (i=1;i<=n;i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
    */
            if(j==n)
                cout<<"Case "<<t++<<": Yes"<<endl;
            else
                cout<<"Case "<<t++<<": No"<<endl;
        }
    }
    return 0;
}

