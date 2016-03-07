import java.util.*;

/**
 *
 * @author leo
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static boolean prime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;

    }

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int m, a, b;
        m = scan.nextInt();
        a = scan.nextInt();
        b = scan.nextInt();
        while (true) {
            if (a == 0 && b == 0 && m == 0) {
                break;
            }
            boolean flag = false;
            while (m > 0) {
                int t = (int) Math.sqrt((double) (m * a / b));
                if (t * t != m) {
                    t++;
                }
                int tmp = (int) Math.sqrt((double) m);
                for (int i = t; i <= tmp; i++) {
                    if (m % i == 0 && prime(i) && prime(m / i)) {
                        flag = true;
                        System.out.println(i + " " + m / i);
                        break;
                    }
                }
                if (flag) {

                    break;
                }
                m--;

            }

            m = scan.nextInt();
            a = scan.nextInt();
            b = scan.nextInt();
        }
        // TODO code application logic here
    }
}