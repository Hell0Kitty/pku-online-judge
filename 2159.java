 import java.io.BufferedReader;
 import java.io.InputStreamReader;
 import java.util.ArrayList;
 import java.util.Collections;
 import java.util.List;

 public class Main {

     public static void main(String[] args) throws Exception {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         String chips = null;
         String source;
         boolean flg;
         while ((chips = read.readLine()) != null) {
             source = read.readLine();
             flg = true;
             List list1 = new ArrayList();
             List list2 = new ArrayList();
             list1 = getDifferent(chips, list1);
             list2 = getDifferent(source, list2);
             if (list1.size() != list2.size()) {
                 flg = false;
             } else {
                 Collections.sort(list1);
                 Collections.sort(list2);
                 for (int i = 0; i < list1.size(); i++) {
                     if (list1.get(i) != list2.get(i)) {
                         flg = false;
                     }
                 }
             }
             if (flg) {
                 System.out.println("YES");
             } else {
                 System.out.println("NO");
             }
         }
     }

     public static List getDifferent(String s, List list) {
         char[] c = s.toCharArray();
         String used = "";
         int index = 0;
         for (int i = 0; i < c.length; i++) {
             if ((index = used.indexOf(c[i])) == -1) {
                 used += c[i];
                 list.add(1);
             } else {
                 list.set(index, (Integer) list.get(index) + 1);
             }
         }
         return list;
     }
}

