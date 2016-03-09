import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.*;
public class Main {
 public static void main(String args[]){
     String str1="";
        Scanner scan=new Scanner(System.in);
        String s2="";
        while(scan.hasNext()){
         String str=scan.nextLine();
               if(str=="") break;
         StringTokenizer s=new StringTokenizer(str);
         while(s.hasMoreTokens()){
           String str2=(String)s.nextElement();
           if(str2.equals("< br>")){
            s2+=str1;
                 s2+='\n';
            str1="";
           }
           else if(str2.equals("< hr>")){
            if(str1!="") { s2+=str1;
                                s2+='\n';
                  }
            s2+="--------------------------------------------------------------------------------\n";
            str1="";
           }
           else{
            String s1="";
            if(str1!="") s1=str1+" "+str2;
            else s1=str2;
            if(s1.length()<=80){
              str1=s1;
            }
            else{
             s2+=str1;
             s2+='\n';
             str1=str2;
            }
           }
         }


        }

        if(str1!=null){
         System.out.print(s2);
         System.out.println(str1);
       }
        else {
         System.out.println(s2);
        }

   }
}


