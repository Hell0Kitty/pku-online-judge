import java.util.Scanner;
import java.util.Arrays;
public class Main{
  int degree[]=new int[210];
  boolean visit[][]=new boolean[210][210];
  int path[]=new int[210];
  int n,m,t;

  void topsort(){
     for(int k=n;k>=1;k--){
          int i=n;
          while(i>=1 && degree[i]!=0) i--;
          if(i< 1){ System.out.printf("-1\n"); return; }
          degree[i]=-1;
          path[i]=k;
          for(int x=1;x<=n;x++) if(visit[x][i]) degree[x]--;
     }
     for(int j=1;j<=n;j++)  System.out.printf("%d ",path[j]);
     System.out.printf("\n");
}

 public void doit(){
   Scanner sc=new Scanner(System.in);

    int x,y;
    t=sc.nextInt();
    while((t--)!=0){
        n=sc.nextInt();
        m=sc.nextInt();
        Arrays.fill(degree,0);
        for(int i=0;i< visit.length;i++)
           Arrays.fill(visit[i],false);
        for(int i=1;i<=m;i++){
           x=sc.nextInt();
           y=sc.nextInt();
           if(!visit[x][y]){
              visit[x][y]=true;
              degree[x]++;
            }
        }
        topsort();
    }
  }
 public static void main(String args[]){
   Main m=new Main();
     m.doit();
  }
}

