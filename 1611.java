import java.util.Arrays;   
import java.util.Scanner;   
  
public class Main {   
    static int[] student;   
    static int[] ans;   
  
    public static void main(String[] args) {   
        Scanner sc = new Scanner(System.in);   
        while (sc.hasNext()) {   
            int n = sc.nextInt();   
            int m = sc.nextInt();   
  
            if (n == 0 && m == 0)   
                break;   
            student = new int[n];   
  
            ans = new int[n];   
            Arrays.fill(ans, 1);   
            for (int i = 0; i < n; ++i) {   
                student[i] = i;   
            }   
            for (int i = 0; i < m; ++i) {   
                int k = sc.nextInt();   
                int x = sc.nextInt();   
                for (int j = 0; j < k - 1; ++j) {   
                    int y = sc.nextInt();   
                    unin(x, y);   
                    // student[y] = x;   
                    // x = y;   
                }   
            }   
            System.out.println(ans[find(0)]);   
            // for (int i = 0; i < n; ++i)   
            // System.out.println(i + ":" + student[i]);   
        }   
    }   
  
    static void unin(int x, int y) {   
  
        int px = find(x);   
        int py = find(y);   
        if (px == py)   
            return;   
        else {   
            // System.out.println("py=" + py + ";px=" + px);   
            if (px > py) {   
                student[py] = px;   
                ans[px] = ans[px] + ans[py];   
                // System.out.println("ans["+px+"]="+ans[px]);   
            } else {   
                student[px] = py;   
                ans[py] = ans[px] + ans[py];   
                // System.out.println("ans["+py+"]="+ans[py]);   
            }   
        }   
    }   
  
    static int find(int x) {   
        // ans++;   
        int p = student[x];   
        // System.out.println("p=" + p);   
        if (p == x)   
            return p;   
        else  
            return find(p);   
    }   
}  


//出处：http://blog.csdn.net/lazy_p/archive/2010/06/12/5666596.aspx