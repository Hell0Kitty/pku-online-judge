import java.io.BufferedInputStream;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Locale;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * poj3751 easy
 *
 * API里的
 * 字母  日期或时间元素  表示  示例
 *G  Era 标志符  Text  AD
 *y  年  Year  1996; 96
 *M  年中的月份  Month  July; Jul; 07
 *w  年中的周数  Number  27
 *W  月份中的周数  Number  2
 *D  年中的天数  Number  189
 *d  月份中的天数  Number  10
 *F  月份中的星期  Number  2
 *E  星期中的天数  Text  Tuesday; Tue
 *a  Am/pm 标记  Text  PM
 *H  一天中的小时数（0-23）  Number  0
 *k  一天中的小时数（1-24）  Number  24
 *K  am/pm 中的小时数（0-11）  Number  0
 *h  am/pm 中的小时数（1-12）  Number  12
 *m  小时中的分钟数  Number  30
 *s  分钟中的秒数  Number  55
 *S  毫秒数  Number  978
 *z  时区  General time zone  Pacific Standard Time; PST; GMT-08:00
 *Z  时区  RFC 822 time zone  -0800
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        int n = Integer.parseInt(scanner.nextLine());
        //DateFormat 是一个抽象类来的
        SimpleDateFormat df1 =
                new SimpleDateFormat("yyyy/MM/dd-HH:mm:ss", Locale.US);
        //二十四小时制
        SimpleDateFormat df2 =
                new SimpleDateFormat("MM/dd/yyyy-hh:mm:ssa", Locale.US);
        //十二小时制，12：01凌晨是十二点多
        //系统默认是上午或下午，而不是am或pm
        for (int i = 0; i < n; i++) {
            try {
                String s = scanner.nextLine();
                //先把字符串解析为日期，再格式化日期，转成字符串，最后再转小写
                System.out.println(df2.format(df1.parse(s)).toLowerCase());
            } catch (ParseException ex) {

            }
        }
    }
}

