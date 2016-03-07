 import java.util.*;  
 import java.text.*;  
   
 public class Main {  
   
     public static void main(String[] args) {  
         Scanner cin = new Scanner(System.in);  
   
         float value = 0;  
         float temp = 0;  
           
         for(int i = 0; i < 12; i++)  
         {  
             temp = Float.valueOf(cin.nextLine()).floatValue();  
             value += temp;  
         }  
           
         value = value / 12;  
           
         DecimalFormat df = new DecimalFormat(".00");  
         String str = df.format(value);  
           
         System.out.println("$" + str);  
           
     }  
}   