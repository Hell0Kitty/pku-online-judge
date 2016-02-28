import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

//最短路径bellman_ford
public class Main {
 Scanner cin = new Scanner(System.in);

 int n;
 int m;
 int s;
 double v;
 Edge[] rate;
 Edge[] commission;
 double[] value;
 public static final double EPS = 1E-8;

 public void inPut() throws FileNotFoundException {
 // File f = new File("D:\\ACM\\POJ解题\\1860\\test.txt");
 // cin = new Scanner(f);

  n = cin.nextInt();
  m = cin.nextInt();
  s = cin.nextInt() - 1;
  v = cin.nextDouble();
  int a;
  int b;
  double rab;
  double cab;
  double rba;
  double cba;
  rate = new Edge[m * 2];
  commission = new Edge[m * 2];
  value = new double[n];

  for (int i = 0; i < 2 * m; i++) {
   a = cin.nextInt() - 1;
   b = cin.nextInt() - 1;
   rab = cin.nextDouble();
   cab = cin.nextDouble();
   rba = cin.nextDouble();
   cba = cin.nextDouble();

   rate[i] = new Edge();
   rate[i].s = a;
   rate[i].e = b;
   rate[i].v = rab;
   commission[i] = new Edge();
   commission[i].s = a;
   commission[i].e = b;
   commission[i].v = cab;

   i++;
   rate[i] = new Edge();
   rate[i].s = b;
   rate[i].e = a;
   rate[i].v = rba;
   commission[i] = new Edge();
   commission[i].s = b;
   commission[i].e = a;
   commission[i].v = cba;
  }

  solve();
 }

 private void solve() {
  if (bellmanFord(s, rate, commission)) {
   System.out.println("YES");
  } else {
   System.out.println("NO");
  }
 }

 private boolean bellmanFord(int s, Edge[] rate, Edge[] commission) {
  Arrays.fill(value, 0);
  value[s] = v;
  boolean released;

  while (value[s] <= v + EPS) {
   released = false;
   for (int i = 0; i < m * 2; i++) {
    if (value[rate[i].e] + EPS < (value[rate[i].s] - commission[i].v)
      * rate[i].v) {
     value[rate[i].e] = (value[rate[i].s] - commission[i].v)
       * rate[i].v;
     released = true;
//     System.out.println(Arrays.toString(value));
    }
   }

   if (!released) {
//    System.out.println(true);
    return value[s] > v + EPS;
   }
  }
//  System.out.println(value[s]);
  return true;
 }

 public static void main(String[] args) throws FileNotFoundException {
  new Main().inPut();
 }

 class Edge {
  int s;
  int e;
  double v;
 }
}