import java.util.*;
public class Main {
  
 static int value[][]=new int[50][50];
 static int ans,n;

static void calc()
{
	int i, j, temp, k, s;

	for( k=0; k< n-2; k++ )
	{
		s = 10000000;
		for( i = k+1; i < n; i++ )
		for( j = i+1; j < n; j++ )
		{
			if( (temp = (value[i][k]+value[j][k]-value[i][j])/2 ) < s )
				s = temp;
		}

		for( i = k+1; i < n; i++ ){
			value[i][k] -= s;
                    value[k][i] -= s;
              }
		ans += s;
	}
	ans += value[n-2][n-1];
}

 public static void main(String[] args){

    Scanner in = new Scanner(System.in);
	int i, j;
	
	while( in.hasNext())
	{
		n=in.nextInt();

		if( n == 0 ) break;

		for( i=0; i<n; i++ )
		{
			for( j=i+1; j<n; j++ )
			{
			  value[i][j]=in.nextInt();
				value[j][i] = value[i][j];
			}

			value[i][i] = 0;
		}

		ans = 0;

		calc();

		System.out.printf( "%d\n",ans );
	}

   }
}
		
