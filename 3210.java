//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args){
  Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int n;
    while (true){
           n=scanner.nextInt();
       if (n==0){
        break;
       }
       if (n%2==0){
        System.out.println("No Solution!");
       }
       else{
        System.out.println(n-1);
      }
    }
  }
}

