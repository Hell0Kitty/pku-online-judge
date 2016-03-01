import java.util.Scanner;

public class Main {

 /**
  * 获得一个Integer对应的二进制中1的个数
  * @param i
  * @return sum
  */
 public static int getSum(int i) {
  int sum = 0;
  while (i > 0) {
   i = i & (i - 1);
   ++sum;
  }
  return sum;
 }

 public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);
  while (sc.hasNext()) {
   int i = sc.nextInt();
   if (i == 0)
    break;
   int sum1 = getSum(i);
   for (int j = i + 1;; ++j) {
    int sum2 = getSum(j);
    if (sum2 == sum1) {
     System.out.println(j);
     break;
    }
   }
  }
 }

}

