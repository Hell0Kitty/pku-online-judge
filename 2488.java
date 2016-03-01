import java.io.PrintWriter;
 import java.util.Scanner;
 import java.util.Stack;
 public class Main {
  static class Point{
   int x ,y;
   public Point(int x ,int y){
    this.x = x;
    this.y = y;
   }
  }

 static int[][] chessboard = new int[27][27];
  static int num = 1;
 static int[] DX = {-1,1,-2,2,-2,2,-1,1};
  static int[] DY = {-2,-2,-1,-1,1,1,2,2};

  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);

   PrintWriter out = new PrintWriter(System.out);
   int n ,p,q;
   n = scn.nextInt();
   int index = 1;
   while(n-- > 0){
    p = scn.nextInt();
    q = scn.nextInt();
    out.format("Scenario #%d:\n%s\n\n", index++,calute(p,q));
   }
   out.flush();
  }
  static boolean find;//找到标志
  private static String calute(int p, int q) {
   //Queue points = new LinkedList();
   Stack result = new Stack();
   num = 1;
   find = false;
   int[][] visited = new int[p][q];
   result.add("A1");
   visited[0][0] = 1;
   bfs(p,q,new Point(0,0),result,visited);
   if(!find){
    return "impossible";
   }
   return getResult(result);
  }
  private static String getResult(Stack result) {
   StringBuffer sbf = new StringBuffer("");
   for(String str : result){
    sbf.append(str);
   }
   return sbf.toString();
  }
  private static void bfs(int p, int q, Point point, Stack result, int[][] visited) {
   int x = point.x, y = point.y, nx,ny;
   if(num == (p*q)){
    find = true;
   }
   for(int i = 0; i < 8 && !find; i++){
    nx = x + DX[i];
    ny = y + DY[i];

    if((nx <0 || nx >= p) || (ny < 0 || ny >= q)){
     continue;
    }
    //已访问过
    if(visited[nx][ny] == 1){
     continue;
    }
    result.add((char)('A' + ny) + "" + (nx + 1));
    visited[nx][ny] = 1;
    num++;
    bfs(p,q,new Point(nx,ny),result,visited);
    if(find){
     break;
    }
    visited[nx][ny] = 0;
    num--;
    result.pop();

   }
  }

 }

