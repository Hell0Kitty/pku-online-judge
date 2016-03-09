import java.util.Scanner;

/**
 * POJ2027 easy
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            int n = scan.nextInt();
            for (int i = 0; i < n; i++) {
                int a = scan.nextInt();
                int b = scan.nextInt();
                if (a >= b) {
                    System.out.println("MMM BRAINS");
                } else {
                        System.out.println("NO BRAINS");
                }
            }
        }
    }
}

