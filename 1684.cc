#include <iostream>
#include <string>
#include <map>
using namespace std;
int ca,T,n,x,y;
char state[105][50],op[50],tmp[50],tmp2[50],id;
map<char,int> hash;
map<char,int> value;

inline void init(){
    hash.clear();
    value.clear();
}

void Toupper(char *str){
    int i;
    for(i=0;i<strlen(str);i++){
        if('a'<=str[i]&&str[i]<='z'){
            str[i]=str[i]-'a'+'A';
        }
    }
}

int Toint(char *str){
    if(strcmp(str,"DEC")==0)    return -1;
    if(strcmp(str,"INC")==0)    return 1;
    int i,sum=0;
    for(i=0;i<strlen(str);i++){
        sum*=10;
        sum+=str[i]-'0';
    }
    return sum;
}

int main(){
    scanf("%d",&T);
    while(T--){
        printf("%d\n",++ca);
        scanf("%d",&n);
        int i,j;
        scanf("\n");
        for(i=1;i<=n;i++){
            gets(state[i]);
        }
        init();
        for(i=1;i<n;i++){
            sscanf(state[i],"%s%s",&op,&tmp);
            Toupper(op);
            Toupper(tmp);
            if(strcmp(op,"DCL")==0){
                sscanf(state[i],"%s%s",&op,&tmp);
                id=tmp[0];
                if(hash.find(id)==hash.end()){
                    hash[id]=0;
                    value[id]=0;
                }
                else{
                    if(hash[id]==0){
                        printf("%d 1\n",i);
                    }
                    else{
                        hash[id]=0;
                        value[id]=0;
                    }
                }
            }
            else if(strcmp(tmp,"=")==0){
                sscanf(state[i],"%s%s%s",&op,&tmp,&tmp2);
                id=op[0];
                if(hash.find(id)==hash.end()){
                    printf("%d 2\n",i);
                }
                else{
                    hash[id]++;
                    value[id]=Toint(tmp2);
                }
            }
            else if(strcmp(op,"INC")==0||strcmp(op,"DEC")==0){
                sscanf(state[i],"%s%s",&op,&tmp);
                id=tmp[0];
                if(hash.find(id)==hash.end()){
                    printf("%d 2\n",i);
                }
                else{
                    hash[id]++;
                    value[id]+=Toint(op);
                }
            }
            else if(strcmp(op,"GOTO")==0){
                sscanf(state[i],"%s%s",&op,&tmp);
                id=tmp[0];
                if(('A'<=id&&id<='Z')||('a'<=id&&id<='z')){
                    sscanf(state[i],"%s%s%s",&op,&tmp,&tmp2);
                    if(hash.find(id)!=hash.end()){
                        hash[id]++;
                        if(value[id]>0){
                            i=Toint(tmp2)-1;
                        }
                    }
                    else{
                        printf("%d 2\n",i);
                    }
                }
                else{
                    i=Toint(tmp)-1;
                }
            }
        }
    }
    return 0;
}



