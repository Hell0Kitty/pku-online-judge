//* @author:alpc12
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

    String num;
    boolean ok;

    void DFS(int dep, String b) {
        if(b.length() == num.length())
            return;
        int i, j;
        for(i = 0; i <= 9; ++i) {
            BigInteger now = new BigInteger(""+i+b);
            String nows = now.multiply(now).multiply(now).toString();
            if(nows.length() >= num.length() && nows.substring(nows.length()-num.length()).equals(num)) {
                ok = true;
                System.out.println(now);
                return;
            }
            if(nows.length() > dep) {
                int all = Math.min(dep, num.length()-1);
                for(j = 0; j <= all; ++j) {
                    if(nows.charAt(nows.length()-1-j) != num.charAt(num.length()-1-j))
                        break;
                }
                if(j > all) {
                    DFS(dep+1, ""+i+b);
                    if(ok) return;
                }
            }
        }
    }

    void run() {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        for (int i = 0; i < n; ++i) {
            num = cin.next();
            ok = false;
            DFS(0, "");
            if(!ok) while(true);
        }
    }

    public static void main(String[] args) {
        new Main().run();

    }

}

