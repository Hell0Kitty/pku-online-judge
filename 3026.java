import java.io.PrintWriter;
 import java.util.LinkedList;
 import java.util.Queue;
 import java.util.Scanner;

public class Main {
  static class Point{
  int x,y,step;
   int result = 1;
   char c;
   public Point(int x, int y, char c){
   this.x = x;
    this.y = y;
  this.c = c;
    step = 1;
  }
  public Point(int x, int y,int step, char c){
    this.x = x;
   this.y = y;
    this.c = c;
    this.step = step;
  }
   @Override
   public int hashCode() {
    if(result != 1){
     return result;
    }
    final int prime = 31;
    result = 1;
    result = prime * result + c;
    result = prime * result + x;
    result = prime * result + y;
    return result;
   }
   @Override
   public boolean equals(Object obj) {
    if (this == obj)
     return true;
    Point other = (Point) obj;
    if (c != other.c)
     return false;
    if (x != other.x)
     return false;
    if (y != other.y)
     return false;
    return true;
   }

  }
  static int[][] all = new int[150][150];
  static int[] DX = {0,-1,0,1};//e n w s
  static int[] DY = {-1,0,1,0};
  public static void main(String[] args) {
   Scanner scn = new Scanner(System.in);

   PrintWriter out = new PrintWriter(System.out);


   int n = scn.nextInt(),x,y;
   int num;//S 和 A 的数量
   char[][] data = new char[101][101];
  int[][] table = new int[101][101];
   Point[] points = new Point[101];
   Point point;
   String str;
  while(n-- > 0){
    x = scn.nextInt();
    y = scn.nextInt();

    scn.nextLine();
    for(int i = 0; i < y; i++){
     str = scn.nextLine();
     data[i] = str.toCharArray();
    }
    //得到顶点数，并将其存入points数组中来
   num = getNum(data,y,x,points);
   for(int i = 0; i < num; i++){
     bfs(data,table,points[i]);
    }
    out.println(prim(table, num));
   }
   out.flush();
  }
 private static void bfs(char[][] data, int[][] table, Point point) {
   Queue queue = new LinkedList();
   queue.add(point);
   int x,y,nx,ny;
   int px = all[point.x][point.y];
   int[][] visted = new int[150][150];
   while(!queue.isEmpty()){
    point = queue.poll();
    x = point.x;
    y = point.y;
    for(int i = 0; i < 4; i++){
     nx = x + DX[i];
    ny = y + DY[i];
     if(data[nx][ny] == '#'){
      continue;
     }
     if(visted[nx][ny] == 1){
      continue;
     }
     visted[nx][ny] = 1;
     if(data[nx][ny] == 'A' || data[nx][ny] == 'S'){
      table[px][all[nx][ny]] = point.step;
     }
     queue.add(new Point(nx,ny,point.step + 1,data[nx][ny]));
    }
  }
 }


  /**
   * 得到 y 和 s 的数量
   * @param data
   * @param y
   * @param x
   * @return
   */
  private static int getNum(char[][] data, int x, int y,Point[] points) {
   int num = 0;
   char c;
   for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
     c = data[i][j];
     if(c == 'A' || c == 'S'){
      all[i][j] = num;
      points[num] = new Point(i,j,c);
      num++;
     }
    }
   }
   return num;
  }
  public static int prim(int[][] table, int n) {

   int[] lowcost = new int[n];
   boolean[] s = new boolean[n];
   int sum = 0;
   s[0] = true;// 从第一个位置开始
   for (int i = 1; i < n; i++) {
    lowcost[i] = table[0][i];
    s[i] = false;
   }
   // 找到 j - s 中的最小权边
   for (int i = 1; i < n; i++) {
    int min = Integer.MAX_VALUE;
    int j = 1;
   for (int k = 1; k < n; k++) {
     if ((lowcost[k] < min) && (!s[k])) {
      min = lowcost[k];
      j = k;
     }
    }
    s[j] = true;// 加入到j 加入到 s 集合中来
    // sum += min;
   for (int k = 1; k < n; k++) {
     if (table[j][k] < lowcost[k] && (!s[k])) {
      lowcost[k] = table[j][k];
     }
    }
   }

  for (int i = 0; i < n; i++) {
    sum += lowcost[i];
   }
   return sum;
  }
    }


