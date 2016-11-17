#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;
const int N = 100001 ;
struct Node
{
      int vdx ;
      int cost ;
      Node *next ;
}*map[N],nome[2*N] ; 
int   n,en,root,Max,Xor[N] ;
void  add(int from,int to,int cost)
{
      Node *ptr =&nome[en++] ;     
      ptr -> vdx = to ;
      ptr -> cost = cost ;
      ptr -> next = map[from] ;
      map[from] = ptr ;   
}
bool  used[N] ; 
void  dfs(int u)
{
      used[u] = true ;
      if(Xor[u] >Max) Max = Xor[u] ; 
      for(Node *ptr=map[u];ptr;ptr=ptr->next)
      {
            int v = ptr->vdx ;
            if(!used[v])
            {
                 if(u==root) Xor[v] = ptr->cost ;
                 else  Xor[v] = (ptr->cost^Xor[u]) ; 
                 dfs(v);     
            }   
      }   
} 
int readT()
{
    char c;int ret;
    while(c=getchar(),c<'0'||c>'9');
    ret=c-'0';
    while(c=getchar(),c>='0'&&c<='9')ret=ret*10+c-'0';
    return ret;
}
int chd[100000*31][2];        
int zn,maxdeep = 30;
int arr[32] ;
void  Insert() 
{
      int p = 0 ;  
      for(int i=maxdeep;i>=0;i--)
      {
          if(chd[p][arr[i]]==-1) 
          {
                memset(chd[zn],-1,sizeof(chd[zn])); 
                chd[p][arr[i]] = zn ++ ;      
          }
          p = chd[p][arr[i]] ;   
      } 
} 
int   query(int idx,int deep)
{
      if(deep == -1)
      {
          return 0 ; 
      } 
      if(chd[idx][1-arr[deep]] != -1) {
          return  (1<<deep) + query(chd[idx][1-arr[deep]],deep-1) ;    
      }else {
          return  query(chd[idx][arr[deep]],deep-1) ;   
      } 
}
int   main()
{
      while(scanf("%d",&n) != EOF)
      { 
      int a,b,c; 
      en = 0 ;  
      for(int i=0;i<=n;i++) map[i] = NULL ;
      for(int i=1;i<n;i++)
      {
          a = readT() ; 
          b = readT() ;
          c = readT() ;  
          add(a,b,c)  ;
          add(b,a,c)  ; 
      } 
      Max = -1 ;  
      memset(used,false,sizeof(used));
      root = 0 ;
      Xor[root] = 0 ;   
      dfs(root) ;
      memset(chd[0],-1,sizeof(chd[0]));       
      zn = 1 ;  
      for(int i=0;i<n;i++)
      {
          for(int j=maxdeep;j>=0;j--)
          {
              if(Xor[i]&(1<<j))  {
                    arr[j] = 1 ;
              }else {
                    arr[j] = 0 ;  
              }      
          }   
          Insert() ;
          Max =max(Max,query(0,maxdeep));  
      } 
      printf("%d\n",Max); 
      } 
      return 0 ; 
}


