//* @author:
import java.util.*;
public class Main{
   public static void main(String args[]){
     Scanner in=new Scanner(System.in);
      int n=in.nextInt();
      int j=-1;
       while(n!=0){
          String test=in.next();
          String front=in.next();
          String back=in.next();
           int len1=test.length();
           int len2=front.length();
          for(int i=0;i< len2;i++){
            if((front.charAt(i)=='*')||(test.charAt(j+1)==front.charAt(i)) || (test.charAt(j+1)==back.charAt(i)))
               j++;
            if(j==len1-1)
               break;
          }
          if(j==len1-1)
            System.out.printf("win\n");
        else
            System.out.printf("lose\n");
        n--;
        j=-1;
    }
   }
}

