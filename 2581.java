//* @author:
import java.util.*;
public class Main {
 static public void main( String [] str ){
   Scanner sc = new Scanner(System.in);
   while(sc.hasNext())
   {
       int a,b,c,d,e,i,j,k,total,s,value;
	int as=0,bs=0,cs=0,ds=0;
	double t;
       t=sc.nextDouble();
       b=sc.nextInt();
       c=sc.nextInt();
       d=sc.nextInt();
       e=sc.nextInt();
	a = (int)(t*100);
	total = 99999;
	s = 0; value = 0;

	for( i=0; i<=b && i< total && value+i*25<=a; i++ )
	{
         s += i;
	  value += i*25;
	  for( j=0 ; j<=c && s+j< total && value+j*10<=a; j++ )
	  {
	    s += j;
	    value += j*10;
	    for( k=0 ; k<=d && s+k< total && value+k*5<=a; k++ )
	    {
		s += k;
		value += k*5;
		if( a-value<=e && s+a-value < total )
		{
		  total = s+a-value;
		  as=i;bs=j;cs=k;ds=a-value;
		}
		s -= k;
		value -= k*5;
	    }
	    s -= j;
	    value -= j*10;
	  }
	  s -= i;
	  value -= i*25;
    }
    if( total == 99999 )
	System.out.printf("NO EXACT CHANGE\n" );
    else System.out.printf( "%d %d %d %d\n", as, bs, cs, ds);
   }
  }
}

