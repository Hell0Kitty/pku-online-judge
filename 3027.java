import java.util.*;
public class Main {

 static public void main( String [] str ){

  Scanner sc=new Scanner(System.in);
  int tt=sc.nextInt();
  while(( tt--)!=0 ) {
    int a, b, r1, r2, t, r, s;
    a=sc.nextInt();
    b=sc.nextInt();
    r1=sc.nextInt();
    r2=sc.nextInt();
    for( r2--; r2>r1; r2-- ) {
	r = r2; t = 0; s = 1;
	while( r!=0 ) {
	  t += (r%a)*s;
	  s *= b;
	  r/=a;
	}
	if( t % r2 == 0 )
	  break;
    }
    if( r2 > r1 )
	System.out.printf( "%d\n", r2 );
    else
	System.out.printf( "Non-existent.\n" );
   }
  }
}

