//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args){
   Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String code=scanner.nextLine();
        String sent=scanner.nextLine();
        String decode="";
        for (int i=0;i< sent.length() ;i++ ){
            decode=decode+getChar(sent.charAt(i),code);
        }
        System.out.print(decode);
    }

    public static char getChar(char c,String code){
        if (c-'a'< 26&&c-'a'>=0){
            return Character.toLowerCase(code.charAt(c-'a'));
        }
        else if (c-'A'< 26&&c-'A'>=0){
            return Character.toUpperCase(code.charAt(c-'A'));
        }
        else{
            return c;
        }
    }
}


