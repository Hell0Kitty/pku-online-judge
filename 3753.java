import java.io.BufferedInputStream;
import java.util.Scanner;

/**
 *
 *poj3753
 * C语言里的
 * while(EOF != scanf("%s",source))
 *等价于java里的while (scan.hasNext())
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        while (scan.hasNext()) {
            String src = scan.nextLine().trim();
            while (true) {
                String key = scan.nextLine().trim();
                if (key.endsWith("END")) {
                    break;
                }
                if (key.equals("NULL")) {
                    System.out.println("0 NULL");//陷井
                } else if (key.isEmpty() || key.equals("") || !src.contains(key)) {
                    System.out.println(src.length() + " " + src);//陷井
                } else if (src.contains(key)) {
                    String sub = src.substring(0, src.indexOf(key));
                    if (src.indexOf(key) == 0) {
                        System.out.println("0 NULL");//陷井
                    } else {
                        System.out.println(sub.length() + " " + sub);
                    }
                }
            }
        }
    }
}

