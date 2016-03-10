import java.util.regex.*;import java.util.*;
public class Main {
     public static void main(String[] args){
         String str;
         int n;
         Scanner cin = new Scanner(System.in);
          n=cin.nextInt();
          str=cin.nextLine();
         Pattern pattern = Pattern.compile("(\\s)*(\\+|\\-)?(\\d)+(\\.(\\d)+)?((e|E)(\\+|\\-)?(\\d)+)?");
         int i;
          for(i=0;i< n;++i){
              str=cin.nextLine();
             Matcher matcher = pattern.matcher(str);
             if(matcher.matches()){
                 System.out.println("LEGAL");
             }
             else{
                 System.out.println("ILLEGAL");
              }
         }
     }
}

