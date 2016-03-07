 import java.util.Arrays;
 import java.util.Scanner;

 public class Main {

     class Point implements Comparable {
         int row;
         int col;

         public Point(int x, int y) {
             this.row = x;
             this.col = y;
         }

         public int compareTo(Object o) {
             int result = 0;
             result = this.row - ((Point) o).row;
             if (result == 0) {
                 return this.col - ((Point) o).col;
             }
             return result;
         }
     }

     int width;
     int length;
     int num;
     Point[] points;
     int t_w;
     int t_l;
     int t_r;
     int t_c;
     int t_p;
     int max;
     int t_max;
     boolean[][] tian;

     public Main() {
         Scanner scan = new Scanner(System.in);
         width = scan.nextInt();
         length = scan.nextInt();
         tian = new boolean[width][length];
         num = scan.nextInt();
         points = new Point[num];
         for (int i = 0; i < num; i++) {
             t_r = scan.nextInt() - 1;
             t_c = scan.nextInt() - 1;
             points[i] = new Point(t_r, t_c);
             tian[t_r][t_c] = true;
         }
         Arrays.sort(points);
         search();
         if (max >= 3) {
             System.out.println(max);
         } else {
             System.out.println(0);
         }
     }

     public void search() {
         max = 0;
         for (int i = 0; i < num; i++) {
             for (int j = i + 1; j < num; j++) {
                 t_w = points[j].row - points[i].row;
                 t_l = points[j].col - points[i].col;
                 t_r = points[i].row - t_w;
                 t_c = points[i].col - t_l;
                 if (t_r >= 0 && t_r < width && t_c >= 0 && t_c < length) {
                     continue;
                 }
                 t_r = points[j].row;
                 t_c = points[j].col;
                 t_max = getLength(2);
                 if (max < t_max) {
                     max = t_max;
                 }

             }
         }
     }

     public int getLength(int sum) {
         t_r += t_w;
         t_c += t_l;
         while (t_r >= 0 && t_r < width && t_c >= 0 && t_c < length) {
             if (hasPoint(t_r, t_c)) {
                 sum++;
             } else {
                 return 0;
             }
             t_r += t_w;
             t_c += t_l;
         }
         return sum;
     }

     public boolean hasPoint(int row, int col) {
         if (tian[row][col]) {
             return true;
         } else {
             return false;
         }
     }

     public static void main(String[] args) {
         new Main();
     } 
}