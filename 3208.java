import java.util.Scanner;
public class Main {

static int s[][]=new int[14][4];

static int to[][]=new int[4][10];

static void doit( ) {
    int i, j, k;

    for( i=0; i< 3; i++ )
    for( j=0; j< 10; j++ )
        to[i][j] = 0;
    to[0][6] = 1;
    to[1][6] = 2;
    to[2][6] = 3;
    for( j=0; j< 10; j++ )
        to[3][j] = 3;

    s[0][3] = 1;

    for( i=1; i< 14; i++ )
    for( j=0; j< 4; j++ )
    for( k=0; k< 10; k++ )
        s[i][j] += s[i-1][to[j][k]];
}


 public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);

  int i, j, n, k, t;
  long ans;

  doit( );
  t=sc.nextInt();

  while(( t-- )!=0){
     n=sc.nextInt();
     ans = 0;
     k = 0;
     for( i=0; i< 14 && s[i][0] < n; i++ )
            ;
    while( (i-- )!=0) {
      for( j=0; j< 10 && s[i][to[k][j]] < n; j++ )
        n -= s[i][to[k][j]];
     ans = ans*10+j;
     k = to[k][j];
      }
      System.out.printf( "%d\n", ans );
  }
 }
}

