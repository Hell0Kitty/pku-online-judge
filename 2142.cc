#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int gcd(int a,int b){
	if(b == 0)
		return a;
	return gcd(b,a%b);
}
void extend_Eulid(int a,int b,int &x,int &y){
	if(b == 0){
	  x = 1;
	  y = 0;
	  return;
	}
	extend_Eulid(b,a%b,x,y);
	int temp = x;
	x = y;
	y = temp - a / b * y;
}
int main(){
	int a,b,n;
	while(scanf("%d%d%d",&a,&b,&n)){
	  if(a + b + n == 0)
		  break;
	  int x,y;
	  int gcdab = gcd(a,b);
	  a /= gcdab;
	  b /= gcdab;
	  n /= gcdab;
	  extend_Eulid(a,b,x,y);
	  int vx = x * n;
	  vx = (vx %b + b) % b;
	  int vy = (n - a * vx) / b;
	  if(vy < 0) vy = -vy;
	  y = y * n;
	  y = (y % a + a) % a;
	  x = (n - b * y) / a;
	  if(x < 0) x = -x;
	  if(x + y > vx + vy){
	    x = vx; y = vy;
	  }
	  printf("%d %d\n",x,y);
	}
	return 0;
}



