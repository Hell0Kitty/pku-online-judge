	import java.util.*;
import java.io.*;
import java.lang.reflect.Array;

public class Main {
  static public void main( String [] string ) throws Exception{
    Scanner cin = new Scanner( System.in );
    int b, n;
    while( true ) {
      b = cin.nextInt();
      n = cin.nextInt();
      if( b == 0 && n == 0 )
	 break;
      int x = (int)Math.pow( b, 1.0/n );
      if( Math.abs(Math.pow( x, n )-b)>Math.abs(Math.pow( x+1, n )-b) )
	 x = x+1;
      System.out.println( x );
    }
    return;
  }
}

