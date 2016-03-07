import java.io.BufferedInputStream;   
import java.math.BigDecimal;   
import java.util.Scanner;   
  
/**  
 *  
 * poj1354  
 * 2*(n-1)  
 * 看不懂，不知道为什么？  
 * 也不想去想了。。。水过先  
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
            BigDecimal nn = new BigDecimal(n);   
            BigDecimal sum = BigDecimal.ONE;   
            for (BigDecimal i = BigDecimal.ONE; i.compareTo(nn) == -1; i = i.add(BigDecimal.ONE)) {   
                sum = sum.multiply(i);   
            }   
            System.out.println("N=" + n + ":");   
            System.out.println(sum.multiply(new BigDecimal(2)));   
        }   
    }   
}  
