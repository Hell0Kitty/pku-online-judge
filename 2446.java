//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;

public class Main {
 static final int N = 1030,M = 35;
 static int n,m;
 static int Graph[][] = new int[N][N],map[][] = new int[M][M];
 static int dir[][] = {{0,1},{0,-1},{1,0},{-1,0}};
 static int mat[] = new int[N],tmat[] = new int[N];
 static int hungry_aug(int i,int nt){
	int v,j;
	for(j=0;j< nt;++j){
          if(Graph[i][j]>0 && tmat[j]==0){
		tmat[j] = 1; v = mat[j];mat[j] = i;
		if(v==-1 || hungry_aug(v,nt)>0) return 1;
		mat[j] = v;
	  }
	}
	return 0;
}

static int hungry(int nt,int mt){
	int i,j,k=0;
	for(i=0;i< N;++i) mat[i] = -1;
	for(i=0;i< nt;++i){
        for(j=0;j< N;++j) tmat[j] = 0;
		k+=hungry_aug(i,nt);
	}
	return k;
}


 public static void main(String[]args) throws Exception{

  int i,j,k,hole,x,y;
  StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));


   n = Get_Num(cin);
   m = Get_Num(cin);
   hole = Get_Num(cin);
   init_graph();
   for(i=0;i< hole;++i){
	x = Get_Num(cin)-1;
	y = Get_Num(cin)-1;
	map[y][x] = 1;
   }
   for(i=0;i< n;++i)
    for(j=0;j< m;++j)
	  if(map[i][j]==0){
	   for(k=0;k< 4;++k)
	    if(can(i+dir[k][0],j+dir[k][1])){
		  x = i*m+j;
		  y = (i+dir[k][0])*m+(j+dir[k][1]);
		  Graph[x][y] = 1;
	     }
      }
  if((n*m-hole)%2==1 || hungry(n*m,n*m)!=(n*m-hole))
	System.out.println("NO");
  else System.out.println("YES");
 }

 static boolean can(int x,int y){
  if(x<0||x>=n||y< 0||y>=m)
	return false;
  if(map[x][y]>0) return false;
	return true;
 }

 static void init_graph(){
   int i,j;
   for(i=0;i< M;++i)
     for(j=0;j< M;++j)
	  map[i][j] = 0;
   for(i=0;i< n*m;++i)
      for(j=0;j< n*m;++j)
	   Graph[i][j] = 0;
 }

  static int Get_Num(StreamTokenizer cin) throws Exception{
	cin.nextToken();
	return (int) cin.nval;
  }
}

