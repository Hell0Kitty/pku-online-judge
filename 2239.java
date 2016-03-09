import java.io.*;
import java.util.*;

public class Main{
 static boolean[][] g=new boolean[305][100];
 static int[] xm=new int[305];
 static int[] ym=new int[100];
 static boolean[] chk=new boolean[100];
 static int un,vn;
 public static boolean search(int u){
   int v;
   for(v=0;v< vn;v++){
    if(g[u][v]&&!chk[v]){
    chk[v]=true;
    if(ym[v]==-1||search(ym[v])){
      ym[v]=u;
      xm[u]=v;
      return true;
    }
     }
   }
  return false;
 }

public static int match(){
 int u,ans=0;
 Arrays.fill(xm, -1);
 Arrays.fill(ym, -1);
 for(u=0;u< un;u++)
   if(xm[u]==-1){
    Arrays.fill(chk, false);
    if(search(u)) ans++;
    }
  return ans;
 }

 public static void main(String[] args){
  Scanner cin=new Scanner(new BufferedInputStream(System.in));
  while(cin.hasNext()){
   int n=cin.nextInt();
   un=n;
   vn=84;
   for(int i=0;i< g.length;i++)
    Arrays.fill(g[i], false);
   for(int i=0;i< n;i++){
    int t=cin.nextInt();
    for(int j=0;j< t;j++){
        int p=cin.nextInt();
     int q=cin.nextInt();
     g[i][(p-1)*12+q-1]=true;
    }
    }
    System.out.println(match());
  }
 }
}

