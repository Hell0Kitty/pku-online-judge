import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;

 public class Main {

     public static void main(String[] args) throws IOException {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         String s;
         int a, b;
         int min;
         int max;
         double gold = (Math.sqrt(5) - 1) / 2.0;
         int j;
         while ((s = read.readLine()) != null) {
             if (s.equals("")) {
                 break;
             }
             a = Integer.parseInt(s.split(" ")[0]);
             b = Integer.parseInt(s.split(" ")[1]);
             if (a == b || a == 0 || b == 0) {
                 System.out.println("1");
                 continue;
             }
             min = Math.min(a, b);
             max = Math.max(a, b);
             j = (int) ((max - min) / gold);
             if (min == j) {
                 System.out.println("0");
             } else {
                 System.out.println("1");
             }
         }
     } 
}

