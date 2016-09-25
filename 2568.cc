#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
const int maxn=55;
int a[maxn];
int num[maxn][maxn];  
int vis[maxn]; 
int rest[maxn]; 
int used[maxn]; 
vector<int>son[maxn];
struct Node{
    int u,v;  }node[maxn];

void dfs(int u){
    printf("(");
    printf("%d",u);
    for(int i=0;i<son[u].size();i++){
        printf(" "); 
        dfs(son[u][i]);
    }
    printf(")");
}
int main()
{
    string buf;
    char ch,str[200];
    int idx,u,v,minv;
    while(getline(cin,buf)){
        for(int i=0;i<maxn;i++)
            son[i].clear();
        memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(num));
        memset(used,0,sizeof(used));

        stringstream ss(buf);
        for(idx=0;ss>>a[idx];idx++);
        for(int i=idx-1;i>=0;i--){
            vis[a[i]]=1;  
            num[a[i]][i]=num[a[i]][i+1]+1;
            for(int j=0;j<idx;j++){
                if(a[j]!=a[i])
                    num[a[j]][i]=num[a[j]][i+1];
            }
        }
        int rlen=0,r=0; 
        for(int i=1;i<=a[idx-1];i++){
            if(!vis[i]){
                rest[rlen++]=i;
            }
        }
        sort(rest,rest+rlen);
        int k=0;
        for(int i=0;i<idx;i++){
            u=a[i];
            minv=60;
            for(int j=0;j<idx;j++){
                if(num[a[j]][i]==0 && a[j]<minv && !used[a[j]]){
                    minv=a[j];
                }
            }
            if(r<rlen && rest[r]<minv){
                minv=rest[r];
                r++;
            }
            used[minv]=1;
            node[k].u=u;
            node[k].v=minv;
            k++;
        }
        for(int i=0;i<k;i++){
            u=node[i].u;
            v=node[i].v;
            son[u].push_back(v);
        }
        if(a[idx-1]==0)
            a[idx-1]=1;
        dfs(a[idx-1]);
        printf("\n");
    }
    return 0;
}


