import java.io.BufferedInputStream;
import java.util.Scanner;

/**
 *poj2017
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));


        while (scan.hasNext()) {
            int n = scan.nextInt();
            if (n == -1) {
                break;
            }
            int lastTime = 0;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                int speed = scan.nextInt();
                int time = scan.nextInt();
                sum = sum + speed * (time - lastTime);
                lastTime = time;
            }
            System.out.println(sum + " miles");
        }
    }
}

