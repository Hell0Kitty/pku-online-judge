import java.io.BufferedInputStream;   
import java.math.BigDecimal;   
import java.util.Scanner;   
  
/**  
 *  
 * 格式错了好多次啊。。。  
 * 后来把输出结果复制到记事本比较下才发现。。。。郁闷啊。。。。  
 * poj1454  
 * @author NC  
 */  
public class Main{   
  
    public static void main(String[] args) {   
        Scanner scan = new Scanner(new BufferedInputStream(System.in));   
        while (scan.hasNext()) {   
            int n = scan.nextInt();   
            if (n == 0) {   
                break;   
            }   
            BigDecimal a = new BigDecimal(n + 1);   
            BigDecimal sum = BigDecimal.ONE;   
            for (BigDecimal i = BigDecimal.ONE; i.compareTo(a) == -1; i = i.add(BigDecimal.ONE)) {   
                sum = sum.multiply(i);   
            }   
            char[] s = sum.toString().toCharArray();   
            int[] num = new int[10];   
            for (int i = 0; i < s.length; i++) {   
                num[s[i] - '0']++;   
            }   
            System.out.println(n + "! --");   
            for (int i = 0; i <= 9; i++) {   
                if (i == 0 | i == 5) {   
                    System.out.print("   " + "(" + i + ")");   
                } else {   
                    System.out.print("    " + "(" + i + ")");   
                }   
                if (num[i] >= 100) {   
                    System.out.print("  " + num[i]);   
                } else if (num[i] >= 10) {   
                    System.out.print("   " + num[i]);   
                } else {   
                    System.out.print("    " + num[i]);   
                }   
                if (i == 4 || i == 9) {   
                    System.out.println("");   
                }   
            }   
        }   
    }   
}  
