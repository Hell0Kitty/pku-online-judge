import java.util.*;   
  
public class Main {   
  
    public static void main(String[] args) {   
        Scanner cin = new Scanner(System.in);   
           
        while(true)   
        {   
            String skew = cin.nextLine();   
            if(skew.equals("0"))   
                break;   
               
            int decimal = trans(skew);   
            System.out.println(decimal);   
        }   
  
    }   
       
    private static int trans(String skew)   
    {   
        int num = 0;   
        int index = 0;   
        for(int i = skew.length()-1; i>=0; i--)   
        {   
            int cnum = Integer.valueOf(skew.substring(i, i+1));   
            num += (Math.pow(2, index+1) - 1) * cnum;   
            index++;   
        }   
           
        return num;   
    }   
  
}  
