import java.io.BufferedInputStream;
import java.math.BigDecimal;
import java.util.Scanner;

/**
 *
 * poj3331
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        while (scan.hasNext()) {
            int n = scan.nextInt();
            for (int i = 0; i < n; i++) {
                int a = scan.nextInt();
                int b = scan.nextInt();
                BigDecimal sum = BigDecimal.ONE;
                while (a > 0) {
                    BigDecimal aa = new BigDecimal(a);
                    sum = sum.multiply(aa);
                    a--;
                }
                char[] cs = sum.toString().toCharArray();
                int count = 0;
                String s = b+"";
                for (int k = 0; k < cs.length; k++) {
                    if ((cs[k]+"").equals(s)) {
                        count++;
                    }
                }
                System.out.println(count);
            }
        }
    }
}
