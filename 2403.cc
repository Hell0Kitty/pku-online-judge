#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string,int> ma;

int main(){
    int m,n;
    cin>>m>>n;
    while(m--){
        string a;
        int b;
        cin>>a;
        scanf("%d",&b);
        ma[a]=b;
    }
    while(n--){
        string a;
        int sum=0;
        while(cin>>a){
            if(a==".")  break;
            //cout<<"de:"<<ma[a]<<endl;
            sum+=ma[a];
        }
        printf("%d\n",sum);

    }
}



