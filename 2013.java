//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args){
  Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n;
        String[] s;
        int index=1;
        while (true){
            n=scanner.nextInt();
            if (n==0){
                break;
            }
            System.out.println("SET "+index);
            index++;
            s=new String[n];
            for (int i=0;i< n/2 ;i++ ){
                s[i]=scanner.next();
                s[n-i-1]=scanner.next();
            }
            if (n%2==1){
                s[(n-1)/2]=scanner.next();
            }
            for (int i=0;i< n ;i++ ){
                System.out.println(s[i]);
            }
        }
    }
}

