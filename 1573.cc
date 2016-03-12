#include <memory.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct point{
  int x; 
  int y; 
};

std::vector<struct point> vp;
char matrix[20][20];
int row, column, enter; 

bool out_of_bound(int x, int y){
  if(x<0 || y <0) return true; 
  if(x >= row || y >=column ) return true; 
  return false; 
}


bool repeat(int newx, int newy){
  for (int i = 0; i < vp.size(); ++i)
  {
    if( newx == vp[i].x && newy == vp[i].y ){
      cout << i <<" step(s) before a loop of " << vp.size() -i <<" step(s)" << endl;
      return true; 
    }
  }
  return false;
}
void run(int enter){
  int cur = 0; 
  int startx = 0; 
  int starty = enter -1 ;
  struct point p;
  p.x = startx; p.y = starty; 
  cout << "[dbg] the startx " << startx << " starty: " << starty << endl;
  vp.clear();
  vp.push_back(p);

  while(true){
    cur ++;
    char inst = matrix[p.x][p.y];
    if( inst == 'E') {
      p.y++;
      struct point newpoint = p;
      vp.push_back(newpoint);
      if(out_of_bound(p.x, p.y )) break;  
      if(repeat(p.x, p.y )) {

        return; 
      }
    } else if( inst == 'W') {
      
      p.y --; 
      vp.push_back(newpoint);
      cout << "[dbg] now at " << newx << " " << newy << " W" << endl ;
      if(out_of_bound(p.x, p.y )) break;  
      if(repeat(p.x, p.y )) {
        return; 
      }

    } else if( inst == 'N') {
      p.x ++; 
      vp.push_back(newpoint);
      if(out_of_bound(p.x, p.y )) break;  
      if(repeat(p.x, p.y )) {

        return; 
      }

    } else {
      // inst == 's'
      p.x --;
      vp.push_back(newpoint);
      if(out_of_bound(p.x, p.y  )) break;  
      if(repeat(p.x, p.y )) {

        return; 
      }

    }
  } 
  cout << cur << " step(s) to exit" << endl; 


}


int main(int argc, char const *argv[])
{
  std::ios::sync_with_stdio(false);
  while(true){
    cin >> row >> column >> enter; 
    if(!row && !column && !enter) break; 
    for (int i = 0; i < row; ++i)
    {
      string tmp ;
      cin >> tmp ; 
      for (int j = 0; j < column; ++j)
      {
        matrix[i][j] = tmp[j];
      }
    }
    run(enter);
  }

  return 0;
}