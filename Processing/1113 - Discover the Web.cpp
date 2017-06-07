#include<iostream>
#include<cstring>
#define size 51
#define max 101
using namespace std;
class queue
{
    char url[max][size];
    int index;
    int current;
public:
    queue()
    {
        int i;
        char s[size]={"http://www.lightoj.com/\0"};
        for(i=0;i<strlen(s);i++)
        {
            url[0][i]=s[i];
        }
        url[0][i]='\0';
        index=0;
        current=index;
    }
    void back (void)
    {
        if(index==0)
            cout<<"Ignored"<<endl;
        else
        {
            index--;
            cout<<url[index]<<endl;
        }
    }
    void forward (void)
    {
        if(index==current)
            cout<<"Ignored"<<endl;
        else
        {
            index++;
            cout<<url[index]<<endl;
        }
    }
    void visit (char str[],int len)
    {
        index++;
        int i;
        for(i=0;i<len;i++)
        {
            url[index][i]=str[i];
        }
        url[index][i]='\0';
        cout<<url[index]<<endl;
        current=index;
    }
};
int main ()
{
    int T,t=1;
    cin>>T;
    while(T--)
    {
        cout<<"Case "<<t++<<":"<<endl;
        queue Q;
        char command[10];
        cin>>command;
        while( strcmp(command,"QUIT") )
        {
            if( !strcmp(command,"BACK") )
            {
                Q.back();
            }
            else if( !strcmp(command,"FORWARD") )
            {
                Q.forward();
            }
            else if( !strcmp(command,"VISIT") )
            {
                char str[size];
                int len;
                cin>>str;
                len = strlen(str);
                Q.visit(str,len);
            }
            cin>>command;
            command[strlen(command)]='\0';
        }
    }
    return 0;
}
