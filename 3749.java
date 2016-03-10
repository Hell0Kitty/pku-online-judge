import java.io.BufferedInputStream;
import java.util.Scanner;

/**
 *
 *poj
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        while (scan.hasNext()) {
            String s = scan.nextLine();
            if (s.equals("ENDOFINPUT")) {
                break;
            }
            while (s.equals("START")) {
                s = scan.nextLine();
                if (s.equals("END")) {
                    break;
                }
                char[] cs = s.trim().toCharArray();
                for (int i = 0; i < cs.length; i++) {
                    char c = cs[i];
                    if (c >= 'a' && c <= 'z') {
                        c = (char) (c - 32);
                    }
                    if (c >= 'A' && c <= 'Z') {
                        c = (char) ('A' + (c - 'A' - 5 + 26) % 26);
                        System.out.print(c);
                    } else {
                        System.out.print(c);
                    }
                }
                System.out.println();
                s = scan.nextLine();
            }

        }
    }
}


