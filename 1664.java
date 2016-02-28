import java.io.BufferedInputStream;
import java.util.Scanner;

/**
 *
 *poj1664
 * 自己还是想不到啊
 * f(m, n) = f(m-n, n) + f(m, n-1)
 * f(m, n): 把m个苹果放到n个盘子中的方法数
 * f(m, n-1): 把m个苹果放到n-1个盘子中的方法数(其中至少有一个空盘子)
 * f(m-n, n): 把m个苹果放到n个盘子中,而且每个盘子中都有苹果(先拿n个出来,等m-n个放好了,然后每个盘子放一个)
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        if (scan.hasNext()) {
            int n = scan.nextInt();
            for (int i = 0; i < n; i++) {
                int a = scan.nextInt();
                int b = scan.nextInt();
                System.out.println(f(a, b));
            }
        }
    }

    static int f(int m, int n) {
        /* 有些盘子不放苹果，已包含在f(m, n - 1)中，返回0*/
        if (m < 0) {
            return 0;
        }
        /* 刚好每个盘子放1个，只有一种情况 */
        if (m == 0) {
            return 1;
        }
        /* 只有1个盘子可以放，也只有全部放入这一种情况 */
        if (n == 1) {
            return 1;
        }
        /* n个盘子内至少都放1个 + 只放入n-1个盘子中 */
        return f(m - n, n) + f(m, n - 1);
    }
}
