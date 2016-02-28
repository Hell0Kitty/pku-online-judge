import java.util.Scanner;
public class Main{

  public static int minP(String s)
{
         int i = 0, j = 1, k = 0;
         int l = s.length();
         while (true)
         {
                   if (i + k >= l || j + k >= l) break;
                   if (s.charAt(i + k) == s.charAt(j + k))
                   {
                            k++;
                            continue;
                   }

                  else
                   {
                            if (s.charAt(j + k) > s.charAt(i + k)) j += k + 1;
                            else
                                     i += k + 1;
                           k = 0;
                            if (i == j) j++;
                   }
         }
         return Math.min(i, j);
}

public static void main (String args[])
{
         Scanner sc=new Scanner(System.in);
         String s;
         int t, pos;
         t=sc.nextInt();

         while ((t--)!=0)
         {
           s=sc.next();
                   s += s;
                   pos = minP(s);
                   System.out.printf("%d\n", pos + 1);

         }
   }
}