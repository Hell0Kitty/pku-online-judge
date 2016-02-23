#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

struct node{
      int map[5][5] ;
      int step ;
};
char s[5][5] , t[5][5] ;
int g[5][5] ;
map<int,bool> visit;
int goal ;

int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {0,1,-1,1,-1,1,0,-1};

int hash(node a){
      int ret = 0 ;
      for (int i = 0 ; i < 4 ; i++)
            for (int j = 0 ; j < 4 ; j++)
                  ret = ret*3+a.map[i][j] ;
      return ret ;
}

int Solve(){
      queue<node> q ;
      node first;
      for (int i = 0 ; i < 4 ; i++)
            for (int j = 0 ; j < 4 ; j++){
                  if (s[i][j]=='*') first.map[i][j] = 0 ;
                  if (s[i][j]=='w') first.map[i][j] = 1;
                  if (s[i][j]=='b') first.map[i][j] = 2 ;
            }
      int fuck = hash(first) ;
      first.step = 0 ;
      visit[fuck] = 1 ;
      if (fuck == goal) return first.step ;
      q.push(first) ;
      while (!q.empty()){
            node last = q.front() ; q.pop();
            node now = last ; now.step++ ;
            for (int i = 0 ; i < 4 ; i++)
                  for (int j = 0 ; j < 4 ; j++){
                        if (last.map[i][j]==0) continue ;
                        if (last.map[i][j]==2&&last.step%2==0) continue ;
                        if (last.map[i][j]==1&&last.step%2==1) continue ;
                        for (int k = 0 ; k < 8 ; k++){
                              int tx = i , ty = j;

                              while(((tx+dx[k]>=0 && tx+dx[k]<4) && (ty+dy[k]>=0&&ty+dy[k]<4)) && (now.map[tx+dx[k]][ty+dy[k]]==0)){
                                     tx += dx[k] ;
                                     ty += dy[k] ;
                              }
                              if (tx == i && ty == j) continue ;
                              swap(now.map[i][j],now.map[tx][ty]);
                              int state = hash(now);
                              if (visit[state]){
                                    swap(now.map[i][j] , now.map[tx][ty]);
                                    continue ;
                              }
                              if (state==goal)
                                    return now.step ;
                              visit[state] = 1 ;
                              q.push(now) ;
                              swap(now.map[i][j] , now.map[tx][ty]) ;
                        }
                  }
      }
      return -1 ;
}

int main()
{
      int _;
      scanf("%d",&_);
      while (_--){
            visit.clear() ;
            goal = 0;
            for (int i = 0 ; i < 4 ; i++)
            {
                  scanf("%s",s[i]);
            }
            for (int i = 0 ; i < 4 ; i++)
            {
                  scanf("%s",t[i]);
                  for (int j = 0 ; j < 4 ; j++)
                  {
                        if (t[i][j]=='*') g[i][j] = 0 ;
                        if (t[i][j]=='w') g[i][j] = 1;
                        if (t[i][j]=='b') g[i][j] = 2 ;
                        goal = goal * 3 + g[i][j] ;
                  }
            }
            printf("%d\n",Solve());
      }
      return 0 ;
}



