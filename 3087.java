/* @author: */

import java.util.*;
import java.io.*;
import java.lang.reflect.Array;

public class Main {
 static int a[] = new int[200];
 static char start[], result[];

 static public void main( String [] str ) throws Exception{
   int n;
   int m;
   Scanner cin = new Scanner( System.in );
   n = cin.nextInt();
   for( int k=1; k<=n; k++ ) {
	m = cin.nextInt();
	String input1 = cin.next(),
	input2 = cin.next(),
	input3 = cin.next();
	input1 += input2;
	start = input1.toCharArray();
	boolean [] sign = new boolean[m*2];
	for( int i=0; i< m; i++ )
         a[i] = i*2+1;
	for( int i=m; i< m*2; i++ )
	  a[i] = (i-m)*2;

	int i;
	for( i=0; ; i++ ) {
	  //System.out.println( start );
	  if( input3.equals( String.valueOf(start) ) )
		break;

	for( int j=0; j< 2*m; j++)
	  sign[j] = false;

	for( int j=0; j< 2*m; j++ ) {
	  if( !sign[j] ) {
	    char t = start[j], tt;
	    sign[j] = true;
	    for( int l=a[j]; l!=j; l=a[l] ) {
		sign[l] = true;
		tt = start[l];
		start[l] = t;
		t = tt;
	    }
	    start[j] = t;
	  }
	}

	if( input1.equals( String.valueOf(start) ) ) {
	   i = -1;
	   break;
	}
    }

    System.out.println( k+" "+i );
   }
   return;
  }
}

