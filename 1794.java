import java.util.Scanner;
public class Main {


  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

	int cas, k;

	cas=sc.nextInt();

	for( k=1; k<=cas; k++ )
	{
            int s1[]=new int[60010], s2[]=new int[60010];
            	int i, n, m, a, b, ans;

		n=sc.nextInt();
              m=sc.nextInt();
		
		for( i=0; i<n; i++ )
		{
                    a=sc.nextInt();
                    b=sc.nextInt();
			s1[a]++;
			s2[b]++;
		}

		for( i=1; i<=n+m; i++ ){
			s1[i] += s1[i-1];
                   s2[i] += s2[i-1];
              }

		ans = 0;
		for( i=0; i<m; i++ )
		{
                     a=sc.nextInt();
                     b=sc.nextInt();
			if( s1[a] >= s2[b] )
				ans += s1[a] - s2[b-1];
			else
				ans += s2[b] - s1[a];
		}

		System.out.printf( "Scenario #%d:\n", k );
		System.out.printf( "%d\n\n", ans );
	}

   }
}


