import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;
 import java.util.Arrays;

 public class Main {

     public static void main(String[] args) throws NumberFormatException,
             IOException {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         int t = Integer.parseInt(read.readLine());
         int s;
         int[][] m;
         String[] str;
         int[] rooms = new int[200];
         int len;
         int start;
         int max;
         for (int i = 0; i < t; i++) {
             Arrays.fill(rooms, 0);
             s = Integer.parseInt(read.readLine());
             m = new int[s][2];
             for (int j = 0; j < s; j++) {
                 str = read.readLine().split(" ");
                 m[j][0] = Integer.parseInt(str[0]);
                 m[j][1] = Integer.parseInt(str[1]);
             }
             for (int j = 0; j < s; j++) {
                 if (m[j][0] % 2 == 1) {
                     m[j][0] = m[j][0] + 1;
                 }
                 if (m[j][1] % 2 == 1) {
                     m[j][1] = m[j][1] + 1;
                 }
                 len = Math.abs(m[j][0] - m[j][1]) / 2 + 1;
                 start = Math.min(m[j][0], m[j][1]) / 2 - 1;
                 for (int k = 0; k < len; k++) {
                     rooms[start + k]++;
                 }
             }
             max = rooms[0];
             for (int j = 1; j < 200; j++) {
                 if (rooms[j] > max) {
                     max = rooms[j];
                 }
             }
             System.out.println(max * 10);
         }
     } 
}

