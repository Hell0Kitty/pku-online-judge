import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args){
  Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int n=Integer.parseInt(scanner.nextLine());
    if (n< 2){
        System.out.println("YES");
    }
    else if (n==2){
        int a=scanner.nextInt();
        int b=scanner.nextInt();
        int c=scanner.nextInt();
        if (b*b-4*a*c>=0){
            System.out.println("NO");
        }
        else{
            System.out.println("YES");
        }
    }
    else{
        System.out.println("NO");
    }
 }
}

