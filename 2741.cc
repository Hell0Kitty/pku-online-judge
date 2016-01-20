#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
string color[5][7];
int rota[24][6]= { { 0, 1, 2, 3, 4, 5 }, { 0, 2, 4, 1, 3, 5 }, { 0, 4, 3, 2, 1, 5 }, { 0, 3, 1, 4, 2, 5 }, { 3, 1, 0, 5,
        4, 2 }, { 3, 0, 4, 1, 5, 2 }, { 3, 4, 5, 0, 1, 2 }, { 3, 5, 1, 4, 0, 2 }, { 5, 1, 3, 2, 4, 0 }, { 5, 3, 4, 1,
        2, 0 }, { 5, 4, 2, 3, 1, 0 }, { 5, 2, 1, 4, 3, 0 }, { 2, 1, 5, 0, 4, 3 }, { 2, 5, 4, 1, 0, 3 }, { 2, 4, 0, 5,
        1, 3 }, { 2, 0, 1, 4, 5, 3 }, { 4, 0, 2, 3, 5, 1 }, { 4, 2, 5, 0, 3, 1 }, { 4, 5, 3, 2, 0, 1 }, { 4, 3, 0, 5,
        2, 1 }, { 1, 0, 3, 2, 5, 4 }, { 1, 3, 5, 0, 2, 4 }, { 1, 5, 2, 3, 0, 4 }, { 1, 2, 0, 5, 3, 4 } }; 
int Change(string a,string b){
    if(a==b) return 0;
    return 1;
}
int Change(string a,string b,string c){
    if(a==b && b==c) return 0;
    if(a==b) return 1;
    if(a==c) return 1;
    if(b==c) return 1;
    return 2;
}
int Change(string a,string b,string c,string d){
    if(a==b && b==c && c==d) return 0;
    if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d) return 3;
    if(a==b && b==c) return 1;
    if(a==b && b==d) return 1;
    if(a==c && c==d) return 1;
    if(b==c && c==d) return 1;
    return 2;
}
int Check(int b){
    int change=0;
    for(int i=0;i<6;i++){
        change+=Change(color[0][i],color[1][rota[b][i]]); 
    }
    return change;
}
int Check(int b,int c){
    int change=0;
    for(int i=0;i<6;i++){
        change+=Change( color[0][i], color[1][rota[b][i]], color[2][rota[c][i]]); 
    }
    return change;
}
int Check(int b,int c,int d){
    int change=0;
    for(int i=0;i<6;i++){
        change+=Change(color[0][i], color[1][rota[b][i]], color[2][rota[c][i]], color[3][rota[d][i]]); 
    }
    return change;
}
int Match2(){
    int change=100;
    for(int i=0;i<24;i++){
        int change_=Check(i);
        if(change_<change) change=change_;
    }
    return change;
}
int Match3(){
    int change=100;
    for(int i=0;i<24;i++)
        for(int j=0;j<24;j++){
            int change_=Check(i,j);
            if(change_<change) change=change_;
        }
    return change;
}
int Match4(){
    int change=100;
    for(int i=0;i<24;i++)
        for(int j=0;j<24;j++)
            for(int k=0;k<24;k++){
                int change_=Check(i,j,k);
                if(change_<change) change=change_;
            }
    return change;
}
int main(){
    int n;
    while(scanf("%d",&n) && n!=0){
        for(int i=0;i<n;i++)
            for(int j=0;j<6;j++)
                cin>>color[i][j]; 
        switch(n){
            case 1: printf("0\n"); break;
            case 2: printf("%d\n",Match2()); break;
            case 3: printf("%d\n",Match3()); break;
            case 4: printf("%d\n",Match4()); break;
            default: break;
        }
    }
    return 0;
}



