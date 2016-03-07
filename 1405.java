import java.io.BufferedInputStream;   
import java.math.BigDecimal;   
import java.util.ArrayList;   
import java.util.Scanner;   
  
/**  
 *poj1405  
 * 高精题  
 * 亲人人数:1            2           3           4           ...  
 * 所分遗产:1/2          1/3         1/7         1/43        ...  
 * 所剩遗产:1/(1*2)      1/(2*3)     1/(6*7)     1/(42*43)   ...  
 * 输出结果:2            3           7           43          ...  
 * 解析:    =2;          =1*2+1      =2*3+1      =6*7+1  
 * 若当前可分的遗产为1/a,那么要使教堂所分遗产最小的话,亲人所得应该就是1/(a+1)  
 * 剩下的1/(a*(a+1))就是教堂所得了  
 * @author NC  
 */  
public class Main {   
  
    public static void main(String[] args) {   
        Scanner scan = new Scanner(new BufferedInputStream(System.in));   
        if (scan.hasNext()) {   
            int n = scan.nextInt();   
            ArrayList<BigDecimal> results = new ArrayList(18);   
            results.add(0, new BigDecimal(2));   
            for (int i = 1; i < 18; i++) {   
                BigDecimal last = results.get(i - 1);   
                BigDecimal temp = (last.add(BigDecimal.ONE.negate())).multiply(last).add(BigDecimal.ONE);   
                results.add(i, temp);   
            }   
            for (int i = 1; i <= n; i++) {   
                System.out.println(results.get(i - 1));   
            }   
        }   
    }   
}  
