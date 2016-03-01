import java.util.*;
 public class Main{
   public static void main(String args[]){
     Scanner sc=new Scanner(System.in);
      int n=1;
      while(true){
        n=sc.nextInt();
        if(n==0) break;
       System.out.println(test2(n));
      }

   }

   /*
    * Sum of Consecutive Prime Numbers
    */
  public static int test2(int x){
      int count=0;
      for(int i=2;i+i< x;i++){
           int sum = 0;
           if(!isPrime(i)){
              continue;
          }
           for(int j=i;j< x;j++){
              // 判断是否为质数
              if(!isPrime(j))
                 continue;
              sum = sum+j;
             // 判断是否满足条件
              if(sum>=x){
                  if(sum==x){
                    count++;
                  }
                 break;
              }
           }
      }
      if(isPrime(x))
           count++;
       return count;
    }

   /*
    * 判断某个数是否为质数，如果是返回true
    */

   public static boolean isPrime(int x){
      for(int i=2;i*i<=x;i++){
          if(x%i==0)
             return false;
      }
      return true;
    }
}

