#include<iostream>
#include<cstring>
#define size 10
using namespace std;
class queue
{
    int array[size];
    int index;
    int right;
    int left;
    int count;
    int right_count;
    int left_count;
    int right_pop;
    int left_pop;
public:
    queue(int n)
    {
        index = n;
        left = 0;
        right = n-1;
        count = 0;
        right_count = 0;
        left_count = 0;
        for(int i=0;i<index;i++)
        {
            array[i]=2011;
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
            for(int i = right - right_count ; i < right ; i++)
            {
                array[i]=array[i+1];
            }
            array[right] = a;
            cout<<"Pushed in right: "<<array[right]<<endl;
            count++;
            right_count++;
        }
        cout<<endl;
        for(int i=0;i<index;i++)
            cout<<array[i]<<" ";
        cout<<endl;
    }
    void push_left (int a)
    {
        if(count == index)
        {
            cout<<"The queue is full"<<endl;
        }
        else
        {
            for(int i = left_count ; i > left ; i--)
            {
                array[i]=array[i-1];
            }
            array[left] = a;
            cout<<"Pushed in left: "<<array[left]<<endl;
            count++;
            left_count++;
        }
        cout<<endl;
        for(int i=0;i<index;i++)
            cout<<array[i]<<" ";
        cout<<endl;
    }
    void pop_right (void)
    {
        if(count==0)
        {
            cout<<"The queue is empty"<<endl;
        }
        else
        {
            for( right_pop = index-1;;right_pop--)
            {
                if(array[right_pop] >= -100 && array[right_pop] <= 100)
                    break;
            }
            cout<<"Popped from right: "<<array[right_pop]<<endl;
            right_count--;
            if(right_count<0)
            {
                right_count = 0;
            }
            array[right_pop]=2011;
            if(right_pop == index-1)
            {
                int i,j;
                for( i=right_pop,j=0;j<right_count;j++,i--)
                {
                    array[i]=array[i-1];
                }
                array[i]=2011;
            }
            count--;
        }
        cout<<endl;
        for(int i=0;i<index;i++)
            cout<<array[i]<<" ";
        cout<<endl;
    }
    void pop_left (void)
    {
        if(count==0)
        {
            cout<<"The queue is empty"<<endl;
        }
        else
        {
            for( left_pop = 0;;left_pop++)
            {
                if(array[left_pop] >= -100 && array[left_pop] <= 100)
                    break;
            }
            cout<<"Popped from left: "<<array[left_pop]<<endl;
            left_count--;
            if (left_count<0)
            {
                left_count=0;
            }
            array[left_pop]=2011;
            if(left_pop == 0)
            {
                int i,j;
                for( i=left_pop,j=0;j<left_count;j++,i++)
                {
                    array[i]=array[i+1];
                }
                array[i]=2011;
            }
            count--;
        }
        cout<<endl;
        for(int i=0;i<index;i++)
            cout<<array[i]<<" ";
        cout<<endl;
    }
    void show (void)
    {
        cout<<"\ncount\t\t"<<count;
        cout<<"\nright_count\t"<<right_count;
        cout<<"\nleft_count\t"<<left_count;
        cout<<"\nright_pop\t"<<right_pop;
        cout<<"\nleft_pop\t"<<left_pop;
        cout<<endl;
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
            Q.show();
        }
    }
    return 0;
}
