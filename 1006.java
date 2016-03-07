import java.util.Scanner;   
  
/**  
 *poj1006  
 * 程序ac比理解题目简单多了  
 * 直接模拟的话，虽然很好理解，但却超时了。  
 * 最后，只能得用剩余定理  
 *题： 今有物，不知其数，三三数之，剩二；五五数之，剩三；七七数之，剩二。问物几何？  
 *即：n%3=2;n%5=3;n%7=2;求最小的n  
 * 解：三人同行七十稀,五树梅花廿一,七子团圆月正半,除百零五便得知  
 * 即：（2*70+3*21+2*15）%105＝23  
 * 70：a=5*7＝35，70，105...找出最小的a满足a%3=1，即a=70  
 * 21：b=3*7＝21，42，63，84，105...找出最小的b满足b%5=1,即b=21  
 * 15：c=3*5＝15，30，45，60，75，90，105...找出最小的满c足c%7=1,即c=15  
 * 105:3*5*7=105最小公倍数  
 * @author NC  
 */  
public class Main {   
  
    public static void main(String[] args) {   
        Scanner scan = new Scanner(System.in);   
        int k = 0;   
        while (scan.hasNext()) {   
            int p = scan.nextInt();   
            int e = scan.nextInt();   
            int i = scan.nextInt();   
            int d = scan.nextInt();   
            if (p == -1 && e == -1 && i == -1 && d == -1) {   
                break;   
            }   
            k++;   
//            int days = d + 1;   
//            while (true) {   
//                if ((days - p) % 23 == 0 && (days - e) % 28 == 0   
//                        && (days - i) % 33 == 0) {   
//                    break;   
//                }   
//                days++;   
//            }   
/**  
 *5544:28*33=924,1848,2772,3696,4620,5544...5544%23=1;5544相对于23的数论倒数  
 *14421:23*33=759,1518,2277,...,14421...14421%28=1;14421相对于28的数论倒数  
 *1288: 23*28=644,1288...1288%33=1;1288相对于33的数论倒数  
 */  
            int days = (5544 * p + 14421 * e + 1288 * i - d) % (21252);   
            if (days <= 0) {   
                days = 23 * 28 * 33 + days;   
            }   
            System.out.println("Case " + k   
                    + ": the next triple peak occurs in " + days   
                    + " days.");   
        }   
  
  
    }   
}  
