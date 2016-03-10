/* @author: */
import java.util.Scanner;
public class Main {


 public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);
  int i, n, h;
  boolean s[]=new boolean[100];
  n=sc.nextInt();
  if( n == 0 ) {
    System.out.printf( "0\n" );
    return ;
   }

   i = 0;
   h = 1;
   while( n!=0 ) {
    if( (n & 1)!=0 ) {
         s[i] = true;
      n -= h;
    }
    else
      s[i] = false;
    h = -h;
    n >>= 1;
    i++;
    }

    while(( i-- )!=0)
    System.out.printf( "%d", s[i]?1:0 );

    System.out.println();
   }
}

