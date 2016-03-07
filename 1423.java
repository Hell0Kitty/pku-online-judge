import java.util.*;

public class Main {

public static void main(String[] args) {
 Scanner cin = new Scanner(System.in);

 int n = cin.nextInt();
 while(n > 0) {
  int test = cin.nextInt();
  if(test <= 3)
   System.out.println(1);
  else {
   double result = 0.5*Math.log10(2*test*Math.PI)+
   test*Math.log10(test/Math.E)+1;;
   System.out.println((int)(result));
  }
  n--;
 }
}

}
