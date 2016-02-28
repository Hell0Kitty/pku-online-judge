import java.util.Scanner;
public class Main{
 static final int INF = 0x3f3f3f3f ;  
 private int n;  
 private int[][] maze;  //邻接矩阵
 private int[][] dis;  //dis[][]保存可以达到的最短距离，会变化； 
 private int[][] fa;  
 private int[] res;
 private int temp;

  public Main(int n,int[][] fa,int[][] maze){
     this.n=n;
     this.fa=fa;
     this.maze=maze;
     dis=new int[n+1][n+1];
     res=new int[n+1];
     
  }
  

 private void solve(int i, int j ,int k){            //记录最小环的路径    
    temp = 0 ;  
    while(j != i){  
        res[temp++] = j  ;  
        j = fa[i][j] ;  
    }  
    res[temp++] = i ;  
    res[temp++] = k ;  
}  

 private void Floyd(){  
    for(int i=1;i<=n;i++){  
        for(int j=1;j<=n;j++){  
            dis[i][j] = maze[i][j] ;  
        }  
    }  
    int ans = INF ;  
    for(int k=1;k<=n;k++){  
        for(int i=1;i<k;i++){  
            for(int j=i+1;j<k;j++){  
                if(dis[i][j]<INF && maze[i][k]<INF && maze[k][j]<INF && ans>dis[i][j] + maze[i][k] + maze[k][j]){  
                    ans = dis[i][j] + maze[i][k] + maze[k][j] ; //最大节点为k的环的最短路径
                    solve(i,j,k); //记录环的各顶点 
                }  
            }  
        }  
        for(int i=1;i<=n;i++){  
            for(int j=1;j<=n;j++){  
                if(dis[i][k]<INF && dis[k][j]<INF && dis[i][j]>dis[i][k] + dis[k][j]){  
                    dis[i][j] = dis[i][k] + dis[k][j] ;  
                    fa[i][j] = fa[k][j] ;  
                    fa[j][i] = fa[k][i] ;  
                }  
            }  
        }     
    }  
    if(ans == INF){  
        System.out.printf("No solution.\n");  
    }  
    else{  
        for(int i=0;i<temp;i++){  
            System.out.printf("%d%c",res[i],i==temp-1?'\n':' ');  
        }  
    }  
} 
 public static void  main(String args[]){  
    Scanner in=new Scanner(System.in);
    int a ,b ,c ;  
    while(in.hasNext()){  
       int n=in.nextInt();
       int m=in.nextInt();
       int maze[][]=new int[n+1][m+1];
       int fa[][]=new int[n+1][n+1];
        for(int i=1;i<=n;i++){  
            for(int j=1;j<=m;j++){  
                if(i == j)  maze[i][j] = 0;   
                else        maze[i][j] = INF ;  
            }  
        }  
        for(int i=1;i<=m;i++){  
           a=in.nextInt();
           b=in.nextInt();
           c=in.nextInt();
           if(maze[a][b] > c){  
                maze[a][b] = maze[b][a] = c ;  
                fa[a][b] = a ; //标记(i,j)最短路径上，距离j最近的那个结点    
                fa[b][a] = b ;    
            }     
        }  
       Main ma=new Main(n,fa,maze);
        ma.Floyd() ;  
    }     
 }
}  
