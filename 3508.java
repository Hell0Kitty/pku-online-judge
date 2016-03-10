import java.io.BufferedReader;

import java.io.IOException;

import java.io.InputStreamReader;



public class Main {



    public static void main(String[] args) throws IOException {

       BufferedReader read = new BufferedReader(new InputStreamReader(

              System.in));

       int num = 1;

       int flg, tt, last;

       while (true) {

           char[] c = read.readLine().toCharArray();

           if (c.length == 1 && c[0] == '0') {

              break;

           }

           last = c[c.length - 1];

           flg = 0;

           for (int j = c.length - 2; j >= 0; j--) {

              tt = c[j] - last;

              if (flg + tt < 0) {

                  c[j] = (char) ('0' + flg + tt + 10);

                  flg = -1;

              } else {

                  c[j] = (char) ('0' + flg + tt);

                  flg = 0;

              }

              last = c[j];

           }

           if (c[0] != '0') {

              System.out.println(num + ". " + String.valueOf(c));

           } else {

              System.out.println(num + ". IMPOSSIBLE");

           }

           num++;

       }

    }

}

