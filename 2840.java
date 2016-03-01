 import java.util.*;

 public class Main {
     public static void main(String[] args) {
         Scanner cin = new Scanner(System.in);

         int num = Integer.valueOf(cin.nextLine()).intValue();
         for(int i = 0; i < num; i++)
         {
             String[] str = cin.nextLine().split(":");
             int hour = Integer.valueOf(str[0]).intValue();
             int minute = Integer.valueOf(str[1]).intValue();

             if(minute != 0)
                 System.out.println("0");
             else
             {
                 if(hour >= 0 && hour <= 12)
                     System.out.println(hour+12);
                 else
                     System.out.println(hour-12);
             }
         }
     }
   }

