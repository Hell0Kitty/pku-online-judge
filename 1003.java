import java.util.*;   
  
public class Main {   
  
    public static void main(String[] args) {   
        Scanner cin = new Scanner(System.in);   
        String str;   
        int maxCardNum = 0;   
           
        while(cin.hasNext())   
        {   
            str = cin.nextLine();   
            if(str.equals("0.00"))   
                break;   
               
            float len = Float.valueOf(str).floatValue();   
               
            maxCardNum = getCardNum(len);   
            System.out.println(maxCardNum + " card(s)");   
        }   
  
    }   
       
    private static int getCardNum(float len)   
    {   
        float value = 0;   
        int index = 2;   
           
        while (value < len)   
        {   
            value += 1.0/index;   
            index++;   
        }   
               
        return index-2;   
    }   
  
}  
