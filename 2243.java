import java.util.*;
public class Main {

 private static int[][] position = new int[8][2];
 private static int[][] chessboard = new int[8][8];

 public Main() {
  initPosition();
 }

 /**
  * 初始化马可以走的方向
  */
 private static void initPosition() {
  position[0][0] = -2;
  position[0][1] = -1;
  position[1][0] = -2;
  position[1][1] = 1;
  position[2][0] = -1;
  position[2][1] = -2;
  position[3][0] = -1;
  position[3][1] = 2;
  position[4][0] = 1;
  position[4][1] = -2;
  position[5][0] = 2;
  position[5][1] = -1;
  position[6][0] = 1;
  position[6][1] = 2;
  position[7][0] = 2;
  position[7][1] = 1;
 }

 private static int[] getRC(String s) {
  int[] rc = new int[2];
  rc[0] = Integer.valueOf(String.valueOf(s.charAt(1))) - 1;
  rc[1] = s.charAt(0) - 'a';
  return rc;
 }

 /**
  * 广度搜索算法
  *
  * @param s1
  * @param s2
  */
 public static void bsf(String s1, String s2) {
  int[] rc = getRC(s1);
  int formR = rc[0];
  int formC = rc[1];
  // System.out.println(formR + " ," + formC);
  rc = getRC(s2);
  int toR = rc[0];
  int toC = rc[1];
  // System.out.println(toR + " ," + toC);
  LinkedList< Point> queue = new LinkedList();

  Point p = new Point();
  p.r = formR;
  p.c = formC;
  p.steps = 0;
  queue.addLast(p);
  chessboard[p.r][p.c] = 1;
  p = null;

  while (!queue.isEmpty()) {
   p = queue.getFirst();
   queue.removeFirst();
   if (p.r == toR && p.c == toC) {
    System.out.println("To get from " + s1 + " to " + s2
      + " takes " + p.steps + " knight moves.");
    break;
   }
   for (int i = 0; i < 8; ++i) {
    Point pp = new Point();
    pp.r = p.r + position[i][0];
    pp.c = p.c + position[i][1];
    pp.steps = p.steps + 1;
    if (pp.r >= 0 && pp.c >= 0 && pp.r <= 7 && pp.c <= 7
      && chessboard[pp.r][pp.c] == 0) {
     queue.addLast(pp);
     chessboard[pp.r][pp.c] = 1;
    }
    pp = null;
   }
   p = null;
  }
 }

 public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);
  initPosition();
  while (sc.hasNext()) {
   chessboard = null;
   chessboard = new int[8][8];
   String s1 = sc.next();
   String s2 = sc.next();
   Main.bsf(s1, s2);
  }
 }

}

class Point {
 int r;
 int c;
 int steps;
}


