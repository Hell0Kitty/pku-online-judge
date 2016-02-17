#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn1 = 250010;
const int maxn2 = 110;
const int mod = 1000000;
struct tree1{
  int l , r , sum;
}a1[4*maxn2];
struct plane{
  int x , v;
}P[maxn1];
struct tree2{
  int l , r , Max;
}a2[4*maxn1];
struct Node{
  int l , r;
}node[maxn1];
int N;

void build1(int l , int r , int k){
  a1[k].l = l;
  a1[k].r = r;
  a1[k].sum = 0;
  if(l != r){
    int mid = (l+r)/2;
    build1(l , mid , 2*k);
    build1(mid+1 , r , 2*k+1);
  }
}

void add1(int l , int r , int k){
  if(l <= a1[k].l && a1[k].r <= r) a1[k].sum++;
  else{
    int mid = (a1[k].l+a1[k].r)/2;
    if(mid >= r) add1(l , r , 2*k);
    else add1(l , r , 2*k+1);
    a1[k].sum = (a1[2*k].sum+a1[2*k+1].sum)%mod;
  }
}

int query1(int l , int r , int k){
  if(l <= a1[k].l && a1[k].r <= r) return a1[k].sum;
  else{
    int mid = (a1[k].l+a1[k].r)/2;
    if(mid >= r) return query1(l , r , 2*k)%mod;
    else if(l > mid) return query1(l , r , 2*k+1)%mod;
    else return (query1(l , mid , 2*k)+query1(mid+1 , r , 2*k+1))%mod;
  }
}

void pushup(int k){
  if(a2[2*k].Max == -1 && a2[2*k+1].Max == -1) a2[k].Max = -1;
  else if(a2[2*k].Max == -1) a2[k].Max = a2[2*k+1].Max;
  else if(a2[2*k+1].Max == -1) a2[k].Max = a2[2*k].Max;
  else{
    int lson = a2[2*k].Max , rson = a2[2*k+1].Max;
    int lnode = (P[node[lson].r].v-P[node[lson].l].v)*(P[node[rson].r].x-P[node[rson].l].x);
    int rnode = (P[node[rson].r].v-P[node[rson].l].v)*(P[node[lson].r].x-P[node[lson].l].x);
    if(lnode <= rnode) a2[k].Max = a2[2*k].Max;
    else a2[k].Max = a2[2*k+1].Max;
  }
}

void build2(int l , int r , int k){
  a2[k].l = l;
  a2[k].r = r;
  a2[k].Max = -1;
  if(l == r){
    if(P[node[l].l].v <= P[node[l].r].v) a2[k].Max = -1;
    else a2[k].Max = l;
  }else{
    int mid = (l+r)/2;
    build2(l , mid , 2*k);
    build2(mid+1 , r , 2*k+1);
    pushup(k);
  }
}

void update(int l , int r , int k){
  if(l <= a2[k].l && a2[k].r <= r){
    if(P[node[l].l].v <= P[node[l].r].v) a2[k].Max = -1;
    else a2[k].Max = l;
  }else{
    int mid = (a2[k].l+a2[k].r)/2;
    if(r <= mid) update(l , r , 2*k);
    else update(l , r , 2*k+1);
    pushup(k);
  }
}

void computing(){
  for(int i = 1; i < N; i++){
    node[i].l = i;
    node[i].r = i+1;
  }
  build2(1 , N-1 , 1);
  int cnt = 0;
  while(cnt < 10000){
    if(a2[1].Max == -1) break;
    int m = a2[1].Max;
    printf("%d %d\n" , node[m].l , node[m].r);
    swap(node[m].l , node[m].r);
    update(m , m , 1);
    if(m-1 >= 1){
      node[m-1].r = node[m].l;
      update(m-1 , m-1 , 1);
    }
    if(m+1 < N){
      node[m+1].l = node[m].r;
      update(m+1 , m+1 , 1);
    }
    cnt++;
  }
}

void readcase(){
  build1(1 , 100 , 1);
  int ans = 0;
  for(int i = 1; i <= N; i++){
    scanf("%d%d" , &P[i].x , &P[i].v);
    ans = (ans+query1(P[i].v+1 , 100 , 1))%mod;
    add1(P[i].v , P[i].v , 1);
  }
  printf("%d\n" , ans);
  if(ans != 0) computing();
}

int main(){
  while(~scanf("%d" , &N)){
    readcase();
  }
  return 0;
}



