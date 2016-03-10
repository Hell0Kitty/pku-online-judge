/* @author: */
import java.util.Scanner;
public class Main {
 public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);

  int t, i, c, j;
  char w[]=new char[100];
  boolean s[]=new boolean[100];
  int ans[]=new int[100];
  t=sc.nextInt();
  while(( t-- )!=0) {
     w=sc.next().toCharArray();
     for( i=0; i< 26; i++ ) {
      s[i] = false;
      w[i]-='A';
      ans[i+1] = 0;
     }

     for( i=0; i< 26; i++ ) {
    if( !s[i] ) {
       s[i] = true;
       for( j=w[i], c=1; j!=i; j=w[j], c++ )
        s[j] = true;
       if( (c&1)==0 )
        ans[c]++;
    }
     }
     for( i=2; i<=26; i++ )
    if( (ans[i] & 1)!=0 )
       break;
    System.out.printf( "%s\n", i<=26?"No":"Yes" );
   }
  }
}

