 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;

 public class Main {

     class Point {
         int x;
         int y;

         public Point(int x, int y) {
             this.x = x;
             this.y = y;
         }
     }

     public static void main(String[] args) throws NumberFormatException,
             IOException {
         Main main = new Main();
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         int n = Integer.parseInt(read.readLine());
         Point[] p;
         Point[] ch;
         int x, y;
         String[] s;
         int len;
         int t;
         boolean b;
         for (int i = 0; i < n; i++) {
             int m = Integer.parseInt(read.readLine());
             p = new Point[m];
             for (int j = 0; j < m; j++) {
                 s = read.readLine().split(" ");
                 x = Integer.parseInt(s[0]);
                 y = Integer.parseInt(s[1]);
                 p[j] = main.new Point(x, y);
             }
             if (m <= 5) {
                 System.out.println("NO");
             } else {
                 ch = new Point[m];
                 len = 0;
                 len = Graham_scan(p, ch, m);
                 b = false;
                 t = 0;
                 for (int j = 0; j < len - 2; j++) {
                     if (!AtOneLine(ch[j], ch[j + 1], ch[j + 2])) {
                         b = true;
                         break;
                     }
                 }
                 if (b) {
                     for (int j = 0; j < len - 1; j++) {
                         for (int k = 0; k < m; k++) {
                             if (AtOneLine(ch[j], ch[j + 1], p[k])) {
                                 t++;
                             }
                         }
                         if (t < 3) {
                             b = false;
                             break;
                         }
                         t = 0;
                     }
                 }
                 if (b) {
                     System.out.println("YES");
                 } else {
                     System.out.println("NO");
                 }
             }
         }
     }

     public static boolean AtOneLine(Point p1, Point p2, Point p3) {
         return ((p1.x - p2.x) * (p1.y - p3.y) == (p1.x - p3.x) * (p1.y - p2.y));
     }

     public static double multiply(Point p1, Point p2, Point p0) {
         return ((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y));

     }

     public static double distance(Point p1, Point p2) {
         return (Math.sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y)
                 * (p1.y - p2.y)));
     }

     public static int Graham_scan(Point[] PointSet, Point[] ch, int n) {
         int i, j, k = 0, top = 2;
         Point tmp;
         for (i = 1; i < n; i++)
             if ((PointSet[i].y < PointSet[k].y)
                     || ((PointSet[i].y == PointSet[k].y) && (PointSet[i].x < PointSet[k].x)))
                 k = i;
         tmp = PointSet[0];
         PointSet[0] = PointSet[k];
         PointSet[k] = tmp;
         for (i = 1; i < n - 1; i++) {
             k = i;
             for (j = i + 1; j < n; j++)
                 if ((multiply(PointSet[j], PointSet[k], PointSet[0]) > 0)
                         || ((multiply(PointSet[j], PointSet[k], PointSet[0]) == 0) && (distance(
                                 PointSet[0], PointSet[j]) < distance(
                                 PointSet[0], PointSet[k]))))
                     k = j;
             tmp = PointSet[i];
             PointSet[i] = PointSet[k];
             PointSet[k] = tmp;
         }
         ch[0] = PointSet[0];
         ch[1] = PointSet[1];
         ch[2] = PointSet[2];
         for (i = 3; i < n; i++) {
             while (top > 0 && multiply(PointSet[i], ch[top], ch[top - 1]) >= 0)
                 top--;
             ch[++top] = PointSet[i];
         }
         return top + 1;
     }
}