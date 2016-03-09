import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static String[] names = new String[0];
    static int[] amount = new int[0];
    private static int[][] relation = new int[0][0];

    private static int getIndex(String s) {
        for (int i = 1; i < names.length; i++) {

            if (names[i].equals(s)) {
                return i;
            }
        }

        return -1;
    }


    /**
     * @param args
     * @throws IOException
     */
    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));

        int kase = 0;

        while (true) {
            String line = stdin.readLine();

            String[] temp = line.split("[ ]+");

            int n = Integer.parseInt(temp[0]);
            int k = Integer.parseInt(temp[1]);

            if (n == 0 && k == 0) {
                break;
            }

            kase++;

            names = new String[n + 1];

            for (int i = 1; i <= n; i++) {
                names[i] = stdin.readLine().trim();
            }

            relation = new int[n + 1][n + 1];
            amount = new int[n + 1];

            for (int i = 0; i <= n; i++) {
                amount[i] = 0;

                for (int j = 0; j <= n; j++) {
                    relation[i][j] = 0;
                }
            }

            for (int i = 1; i <= k; i++) {
                line = stdin.readLine();

                temp = line.split("[ ]+");

                int indexA = getIndex(temp[0]);
                int indexB = getIndex(temp[1]);

                if (indexA == -1 || indexB == -1) {
                  //  System.out.println("name==" + temp[0] + "  " + temp[1]);
                    continue;
                }

                relation[indexA][indexB] = 1;

                int m = Integer.parseInt(temp[2]);
                amount[indexA] -= m;

                amount[indexB] += m;
            }


            // firt using foyld wall-shall.
            for (int i = 1; i<= n; i++) {
                for (int j = 1; j<= n; j++) {
                    for (int f = 1; f <= n; f++) {
                        if (relation[i][f] == 1  && relation[f][j] == 1) {
                            relation[i][j] = 1;
                        }
                    }
                }
            }

     System.out.println("Case #" + kase);
     for (int i = 1; i <= n; i++) {
       if (amount[i] < 0) {
          while (amount[i] < 0) {
          for (int j = 1; j<= n; j++) {
            if (amount[j] <= 0) {
               continue;
             }
            if (relation[i][j] == 1) {
              if (amount[j] >= Math.abs(amount[i])) {
                 System.out.println(names[j] + " " + names[i] + " " + Math.abs(amount[i]));
                 amount[j] -= Math.abs(amount[i]);
                 amount[i] = 0;
                 if (amount[i] == 0) {
                    break;
                  }
             } else {
                 System.out.println(names[j] + " " + names[i] + " " + amount[j]);
                 amount[i] += amount[j];
                 amount[j] = 0;
                 break;
             }
           }
          }
      }
     }
    }

    System.out.println();
  }

 }

}


