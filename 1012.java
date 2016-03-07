import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args){
  Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
  int k;
  int[] store={2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
  while (true){
   k=scanner.nextInt();
   if (k==0){
    break;
   }
   System.out.println(store[k-1]);
  }
 }
}


