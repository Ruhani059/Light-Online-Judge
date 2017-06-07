#include<iostream>
#include<cstring>
#define size 100
using namespace std;
class queue
{
    int a_left[size],a_right[size],index,right,left,count,right_pop;
public:
    queue(int n)
    {
        index = n;
        left = 0;
        right = 0;
        count = 0;
        for(int i=0;i<size;i++)
        {
            a_left[i]=2011;
            a_right[i]=2011;
        }
    }
    void push_right (int a)
    {
        if(count == index)
        {
            cout<<"The queue is full"<<endl;
        }
        else
        {
            a_right[right] = a;
            cout<<"Pushed in right: "<<a_right[right]<<endl;
            right++;
            count++;
        }
    }
    void push_left (int a)
    {
        if(count == index)
        {
            cout<<"The queue is full"<<endl;
        }
        else
        {
            a_left[left] = a;
            cout<<"Pushed in left: "<<a_left[left]<<endl;
            left++;
            count++;
        }
    }
    void pop_right (void)
    {
        int check=0;
        if(count==0)
        {
            cout<<"The queue is empty"<<endl;
        }
        else
        {
            for( right_pop = size-1; right_pop >= 0 ; right_pop--)
            {
                if(a_right[right_pop] >= -100 && a_right[right_pop] <= 100)
                {
                    check=1;
                    cout<<"Popped from right: "<<a_right[right_pop]<<endl;
                    a_right[right_pop]=2011;
                    break;
                }
            }
            if(check!=1)
            {
                for( right_pop = 0; right_pop < size ;right_pop++)
                {
                    if(a_left[right_pop] >= -100 && a_left[right_pop] <= 100)
                    {
                        cout<<"Popped from right: "<<a_left[right_pop]<<endl;
                        a_left[right_pop]=2011;
                        break;
                    }
                }
            }
            count--;
        }
    }
    void pop_left (void)
    {
        int check=0;
        if(count==0)
        {
            cout<<"The queue is empty"<<endl;
        }
        else
        {
            for( right_pop = size-1; right_pop >= 0 ;right_pop--)
            {
                if(a_left[right_pop] >= -100 && a_left[right_pop] <= 100)
                {
                    check = 1;
                    cout<<"Popped from left: "<<a_left[right_pop]<<endl;
                    a_left[right_pop]=2011;
                    break;
                }
            }
            if(check!=1)
            {
                for( right_pop = 0; right_pop < size ; right_pop++)
                {
                    if(a_right[right_pop] >= -100 && a_right[right_pop] <= 100)
                    {
                        cout<<"Popped from left: "<<a_right[right_pop]<<endl;
                        a_right[right_pop]=2011;
                        break;
                    }
                }
            }
            count--;
        }
    }
};
int main ()
{
    int T,t=1;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        queue Q(n);
        cout<<"Case "<<t++<<":"<<endl;
        while(m--)
        {
            int a;
            char command[10];
            cin>>command;
            if( !strcmp(command,"pushLeft") )
            {
                cin>>a;
                Q.push_left(a);
            }
            else if( !strcmp(command,"pushRight") )
            {
                cin>>a;
                Q.push_right(a);
            }
            else if( !strcmp(command,"popLeft") )
            {
                Q.pop_left();
            }
            else if( !strcmp(command,"popRight") )
            {
                Q.pop_right();
            }
        }
    }
    return 0;
}
