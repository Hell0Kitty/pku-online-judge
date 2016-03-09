import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static BigInteger getVolume(int[] a, int n) {
        BigInteger sum = new BigInteger("0");
        BigInteger s = new BigInteger("0");
        int i = 0;
        for (; i < n - 1; i++) {
            s = s.add(new BigInteger(String
                .valueOf((Math.abs(a[0] - a[i + 1])))));
        }
        sum = new BigInteger(String.valueOf(s)).add(sum);
        i = 1;
        while (i < n) {
        s = s.subtract(new BigInteger(String.valueOf(new BigInteger(String
            .valueOf((n - 2 * i))).multiply(new BigInteger(String
            .valueOf((Math.abs(a[i] - a[i - 1]))))))));
        sum = sum.add(new BigInteger(String.valueOf(s)));
            i++;
        }
        return sum;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        Arrays.sort(a);
        System.out.println(Main.getVolume(a, n));
    }

}

