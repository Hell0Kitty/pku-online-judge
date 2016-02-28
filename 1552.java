import java.util.*;   
  
public class Main {   
  
    public static void main(String[] args) {   
        Scanner cin = new Scanner(System.in);   
           
        while(true)   
        {   
            String temp = cin.nextLine();   
            if(temp.equals("-1"))   
                break;   
            temp = temp.substring(0, temp.length()-1).trim();   
  
            int[] num = new int[15];   
            String[] str = temp.split(" ");   
            for(int i = 0; i < str.length; i++)   
                num[i] = Integer.valueOf(str[i]).intValue();   
           
            int result = 0;   
            for(int i = 0; i < str.length; i++)   
            {   
                for(int j = 0; j < str.length; j++)   
                    if(num[i] == num[j] * 2)   
                        result++;   
            }   
            System.out.println(result);   
        }   
  
    }   
  
}  
