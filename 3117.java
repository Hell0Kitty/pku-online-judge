//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args){
  Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int t,n;
    while (true){
        t=scanner.nextInt();
        if (t==0){
            break;
        }
        n=3*scanner.nextInt();
        for (int i=0;i< t ;i++ ){
            scanner.next();
            n=n-scanner.nextInt();
        }
        System.out.println(n);
    }
 }
}



