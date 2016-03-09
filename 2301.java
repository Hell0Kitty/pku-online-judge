import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            int n = scan.nextInt();
            for (int i = 0; i < n; i++) {
                int s = scan.nextInt();
                int d = scan.nextInt();
                if (s < d ||(s+d)%2==1) {
                    System.out.println("impossible");
                } else {
                    int a = (s + d) / 2;
                    int b = (s - d) / 2;
                    System.out.println(a + " " + b);
                }
            }
        }

    }
}

