/* @author: */
import java.util.Scanner;
public class Main {

  static boolean b[]=new boolean[20];

  static void set( int k ) {
    if( k !=0) b[k-1] = !b[k-1];
    b[k] = !b[k];
    if( k< 19 ) b[k+1] = !b[k+1];
}

 public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);
   int a[]=new int[20];
   int i, j, ans, count;

   for( i=0; i< 20; i++ )
     a[i]=sc.nextInt();
   ans = 20;

   for( i=0; i< 2; i++ ) {
    for( j=0; j< 20; j++ )
    b[j] = (a[j]==1?true:false);
   count = 0;
   if( (i & 1)!=0 ) {
    set( 0 );
    count ++;
   }

   for( j=0; j< 19; j++ ) {
    if( b[j] == true ) {
        set( j+1 );
        count++;
    }
   }

  if( b[19] == false && count < ans )
    ans = count;
  }

  System.out.printf( "%d\n", ans );
  }
}

