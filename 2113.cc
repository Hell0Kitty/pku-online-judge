#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 512
using namespace std;

bool w[MAXN][MAXN];
int tot[MAXN];
int father[MAXN];
int list[MAXN];
bool set[3][MAXN];
int inset[MAXN];
int n,m;

int findfather(int node){
return node==father[node]?node:(father[node]=findfather(father[node]));
}
void Union(int node1,int node2){
father[findfather(node2)]=findfather(node1);
}

int cmp(int a,int b){
return findfather(a)==findfather(b)?(tot[a]>tot[b]):(findfather(a)<findfather(b));
}

bool search(int num){
if (num>=n || father[list[num]]!=father[list[num-1]]) return true;
int i,j,node=list[num];
bool temp[MAXN];

for (i=0;i<3;i++){
if (set[i][node]){
inset[node]=i;
memcpy(temp,set[i],sizeof temp);
for (j=0;j<n;j++)
if (!w[node][j]) set[i][j]=false;
if (search(num+1)) return true;
memcpy(set[i],temp,sizeof temp);
}
}
return false;
}

int main(){
int i,j,k;
while (scanf("%d%d",&n,&m),n){
memset(w,true,sizeof w);
memset(tot,0,sizeof tot);
for (i=0;i<n;i++){
father[i]=i;
list[i]=i;
}
while (m--){
scanf("%d%d",&i,&j);
Union(i,j);
tot[i]++;
tot[j]++;
w[i][j]=w[j][i]=false;
}
sort(list,list+n,cmp);
for (i=0;i<n;){
inset[list[i]]=0;
memcpy(set[0],w[list[i]],sizeof set[0]);
memset(set[1],true,2*sizeof set[0]);
if (!search(++i)) break;
while (i<n && father[list[i]]==father[list[i-1]])
i++;
}
if (i<n)
puts("The agents cannot be split");
else {
for (i=0;i<n-1;i++)
printf("%d ",inset[i]);
printf("%d\n",inset[n-1]);
}
}
return 0;
}



