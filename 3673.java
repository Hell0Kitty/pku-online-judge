import java.util.Scanner;
public class Main{
 public static void main(String[] args) {
  Scanner scanner=new Scanner(System.in);
  String str1=scanner.next();
  String str2=scanner.next();
  char[] array1=str1.toCharArray();
  char[] array2=str2.toCharArray();
  int sum1=0;
  for(int i=0;i< array1.length;i++){
    sum1+=array1[i]-48;
   }

  int sum2=0;
  for(int i=0;i< array2.length;i++){
   sum2+=array2[i]-48;
  }

  System.out.println(""+(sum1*sum2));
 }
}


