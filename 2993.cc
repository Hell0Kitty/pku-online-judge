#include<iostream>
using namespace std;
void output(int i,int j,char p){
     if ((i+j)%2)
        printf(":%c:|",p);
     else
        printf(".%c.|",p);
     return ;
}
int main(){

    char a[8][8]={0};
    char wll[100];
    char p;
    int i,j,x,y;
    scanf("White: ");
    gets(wll);
    i=0;
    while (wll[i]!='\0'){
          if (wll[i]>='A'&&wll[i]<='Z'){
             p=wll[i];
             i++;
             y=wll[i]-'a';
             i++;
             x=8-wll[i]+'0';
             a[x][y]=p;
             i++;
          }
          else{
             p='P';
             y=wll[i]-'a';
             i++;
             x=8-wll[i]+'0';
             a[x][y]=p;
             i++;
          }
          if (wll[i]==',')
             i++;
    }
    scanf("Black: ");
    gets(wll);
    i=0;
    while (wll[i]!='\0'){
          if (wll[i]>='A'&&wll[i]<='Z'){
             p=wll[i]-'A'+'a';
             i++;
             y=wll[i]-'a';
             i++;
             x=8-wll[i]+'0';
             a[x][y]=p;
             i++;
          }
          else{
             p='p';
             y=wll[i]-'a';
             i++;
             x=8-wll[i]+'0';
             a[x][y]=p;
             i++;
          }
          if (wll[i]==',')
             i++;
    }
    cout<<"+---+---+---+---+---+---+---+---+\n";
    for (i=0;i<8;i++){
        cout<<'|';
        for (j=0;j<8;j++){
            if (a[i][j]==0)
                p=(i+j)%2?':':'.';
            else
                p=a[i][j];
            output(i,j,p);
        }
        cout<<"\n+---+---+---+---+---+---+---+---+\n";
    }
    return 0;
}



