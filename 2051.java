import java.util.Scanner;

public class Main {
 private static Query[] query = new Query[1002];

 public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);

  int i = 0;
  while (sc.hasNext()) {
   String s = sc.nextLine();
   if (s.equals("#")) {
    int k = sc.nextInt();
    slove(k, i);
    break;
   }
   String[] str = s.split(" ");
   Query q = new Query();
   q.d = Integer.parseInt(str[1].trim());
   q.w = Integer.parseInt(str[2].trim());
   q.p = q.w;
   insertHeap(q, i);
   i++;
  }
 }

 public static void slove(int k, int n) {
  // System.out.println("start.........");

  while (k > 0) {
   System.out.println(query[0].d);
   query[0].w += query[0].p;
   // System.out.println(query[0].w);
   keapHeap(n);
   --k;
  }

 }

 public static void keapHeap(int n) {

  Query q = query[0];
  // System.out.println(q.w + ";" + q.d);
  int i = 0;
  int j = (i << 1) + 1;
  while (j <= n - 1) {
   if (j < n - 1 && query[j].w > query[j + 1].w)
    j++;
   else if (j < n - 1 && query[j].w == query[j + 1].w
     && query[j].d > query[j + 1].d) {
    j++;
   }
   if (query[j].w < q.w) {
    query[i] = query[j];
    i = j;
   } else if (query[j].w > q.w)
    break;
   else if (query[j].w == q.w && query[j].d < q.d) {
    query[i] = query[j];
    i = j;
   } else
    break;
   j = (i << 1) + 1;
  }
  query[i] = q;
 }

 public static void insertHeap(Query q, int n) {
  // System.out.println("n = " + n);
  if (n == 0) {
   query[0] = q;
  } else {

   int i = n;
   int j = (i - 1) >> 1;

   while (j >= 0) {
    if (query[j].w > q.w) {
     query[i] = query[j];
     i = j;
    } else if (query[j].w == q.w && query[j].d > q.d) {
     query[i] = query[j];
     i = j;
    } else
     break;
    j = (i - 1) >> 1;
   }
   query[i] = q;
  }
 }

 static class Query {
  private int w;
  private int p;
  private int d;
 }
}


