import java.util.*;
import java.math.*;
public class Main {


 public static void main(String[] args) {
  Scanner cin  = new Scanner(System.in);
  BigInteger b,c,d;
  String str,str1,str2,str3;
  int i,len;
  while(cin.hasNext())
  {
   str = cin.next();
   b = new BigInteger(str);
   len=str.length()+1;
      char []kids = new char[len-1];
      for(i=0;i< len-1;i++)
       kids[i]='9';
      str3 = new String(kids);
   str1 = String.valueOf(len);
   c = new BigInteger(str1);
   d = b.multiply(c);
   str2 = d.toString();
   if(str2.compareTo(str3)==0)
         System.out.println(str+" "+"is cyclic");
   else
    
    System.out.println(str+" "+"is not cyclic");
    
  }
  

 }

}

