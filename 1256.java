 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;
 import java.util.Arrays;
 import java.util.Comparator;

 public class Main {

     class Compara implements Comparator<Character> {
         public int compare(Character o1, Character o2) {
             char a = Character.toLowerCase(o1);
             char b = Character.toLowerCase(o2);
             if (a == b) {
                 return o1 - o2;
             } else {
                 return a - b;
             }
         }
     }

     public Main() throws NumberFormatException, IOException {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         int t = Integer.parseInt(read.readLine());
         String s;
         Character[] c;
         char[] temp;
         char[] o;
         boolean[] used;
         for (int i = 0; i < t; i++) {
             s = read.readLine();
             o = s.toCharArray();
             c = new Character[o.length];
             for (int j = 0; j < o.length; j++) {
                 c[j] = new Character(o[j]);
             }
             Arrays.sort(c, new Compara());
             used = new boolean[c.length];
             temp = new char[c.length];
             findAll(c, temp, 0, used);
         }
     }

     public void findAll(Character[] c, char[] temp, int i, boolean[] used) {
         char flg = ' ';
         if (i == c.length) {
             System.out.println(temp);
             return;
         }
         for (int j = 0; j < c.length; j++) {
             if (!used[j]) {
                 if (flg == c[j]) {
                     continue;
                 }
                 flg = c[j];
                 temp[i] = c[j];
                 used[j] = true;
                 findAll(c, temp, i + 1, used);
                 used[j] = false;
             }
         }
     }

     public static void main(String[] args) throws NumberFormatException,
             IOException {
         new Main();
     }

 }
