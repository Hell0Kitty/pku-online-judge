import java.util.*;   
  
public class Main {   
  
    public static void main(String[] args) {   
        Scanner cin = new Scanner(System.in);   
           
        int num = Integer.valueOf(cin.nextLine()).intValue();   
        String[] str = new String[2];   
        String rawA, rawB;   
           
        int a, b, sum = 0;   
           
        for(int i = 0; i < num; i++)   
        {   
            str = cin.nextLine().split(" ");   
            rawA = str[0];   
            rawB = str[1];   
                   
            a = Integer.valueOf(reverse(rawA)).intValue();   
            b = Integer.valueOf(reverse(rawB)).intValue();   
               
//          System.out.println(a + " " + b);   
            sum = a + b;   
            System.out.println(reverse(""+sum));   
        }   
           
    }   
       
    public static String reverse(String str)   
    {   
        int index = str.length() - 1;   
        while(str.charAt(index) == '0')   
            index--;   
  
        String trimStr = str.substring(0,index+1);   
        StringBuffer sb = new StringBuffer();   
           
        for(int i = trimStr.length()-1; i >=0; i--)   
            sb.append(trimStr.charAt(i));   
           
        return sb.toString();   
    }   
  
}  
