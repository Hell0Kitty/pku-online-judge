 import java.util.*;

 public class Main {

     public static void main(String[] args) {
         Scanner cin = new Scanner(System.in);

         int pnum = Integer.valueOf(cin.nextLine()).intValue();

         for(int i = 1; i <= pnum; i++)
         {
             String[] str = cin.nextLine().split(" ");
             String a = removePreZero(str[0]);
             String b = removePreZero(str[1]);

             a = reverse(a);
             b = reverse(b);

             String result = addBinary(a, b);
             result = reverse(result);
             result = removePreZero(result);
             System.out.println(i + " " + result);
         }

     }

     private static String addBinary(String a, String b)
     {
         StringBuffer sb = new StringBuffer();
         int loa = a.length();
         int lob = b.length();

         String newa = a;
         String newb = b;
         if(loa > lob)
         {
             newa += "0";
             for(int i = 0; i <= (loa-lob);i++)
                 newb += "0";
         }else if(loa == lob)
         {
             newa += "0";
             newb += "0";
         }else
         {
             newb += "0";
             for(int i = 0; i <= (lob-loa);i++)
                 newa += "0";
         }

         int carry = 0;

         for(int i = 0; i < newa.length(); i++)
         {
             char c1 = newa.charAt(i);
             char c2 = newb.charAt(i);
             int tmp = c1 + c2 - 96 + carry;
             if(tmp == 0)
             {
                 sb.append('0');
                 carry = 0;
             }else if(tmp == 1)
             {
                 sb.append('1');
                 carry = 0;
             }else if(tmp == 2)
             {
                 sb.append('0');
                 carry = 1;
             }else
             {
                 sb.append('1');
                 carry = 1;
             }
         }

         return sb.toString();
     }

     private static String reverse(String str)
     {
         StringBuffer sb = new StringBuffer();

         for(int i = str.length() - 1; i >= 0; i--)
         {
             sb.append(str.charAt(i));
         }

         return sb.toString();

     }

     private static String removePreZero(String str)
     {
         int index = 0;

         while(index < str.length())
         {
             if(str.charAt(index) == '0')
                 index++;
             else
                 break;
         }

         if(index == str.length())
             return "0";

         return str.substring(index);
     }
}

