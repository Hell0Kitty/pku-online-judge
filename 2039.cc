#include <iostream>
#include <string>
using namespace std;
int main()
{
    int interval,row,i,j;
    char str[210];
    while(cin>>interval&&interval)
    {
        cin>>str;
        row=strlen(str)/interval;
        for(i=0;i<interval;i++)
            for(j=0;j<row;j++)
            {
                if(j%2==0)
                    cout<<str[interval*j+i];
                else 
                    cout<<str[interval*(j+1)-1-i];
            }
        cout<<endl;
    }
    return 0;
}



