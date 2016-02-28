import java.util.*;   
import java.math.*;   
  
public class Main {   
  
    public static void main(String[] args) {   
        Scanner cin = new Scanner(System.in);   
           
        BigDecimal bd1 = BigDecimal.valueOf(0);   
        BigDecimal bd2 = BigDecimal.valueOf(0);   
        String str;   
           
        while(cin.hasNext())   
        {   
            str = cin.nextLine();   
            if(str.equals("0"))   
                break;   
            else  
            {   
                bd2 = new BigDecimal(str);   
                bd1 = bd1.add(bd2);   
            }   
        }   
           
        System.out.println(bd1.toPlainString());   
           
  
    }   
  
}  
