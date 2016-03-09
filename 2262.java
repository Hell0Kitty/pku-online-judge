import java.util.*;
 public class Main{
   public static void main(String args[]){
     Scanner sc=new Scanner(System.in);
      int n=1;
      while(true){
        n=sc.nextInt();
        if(n==0) break;
       test(n);
      }

   }
   /*
   * 8 = 3 + 5
   * 20 = 3 + 17
   * 42 = 5 + 37
   */
  public static void test(int x){
      if(6<=x && x < 1000000){
          if(x%2!=0){
            System.out.println("输入数据不是偶数！");
           }else{
              boolean b=false;
            for(int i=3;i+i<=x;i++){
                if(isPrime(i) && isPrime(x-i)){
                    System.out.println(x+" = "+i+" + "+(x-i));
                   b = true;
                    break;
                 }
            }
            if(!b)
               System.out.println("Goldbach's conjecture is wrong.");
          }
      }else{
          System.out.println("输入数据范围不对");
       }
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

