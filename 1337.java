import java.util.*;
public class Main {
  

 public static void main(String[] args){

    Scanner in = new Scanner(System.in);
	
   int ans[]=new int[300];
   int a[]=new int[100],d[]=new int[100],t[]=new int[100];

   int cas, i, j, n, temp;
   boolean key;
   cas=in.nextInt();

   while(( cas-- )!=0)
   {
    n=in.nextInt();
    for( i=0; i<n; i++ ){
      t[i]=in.nextInt();
      a[i]=in.nextInt();
      d[i]=in.nextInt();
    }
		
   for( i=0; i<=250; i++ )
 	ans[i] = 0;

  for( i=249; i>=0; i-- )
  {
	key = true;ans[i] = 99999999;
	for( j=0; j<n; j++ )
	{
         if( a[j] <= i && i+t[j] <= d[j] && ( temp = ans[i+t[j]] + t[j] ) < ans[i] ){
		ans[i] = temp;
              key = false;
         }
	}
	if( key ) ans[i] = ans[i+1];
		
   }
   System.out.printf( "%d\n", ans[0] );
  }
 }
}
