//* @author:
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class Main{
 private static final String[] status = new String[] { "", "FILL(1)",
    "FILL(2)", "DROP(1)", "DROP(2)", "POUR(1,2)", "POUR(2,1)" };
 private static boolean[][] visted = new boolean[101][101];
 private static int a;
 private static int b;
 private static int c;

 public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j)
            visted[i][j] = false;
    }
    a = sc.nextInt();
    b = sc.nextInt();
    c = sc.nextInt();
    bfs();
  }

  static void bfs() {
    boolean is = false;
    LinkedList< Node> queue = new LinkedList< Node>();
    Node p = new Node();
    p.aa = 0;
    p.bb = 0;
    visted[p.aa][p.bb] = true;
    queue.addLast(p);
    // visted[p.aa][p.bb] = true;
    // p = new Node();
    // p.aa = 0;
    // p.bb = b;
    // p.status.add(2);
    // visted[p.aa][p.bb] = true;
    // queue.addLast(p);
    while (!queue.isEmpty()) {
     Node front = queue.getFirst();
     queue.remove();
     int r = -1;
     for (int i = 1; i <= 6; ++i) {
      int aa = front.aa;
      int bb = front.bb;
      int flag = i;
      switch (flag) {
       case 1:
        aa = a;
        break;
       case 2:
        bb = b;
        break;
       case 3:
        aa = 0;
        break;
       case 4:
        bb = 0;
        break;
       case 5:
        r = b - bb;
        bb = bb + (r <= aa ? r : aa);
        aa = (r <= aa ? (aa - r) : 0);
        break;
       case 6:
        r = a - aa;
        aa = aa + (r <= bb ? r : bb);
        bb = (r <= bb ? (bb - r) : 0);
        break;
       default:
        break;
       }
       if (aa == c || bb == c) {
        int size = front.status.size();
        System.out.println(size + 1);
        for (int j = 0; j < size; ++j)
             System.out.println(status[front.status.get(j)]);
        System.out.println(status[flag]);
        is = true;
        return;
        }
        if (!visted[aa][bb]) {
         Node tmp = new Node();
         tmp.aa = aa;
         tmp.bb = bb;
         int size = front.status.size();
         for (int j = 0; j < size; ++j)
            tmp.status.add(front.status.get(j));
         tmp.status.add(flag);
         visted[aa][bb] = true;
         queue.addLast(tmp);
         }
     }
    }
    if (!is)
      System.out.println("impossible");
 }

 private static class Node {
    private int aa;
    private int bb;
    private ArrayList< Integer> status = new ArrayList< Integer>();
 }
}

