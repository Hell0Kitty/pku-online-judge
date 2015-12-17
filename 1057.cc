#include<iostream>
#include<string>
#include<list>
using namespace std;
string str;
void f(int layer, string dir)
{
    int i;
    list<string> fl;
    for(i=0;i<layer;i++)cout<<"|     ";
    cout<<dir<<endl;
    while(str!="]"&&str!="*")
    {
        if(str[0]=='f')fl.push_back(str);
        else dir=str,cin>>str,f(layer+1,dir);
        cin>>str;
    }
    fl.sort();
    for(list<string>::iterator it=fl.begin();it!=fl.end();it++)
    {
        for(i=0;i<layer;i++)cout<<"|     ";
        cout<<*it<<endl;
    }
}
int main()
{
    for(int t=1;cin>>str,str!="#";t++)
        cout<<"DATA SET "<<t<<':'<<endl,f(0,"ROOT"),cout<<endl;
    return 0;
}
