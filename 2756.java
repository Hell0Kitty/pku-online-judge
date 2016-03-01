    import java.util.*;
    import java.math.*;

    public class Main {

        public static void main(String[] args)
        {
            Scanner cin = new Scanner(System.in);
            int num = Integer.valueOf(cin.nextLine()).intValue();

           for(int i = 0; i < num; i++)
           {
               String[] str = cin.nextLine().split(" ");

               BigDecimal a = new BigDecimal(str[0]);
               BigDecimal b = new BigDecimal(str[1]);

               BigDecimal result = a.add(b);
               System.out.println(result.toPlainString());
          }

       }

   }

