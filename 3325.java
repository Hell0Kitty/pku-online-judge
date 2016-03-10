  import java.util.*;
 import java.text.*;

 public class Main {

     public static void main(String[] args) {
         Scanner cin = new Scanner(System.in);

         while(true)
         {
             int num = cin.nextInt();
             if(num == 0)
                 break;

             int[] list = new int[num];
             int max = 0;
             int min = 1000;
             int result = 0;
             int tmp = 0;
             for(int i = 0; i < num; i++)
             {
                 tmp = cin.nextInt();
                 if(tmp > max)
                     max = tmp;
                 if(tmp < min)
                     min = tmp;
                 result += tmp;
             }
             result = (result - max - min)/(num-2);
             DecimalFormat df = new DecimalFormat("");
             System.out.println(df.format(result));
         }

     }
}

