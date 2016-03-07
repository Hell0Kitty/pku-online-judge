import java.util.Scanner;  
public class Main {  
 public static int sum = 0;  
 public static boolean isPrime(int num) {  
  for (int i = 2; i <= Math.sqrt(num); i++) {  
   if (num % i == 0)  
    return false;  
  }  
  return true;  
 }  
 public static boolean isSmithNumbers(int num) {  
  String s = String.valueOf(num);  
  int tempSum = 0;  
  int k = num;  
  while (true) {  
   if (k / 10 > 0) {  
    tempSum += k % 10;  
    k /= 10;  
   } else {  
    tempSum += k;  
    break;  
   }  
  }  
  int n = (int)Math.sqrt(num);  
  for (int i = 2; i <= (int)Math.sqrt(num) ; ) {  
   if (num % i == 0) {  
    getSum(i);  
    num = num / i;  
   }else  
    i++;  
  }  
   getSum(num);  
  if (sum == tempSum)  
   return true;  
  return false;  
 }  
 public static void getSum(int i) {  
  while (true) {  
   if (i / 10 > 0) {  
    sum += i % 10;  
    i /= 10;  
   } else {  
    sum += i;  
    break;  
   }  
  }  
 }  
 public static void get(int n) {  
  while (true) {  
   sum = 0;  
   n++;  
   if (!isPrime(n)) {  
    if (isSmithNumbers(n)) {  
     System.out.println(n);  
     return;  
    }  
   }  
  }  
 }  
 public static void main(String[] args) {  
  Scanner sc = new Scanner(System.in);  
  int n = sc.nextInt();  
  while (n != 0) {  
   //long b = System.currentTimeMillis();  
   get(n);  
  // System.out.println(System.currentTimeMillis() - b);  
   n = sc.nextInt();  
  }  
 }  
}