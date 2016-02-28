import java.util.*;
public class Main {
 public static void main(String[] args){
  Scanner sc = new Scanner(System.in);
  int x[]=new int[1000], y[]=new int[1000];
  boolean sign[]=new boolean[1000];
  int a, b, n, m, i, ans;
        while( true )
        {
                n = 0;
                while( true )
                {
                        x[n]=sc.nextInt();
                        y[n]=sc.nextInt();
                        if( x[n] < 0 && y[n] < 0 ) return ;
                        if( x[n] == 0 && y[n] == 0 ) break;
                        sign[n] = false;
                        n++;
                }
                
                for( m=0, ans = 0; m<n; ans++ )
                {
                        a = 0;
                        b= 0;
                        for( i=0; i<n; i++ )
                        if( !sign[i] && x[i]>=a && y[i] >=b )
                        {
                                sign[i] = true;
                                m++;
                                a = x[i];
                                b = y[i];
                         }
                }
                
                System.out.printf( "%d\n", ans );
        }
     }
}                
