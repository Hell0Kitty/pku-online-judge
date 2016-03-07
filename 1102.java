 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;

 public class Main {

     public static void main(String[] args) throws IOException {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         int s;
         String[] ss;
         String str;
         String[] num = new String[] { "1111110", "0000110", "1011011",
                 "1001111", "0100111", "1101101", "1111101", "1000110",
                 "1111111", "1101111" };
         char temp;
         StringBuilder buff;
         while (true) {
             ss = read.readLine().split(" ");
             s = Integer.parseInt(ss[0]);
             if (s == 0) {
                 break;
             }
             str = ss[1];
             for (int i = 0; i < 5; i++) {
                 buff = new StringBuilder();
                 if (i == 0 || i == 2 || i == 4) {
                     for (int j = 0; j < str.length(); j++) {
                         buff.append(' ');
                         if (i == 0) {
                             temp = num[str.charAt(j) - '0'].charAt(0);
                         } else if (i == 2) {
                             temp = num[str.charAt(j) - '0'].charAt(6);
                         } else {
                             temp = num[str.charAt(j) - '0'].charAt(3);
                         }
                         if (temp == '1') {
                             for (int k = 0; k < s; k++) {
                                 buff.append('-');
                             }
                         } else {
                             for (int k = 0; k < s; k++) {
                                 buff.append(' ');
                             }
                         }
                         buff.append(' ');
                         buff.append(' ');
                     }
                 } else {
                     for (int j = 0; j < str.length(); j++) {
                         if (i == 1) {
                             temp = num[str.charAt(j) - '0'].charAt(1);
                             if (temp == '1') {
                                 buff.append('|');
                             } else {
                                 buff.append(' ');
                             }
                             for (int k = 0; k < s; k++) {
                                 buff.append(' ');
                             }
                             temp = num[str.charAt(j) - '0'].charAt(5);
                             if (temp == '1') {
                                 buff.append('|');
                             } else {
                                 buff.append(' ');
                             }
                         } else {
                             temp = num[str.charAt(j) - '0'].charAt(2);
                             if (temp == '1') {
                                 buff.append('|');
                             } else {
                                 buff.append(' ');
                             }
                             for (int k = 0; k < s; k++) {
                                 buff.append(' ');
                             }
                             temp = num[str.charAt(j) - '0'].charAt(4);
                             if (temp == '1') {
                                 buff.append('|');
                             } else {
                                 buff.append(' ');
                             }
                         }
                         buff.append(' ');
                     }
                 }
                 if (i == 0 || i == 2 || i == 4) {
                     System.out.println(buff);
                 } else {
                     for (int k = 0; k < s; k++) {
                         System.out.println(buff);
                     }
                 }
             }
             System.out.println();
         }
     }
}

