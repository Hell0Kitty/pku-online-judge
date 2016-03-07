//仿照别人的思想敲得,之前不是很了解dijkstra，做过这题后有些理解 
//1,将当前未纳入最短路的符合要求的距离最短结点纳入最短路; 
//2,将所有与当前纳入的结点有关联并且未被纳入最短路的结点最短距离进行更新。 
//图论中另一个求最小生成树的的经典算法Prim算法与Dij过程极其类似，都是贪心思想。 
//只是一个是对顶点的选择，另外一个是对边的选择。 

import java.util.*; 
public class Main 
{ public static int[][] e; 
   public static int[]  dis; 
   public static int[] used; 
   public static int[] level; 
   public static int n,m; 
   public static void main(String[] args){ 
    Scanner cin = new Scanner(System.in); 
    int  x,t; 
    e = new int[101][101]; 
    dis = new int[101]; 
    used =  new int[101]; 
    level = new int[101]; 
          m=cin.nextInt(); 
          n=cin.nextInt(); 
           for(int i=1;i<=n;i++) 
             {   e[0][i]=cin.nextInt(); 
                 level[i]=cin.nextInt(); 
                  x=cin.nextInt(); 
                for(int j=0;j<x;j++) 
                { t=cin.nextInt(); 
                  e[t][i]=cin.nextInt(); 
                } 
             } 
           solve(); 
} 

public static void solve() 
{ int max,result; 
  result=e[0][1]; 
  for(int i=1;i<=n;i++) 
     { max=level[i]; 
       for(int j=1;j<=n;j++) 
        if(level[j]>max || level[j]<max-m)//判断所交易的人的等级是否符合题目所述的条件 
         used[j]=1;//不符合 
        else 
         used[j]=0; //符合 
       dijkstra(); 
       if(result>dis[1]) //比较每次所求的费用 
         result=dis[1]; 
} 
System.out.println(result); 
} 
public static void dijkstra() 
{ int min,temp,k; 
  for(int i=1;i<=n;i++) 
   dis[i]=e[0][i]; 
  for(int i=1;i<=n;i++) 
     { min=0x7FFFFFFF; 
       k=0; 
       for(int j=1;j<=n;j++)//找出代价最小的边 
         if(used[j]==0 && dis[j]<min) 
          {min=dis[j]; 
              k=j; 
          } 
       if(k==0) 
        break; 
       used[k]=1; 
       for(int j=1;j<=n;j++)//更新其节点的值 
        if(used[j]==0 && e[k][j]>0 && min+e[k][j]<dis[j]) 
         dis[j]=min+e[k][j]; 
    } 
   } 
} 
 