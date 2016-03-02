 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;
 import java.util.ArrayList;
 import java.util.Collections;
 import java.util.Comparator;
 import java.util.List;

 public class Main {

     class Compara implements Comparator< String[]> {

         public int compare(String[] o1, String[] o2) {
             if (o1[1].charAt(1) == o2[1].charAt(1)) {
                 return o1[1].charAt(0) - o2[1].charAt(0);
             } else if (Character.isUpperCase(o1[0].charAt(0))) {
                 return o1[1].charAt(1) - o2[1].charAt(1);
             } else {
                 return o2[1].charAt(1) - o1[1].charAt(1);
             }
         }
     }

     static char[] a = new char[] { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };

     public static void main(String[] args) throws IOException {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         String s;
         char c;
         String[] q;
         List< String[]> list = new ArrayList< String[]>();
         String[] t;
         for (int i = 0; i < 17; i++) {
             if (i % 2 == 0) {
                 read.readLine();
                 continue;
             }
             s = read.readLine();
             q = s.split("\\|");
             for (int j = 1; j <= 8; j++) {
                 c = q[j].charAt(1);
                 if (c == '.' || c == ':') {
                     continue;
                 }
                 t = new String[2];
                 t[0] = "" + c;
                 t[1] = "" + a[j - 1] + (8 - i / 2);
                 list.add(t);
             }
         }
         System.out.print("White: ");
         print("K", list);
         print("Q", list);
         print("R", list);
         print("B", list);
         print("N", list);
         print("P", list);
         System.out.println();
         System.out.print("Black: ");
         print("k", list);
         print("q", list);
         print("r", list);
         print("b", list);
         print("n", list);
         print("p", list);
         System.out.println();
     }

     public static void print(String key, List< String[]> list) {
         if (key.equals("k") || key.equals("K") || key.equals("q")
                 || key.equals("Q")) {
             String[] s = null;
             for (int i = 0; i < list.size(); i++) {
                 s = list.get(i);
                 if (s[0].equals(key)) {
                     break;
                 }
             }
             if (s != null) {
                 if (key.equals("k") || key.equals("K")) {
                     System.out.print(Character.toUpperCase(key.charAt(0))
                             + s[1]);
                 } else {
                     System.out.print("," + Character.toUpperCase(key.charAt(0))
                             + s[1]);
                 }
             }
         } else {
             List< String[]> temp = new ArrayList< String[]>();
             String[] s;
             for (int i = 0; i < list.size(); i++) {
                 s = list.get(i);
                 if (s[0].equals(key)) {
                     temp.add(s);
                 }
             }
             if (temp.size() > 0) {
                 Collections.sort(temp, new Main().new Compara());
                 if (key.equals("p") || key.equals("P")) {
                     for (int i = 0; i < temp.size(); i++) {
                         System.out.print("," + temp.get(i)[1]);
                     }
                 } else {
                     for (int i = 0; i < temp.size(); i++) {
                         System.out.print(","
                                 + Character.toUpperCase(key.charAt(0))
                                 + temp.get(i)[1]);
                     }
                 }
             }
         }
     }
}

