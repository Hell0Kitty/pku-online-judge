import java.util.*;
class node implements Comparable {
  int score, need;
  public int compareTo(Object o) { //按score升序排列
    node b = (node) o;
    return this.score - b.score;
  }
}

public class Main {
  node[] p;
  int n, c, f, r, sum;
  int[] high, low;
  int[] h;

  void up(int i) { //向上调整
    int j;
    while (i > 1) {
      j = i / 2; // i的父亲
      if (h[i] > h[j])
        swap(i, j);
      else
        break;
      i = j;
    }
  }

  void down(int i) { //向下调整
    int j;
    while (i * 2 <= r) {
      j = i * 2; // i的左儿子
      if (j + 1 <= r && h[j + 1] > h[j])
        j++;
      if (h[j] > h[i])
        swap(i, j);
      else
        break;
      i = j;
    }
  }

  void del(int x) { //删除堆顶,将x作为堆顶
    sum = sum + x - h[1];
    h[1] = x;
    down(1);
  }

  void insert(int x) { //在堆底插入
    h[++r] = x;
    sum += x;
    up(r);
  }

  //交换
  private void swap(int i, int j) {
    int temp = h[i];
    h[i] = h[j];
    h[j] = temp;
  }

  public void print() {
    for (int i = 1; i <= c; i++) {
      System.out.print("[" + p[i].score + "," + p[i].need + "]  ");
    }
  }

  public static void main(String args[]) {
    Main ma = new Main();
    ma.go();
  }

  public void go() {
    Scanner in = new Scanner(System.in);
    n = in.nextInt();
    c = in.nextInt();
    f = in.nextInt();
    low = new int[c + 1];
    high = new int[c + 1];
    h = new int[c + 1];
    p = new node[c + 1];
    for (int i = 1; i <= c; i++) {
      p[i] = new node();
      p[i].score = in.nextInt();
      p[i].need = in.nextInt();
    }
    r = sum = 0;
    Arrays.sort(p, 1, c + 1);
    // print();
    n /= 2;
    for (int i = 1; i <= n; i++) insert(p[i].need);
    low[n] = sum; //记录前面n个花费之和

    for (int i = n + 1; i <= c - n; i++) {
      if (p[i].need < h[1])
        del(p[i].need);
      low[i] = sum;
    }
    h = new int[c + 1];
    r = sum = 0;
    for (int i = c; i > c - n; i--) insert(p[i].need);
    high[c - n + 1] = sum;
    for (int i = c - n; i > n; i--) {
      if (p[i].need < h[1])
        del(p[i].need);
      high[i] = sum;
    }
    int ans = -1;
    for (int i = c - n; i > n; i--)
      if (low[i - 1] + high[i + 1] + p[i].need <= f) {
        ans = p[i].score;
            break; 
        } 
    System.out.println(ans); 
   
   } 
}
