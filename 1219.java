 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;

 public class Main {

     public static void main(String[] args) throws IOException {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         String s;
         String r;
         int time;
         char[] last;
         StringBuilder temp;
         char[] buff;
         int pos;
         boolean[] used;
         game: while (!(s = read.readLine()).equals("LINGO")) {
             if (s.equals("") || s == null) {
                 continue;
             }
             System.out.println();
             r = s;
             last = new char[] { '.', '.', '.', '.', '.' };
             last[0] = r.charAt(0);
             System.out.println(last);
             time = 1;
             turn: while (!(s = read.readLine()).equals("")) {
                 // check valid
                 if (s.length() != 5) {
                     System.out.println(last);
                     time++;
                     continue turn;
                 }
                 for (int i = 0; i < 5; i++) {
                     if (!Character.isUpperCase(s.charAt(i))) {
                         System.out.println(last);
                         time++;
                         continue turn;
                     }
                 }
                 // is right
                 if (s.equals(r)) {
                     System.out.println(r);
                     over(read);
                     continue game;
                 }
                 if (time == 6) {
                     System.out.println(r.toLowerCase());
                     over(read);
                     continue game;
                 }
                 // check
                 buff = new char[] { '.', '.', '.', '.', '.' };
                 temp = new StringBuilder(r);
                 used = new boolean[5];
                 for (int i = 0; i < 5; i++) {
                     if (r.charAt(i) == s.charAt(i)) {
                         buff[i] = s.charAt(i);
                         temp.setCharAt(i, ' ');
                         used[i] = true;
                     }
                 }
                 for (int i = 0; i < 5; i++) {
                     if (used[i]) {
                         continue;
                     }
                     if ((pos = temp.indexOf(s.charAt(i) + "")) != -1) {
                         buff[i] = Character.toLowerCase(s.charAt(i));
                         temp.setCharAt(pos, ' ');
                         used[i] = true;
                     }
                 }
                 System.out.println(buff);
                 last = buff;
                 time++;
             }
             if (time < 7) {
                 System.out.println(r.toLowerCase());
             }
         }
     }

     public static void over(BufferedReader read) throws IOException {
         while (!read.readLine().equals("")) {
         }
     }
} 