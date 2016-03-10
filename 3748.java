import java.io.BufferedInputStream;
import java.util.Scanner;

/**
 *
 *poj3748
 * 位操作
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        if (scan.hasNext()) {
            String[] ss = scan.nextLine().trim().split("[,]");
            Integer r = Integer.parseInt(ss[0], 16);//按16进制解析字符串
            Integer x = Integer.parseInt(ss[1]);//默认按10进制解析
            Integer y = Integer.parseInt(ss[2]);
            r = r & ~(0x1 << x);//第x位设置成0
            r = r & ~(0x1 << (y - 2));//0
            r = r | (0x1 << (y - 1));//1
            r = r | (0x1 << y);//1
            System.out.println(Integer.toHexString(r));
        }
    }
}

