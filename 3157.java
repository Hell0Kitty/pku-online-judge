import java.util.*;

 public class Main {

     public static void main(String[] args) {
         Scanner cin = new Scanner(System.in);

         while(cin.hasNext())
         {
             String str = cin.nextLine();

             int type = checkType(str);
             if(type == -1)
                 System.out.println("Error!");
             else if(type == 1)
             {
                 StringBuffer sb = new StringBuffer();
                 while(str.indexOf("_") != -1)
                 {
                     int index = str.indexOf("_");
                     sb.append(str.substring(0, index));
                     if(index != 0)
                     {
                         String tmp = str.substring(index+1);
                         str = FUpper(tmp);
                     }else
                         str = str.substring(index+1);

                 }
                 sb.append(str);
                 System.out.println(sb.toString());
             }
             else if(type == 2)
             {
                 StringBuffer sb = new StringBuffer();
                 for(int i = 0; i < str.length(); i++)
                 {
                     char c = str.charAt(i);
                     if(c >= 97 && c <= 122)
                     {
                         sb.append(c);
                     }else if(c >= 65 && c <= 90)
                     {
                         sb.append('_');
                         sb.append((char)(c+32));
                     }
                 }
                 System.out.println(sb.toString());
             }

         }

     }

     private static String FUpper(String str)
     {
         StringBuffer sb = new StringBuffer();

         sb.append((char)(str.charAt(0) - 32));
         if(str.length() > 1)
             sb.append(str.substring(1));
         return sb.toString();
     }

     private static int checkType(String str)
     {
         if(str.endsWith("_"))
             return -1;
         if(str.startsWith("_"))
             return -1;

         if(str.indexOf("_") != -1)
         {
             for(int i = 0; i < str.length(); i++)
             {
                 if((str.charAt(i) + 0) >= 65 && (str.charAt(i) + 0) <= 90)
                     return -1;
                 if(str.charAt(i) == '_' && i != 0 && i != str.length()-1)
                     if(str.charAt(i-1) == '_' || str.charAt(i+1) == '_')
                         return -1;
             }

             return 1;
         }

         if(str.charAt(0) >= 65 && str.charAt(0) <= 90)
             return -1;

         return 2;
     }

}

