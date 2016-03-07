import java.util.Scanner;   
  
/**  
 *poj1005 easy  
 * 使用Math里，要写完整 java.lang.Math不然poj编译过不了  
 * @author NC  
 */  
public class Main {   
  
    public static void main(String[] args) {   
        Scanner scan = new Scanner(System.in);   
        if (scan.hasNext()) {   
            int n = scan.nextInt();   
            for (int i = 1; i <= n; i++) {   
                double x = scan.nextFloat();   
                double y = scan.nextFloat();   
                double s = java.lang.Math.PI * (java.lang.Math.pow(x, 2) + java.lang.Math.pow(y, 2)) / 2;   
                int count = 0;   
                while (s > 0) {   
                    s = s - 50;   
                    count++;   
                }   
                System.out.println("Property " + i   
                        + ": This property will begin eroding in year " + count+".");   
            }   
            System.out.println("END OF OUTPUT.");   
        }   
    }   
}  
