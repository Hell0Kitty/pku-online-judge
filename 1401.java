import java.util.*;   
import java.math.*;   
  
public class Main {   
  
    public static void main(String[] args) {   
        Scanner cin = new Scanner(System.in);   
           
        int num = Integer.valueOf(cin.nextLine()).intValue();   
           
        for(int i = 0; i < num; i++)   
        {   
            int raw = Integer.valueOf(cin.nextLine()).intValue();   
               
            int znum = getZNum(raw);   
           
            System.out.println(znum);   
        }   
  
    }   
       
    private static int getZNum(int input)   
    {   
        int output = 0;   
        int power = 1;   
        while(input >= Math.pow(5, power))   
        {   
            output += input / (int)(Math.pow(5, power));   
            power++;   
        }   
        return output;   
    }   
}  
