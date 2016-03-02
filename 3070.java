    import java.io.BufferedReader;
    import java.io.IOException;
    import java.io.InputStreamReader;

    public class Main {

        public static void main(String[] args) throws IOException {
            BufferedReader read = new BufferedReader(new InputStreamReader(
                    System.in));
          int[] f = new int[15000];
           f[0] = 0;
           f[1] = 1;
           f[2] = 1;
           for (int i = 2; i < f.length - 1; i++) {
               f[i + 1] = (f[i - 1] + f[i]) % 10000;
           }
           int i;
           while ((i = Integer.parseInt(read.readLine())) != -1) {
               System.out.println(f[i % 15000]);
           }
       }
   }

