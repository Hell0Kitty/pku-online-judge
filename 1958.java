import java.util.*;
public class Main {

    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        for (int i = 1; i <= 12; i++) {
            System.out.println(move4(i));
        }
    }

    public static int move4(int k) {
        if (k == 1) return 1;
        if (k == 2) return 3;
        if (k == 3) {
            return 5;
        }
        int min = Integer.MAX_VALUE;
        for (int i = 1; i < k; i++) {
            int t = 2 * move4(k - i) + move3(i);
            if (t < min) {
                min = t;
            }
        }
        return min;
    }

    public static int move3(int k) {
        if (k == 0) {
            return 0;
        }
        return move3(k - 1) + move3(k - 1) + 1;
    }
}

