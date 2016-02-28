import java.io.*;
import java.util.*;

public class Main{
 static Scanner cin;
 static int n;
 static int[][] d;

 public static void main(String args[]){
  cin = new Scanner(System.in);
  n   = cin.nextInt();
  if(n==1){
    System.out.println(0);
    return;
   }

   d = new int[n+1][n+1];

   String s;
   int i,j;
   for(i=1;i<=n;i++)
	d[i][i] = 0;
   for(i=2;i<=n;i++)
	for(j=1;j<i;j++){
         s = cin.next();
	  if(s.equals("x") == true){
	    d[i][j] = -1;
	    d[j][i] = -1;
	  }
	  else{
	    d[i][j] = Integer.parseInt(s);
	    d[j][i] = d[i][j];
	   }
				
       }

    int[] dist = dijkstra();
    int max = 0;
    for(i=2;i<=n;i++)
	if(dist[i]>max)
	  max = dist[i];
    System.out.println(max);
  }

  static int[] dijkstra(){
   int[] dist = new int[n+1];
   boolean[] s = new boolean[n+1];

   for(int i=2;i<=n;i++){
    if(d[1][i] == -1)
	dist[i] = 200000;
    else
	dist[i] = d[1][i];
    s[i] = false;
   }
		
   dist[1] = 0;
   s[1] = true;
		
   for(int i=1;i<n;i++){
    int temp = 200000;
    int u=1;
    for(int j=1;j<=n;j++)
	if((!s[j])&&(dist[j]<temp)){
	  u = j;
	  temp = dist[j];
	}

   s[u] = true;
   for(int j=1;j<=n;j++)
    if((!s[j])&&(d[u][j] != -1)){
	int newdist = dist[u]+d[u][j];
	if(newdist < dist[j])
	  dist[j] = newdist;
    }
   }
		
   return dist;

 }

}
		
