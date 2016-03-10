import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
  static final int MAXN = 1000005;
  int sup;
  int p[];
  int  n;
  int count[];
  boolean flag[];

  void getH() {
     p = new int[MAXN];
     flag = new boolean[MAXN];
     for (int i = 5; i < MAXN; i += 4) {
       if (flag[i] == false) {
         p[sup++] = i;
         for (int j = i + i; j < MAXN; j += i)
           flag[j] = true;
       }
     }
     //System.out.println(sup);
     count = new int[MAXN];
     int m = (int) Math.sqrt(MAXN);
     for (int i = 0; p[i] <= m; i++) {
       for (int j = i; j < sup; j++) {
         long temp = (long) p[i] * p[j];
         if (temp >= MAXN) break;
         if (count[(int)temp] == 0) {
           //System.out.println(temp);
           count[(int)temp]++;
         }
       }
     }
     for (int i = 5; i < MAXN; i++) {
        count[i] += count[i - 1];
        //System.out.println(count[i]);
     }
    }

    void run() {
      getH();
      //System.out.println(sup);
      while (true) {
        n = cin.nextInt();
        if (n == 0) break;
        System.out.println(n + " " + count[n]);
       }
     }

     public static void main(String[] args) {
        Main solved = new Main();
        solved.run();
      }

     static InputStream inputStream = System.in;
     static InputReader cin = new InputReader(inputStream);

     //Scanner cin = new Scanner(new BufferedInputStream(System.in));
    }


    class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            return -1;
            //throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int nextInt() {
        int c = read();
        if (c == -1)
            return -1;
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String next() {
        StringBuilder str = new StringBuilder();
        int ch;
        while (isSpaceChar(ch = read()));
        if (ch == -1)
            return null;
        do {
            str.appendCodePoint(ch);
        } while (!isSpaceChar(ch = read()));
        return str.toString();
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public char nextCharacter() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        return (char) c;
    }

}

