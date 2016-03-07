 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;

 public class Main {

     public static void main(String[] args) throws NumberFormatException,
             IOException {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         int t = Integer.parseInt(read.readLine());
         String[][] bijiao;
         boolean[] coin;
         int[] hl;
         int fault;
         for (int i = 0; i < t; i++) {
             fault = -1;
             bijiao = new String[3][];
             hl = new int[12];
             coin = new boolean[12];
             for (int j = 0; j < 3; j++) {
                 bijiao[j] = read.readLine().split(" ");
                 if (bijiao[j][2].equals("even")) {
                     for (int k = 0; k < bijiao[j][0].length(); k++) {
                         coin[bijiao[j][0].charAt(k) - 'A'] = true;
                         coin[bijiao[j][1].charAt(k) - 'A'] = true;
                     }
                 } else {
                     for (int k = 0; k < 12; k++) {
                         if (bijiao[j][0].indexOf((char) ('A' + k)) == -1
                                 && bijiao[j][1].indexOf((char) ('A' + k)) == -1) {
                             coin[k] = true;
                         }
                     }
                 }
             }
             for (int j = 0; j < 3; j++) {
                 if (bijiao[j][2].equals("up")) {
                     for (int k = 0; k < bijiao[j][0].length(); k++) {
                         if (hl[bijiao[j][0].charAt(k) - 'A'] != 1) {
                             hl[bijiao[j][0].charAt(k) - 'A'] = -1;
                         } else {
                             coin[bijiao[j][0].charAt(k) - 'A'] = true;
                         }
                         if (hl[bijiao[j][1].charAt(k) - 'A'] != -1) {
                             hl[bijiao[j][1].charAt(k) - 'A'] = 1;
                         } else {
                             coin[bijiao[j][1].charAt(k) - 'A'] = true;
                         }
                     }
                 } else if (bijiao[j][2].equals("down")) {
                     for (int k = 0; k < bijiao[j][0].length(); k++) {
                         if (hl[bijiao[j][0].charAt(k) - 'A'] != -1) {
                             hl[bijiao[j][0].charAt(k) - 'A'] = 1;
                         } else {
                             coin[bijiao[j][0].charAt(k) - 'A'] = true;
                         }
                         if (hl[bijiao[j][1].charAt(k) - 'A'] != 1) {
                             hl[bijiao[j][1].charAt(k) - 'A'] = -1;
                         } else {
                             coin[bijiao[j][1].charAt(k) - 'A'] = true;
                         }
                     }
                 }
             }
             for (int j = 0; j < 12; j++) {
                 if (!coin[j]) {
                     fault = j;
                     break;
                 }
             }
             if (fault != -1 && hl[fault] == 1) {
                 System.out.println((char) ('A' + fault)
                         + " is the counterfeit coin and it is light.");
             } else if (fault != -1 && hl[fault] == -1) {
                 System.out.println((char) ('A' + fault)
                         + " is the counterfeit coin and it is heavy.");
             }
         }
}
}   