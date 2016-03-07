import java.util.Scanner;
public class Main{

 public static void main(String args[])
{
  int cas, i, n, j, s1, s2;
  int a[]=new int[30];
  Scanner sc=new Scanner(System.in);
  cas=sc.nextInt();
	
  while((cas--)!=0 )
  {
   n=sc.nextInt();
		
   for( i=0; i<n; i++ )
   {
      a[i]=sc.nextInt();
   }

   for( i=0; i<n; i++ )
    if( a[i] == 1 )
    {
	s1 = s2 = 0;
	for( j=1; j<n; j++ )
	if( a[(j+i)%n] == 1 )
	{
	   if( j%2!=0 ) s1++;
	   else s2++;
	}
	if( s1 == s2 || s1 == s2+1 )
	{
	   System.out.printf( "YES\n" );
	   break;
	}
      }
		
     if( i >= n )
	System.out.printf( "NO\n" );
   }
  }
}