//* @author:
import java.util.*;
public class Main {

 private class Point {

  int x = 0;
  int y = 0;

  public Point() {
   this(0, 0);
  }

  public Point(int x, int y) {
   this.x = x;
   this.y = y;
  }

  public boolean equals(Point p) {
   return (x == p.x) && (y == p.y);
  }

  @Override
  public String toString() {
   return "(" + x + ", " + y + ")";
  }
 }

 private int[][] maze = null;  //迷宫图
 private Stack< Point> stack = new Stack< Point>();
 //保存路径的栈

 public Main(int[][] maze) {
  this.maze = maze;
 }

 public void go() {
  Point out = new Point(maze.length-1, maze[0].length-1);  //出口
  Point in = new Point(0,0);  //入口
  Point curNode = in;    //当前点为入口
  Point nextNode = null;  //下一个访问点(目标点)

  while(!curNode.equals(out)) {
   nextNode = new Point(curNode.x,curNode.y);   //设置目标点为当前点，便于下面偏移
   if((curNode.x+1)< maze.length&&maze[curNode.x+1][curNode.y]==0) {  //如果下方是空的，则目标点向下偏移
    nextNode.x++;
   } else if((curNode.y+1)< maze[0].length&&maze[curNode.x][curNode.y+1]==0) {  //如果右边是空的，则目标点向右偏移
    nextNode.y++;
   } else if((curNode.x-1)>=0&&maze[curNode.x-1][curNode.y]==0) {  //如果上方是空的，则目标点向上偏移
    nextNode.x--;
   } else if((curNode.y-1)>=0&&maze[curNode.x][curNode.y-1]==0) {  //如果左边是空的，则目标点向左偏移
    nextNode.y--;
   } else {  //这里是没有路的状态
    maze[curNode.x][curNode.y] = 3;  //标记为死路
    if(stack.isEmpty()) {   //判断栈是否为空
     System.out.println("Non solution");
     return;
    }
    curNode = stack.pop();    //弹出上一次的点
    continue;    //继续循环
   }

   //如果有路的话会执行到这里
   stack.push(curNode);   //当前点压入栈中
   maze[curNode.x][curNode.y] = 2;   //标记为已走
   curNode = nextNode;   //移动当前点
  }

  if(nextNode.equals(out)) {
   stack.push(nextNode);   //将出口点添加到当前路劲中
   maze[nextNode.x][nextNode.y] = 2;   //标记为已走
  }
 // System.out.println("\n该迷宫的一条可行路劲为：");


   for(int i=0;i< stack.size();i++)
     System.out.println(stack.elementAt(i));


 }

 public static void main(String[] args) {
  Scanner in=new Scanner(System.in);
  int[][] maze=new int[5][5];
  for(int i=0;i< 5;i++)
   for(int j=0;j< 5;j++)
     maze[i][j]=in.nextInt();


  new Main(maze).go();
 }
}

