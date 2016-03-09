import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws NumberFormatException,
           IOException {

       BufferedReader read = new BufferedReader(new InputStreamReader(

              System.in));

       int[] a = new int[26];
       int tt;
       for (int i = 0; i < 4; i++) {
           String str = read.readLine();
           for (int j = 0; j < str.length(); j++) {
              tt = str.charAt(j) - 'A';
              if (tt >= 0 && tt <= 25) {
                  a[tt]++;
              }
           }
       }
       int max = 0;
       for (int i = 0; i < 26; i++) {
           if (a[i] > max) {
              max = a[i];
           }
       }

       char[][] c = new char[max + 1][51];
       for (int i = 0; i < max + 1; i++) {
           Arrays.fill(c[i], ' ');
       }
       for (int i = 0; i < 26; i++) {
           int h = a[i];
           for (int j = 0; j < h; j++) {
              c[max - 1 - j][i * 2] = '*';
           }
       }
       for (int i = 0; i < 26; i++) {
           c[max][i * 2] = (char) ('A' + i);
       }

       for (int i = 0; i < max + 1; i++) {
           String str = String.valueOf(c[i]);
           while (str.endsWith(" ")) {
              str = str.substring(0, str.length() - 1);
           }
           System.out.println(str);
       }
    }
}

