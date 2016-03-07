import java.util.*;

/**
 *
 * @author leo
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int total, left;
        while (true) {
            total = scan.nextInt();
            if (total == 0) {
                break;
            }
            left = total;
            int temp = 0;
            for (int i = 0;; i++) {
                temp = i * i * i;
                if (temp == total) {
                    left = 0;
                    break;
                }
                if (temp > total) {
                    break;
                }
                if (left > (total - temp)) {
                    left = total - temp;
                    if (left == 0) {
                        break;
                    }
                }
                int ttemp = 0;
                boolean flag = false;
                for (int j = 1;; j++) {
                    ttemp = j * (j + 1) * (j + 2) / 6 + temp;
                    if (ttemp == total) {
                        left = 0;
                        flag = true;
                        break;
                    }
                    if (ttemp > total) {
                        break;
                    }
                    if (left > (total - ttemp)) {
                        left = total - ttemp;
                        if (left == 0) {
                            flag = true;
                            break;
                        }
                    }

                }
                if (flag) {
                    break;
                }
            }
            System.out.println(total - left);
        }

        // TODO code application logic here
    }
}