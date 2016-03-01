import java.util.Scanner;

public class Main {
public static int[][] org;
public static int[][] m;
public static int[][] f = new int[4][1];
public static void main(String[] args) {
   Scanner cin = new Scanner(System.in);
   while(cin.hasNext()) {
    int n = cin.nextInt();
    if(test(n))
     continue;
    reset();
    n = n-6;
    while(n != 0) {
     if(n % 2 != 0) {
      org = mul(org, m);
     }
     n = n / 2;
     m = mul(m, m);
    }

    f = mul(org, f);
    System.out.println(f[0][0]%2005);
   }
}

private static int[][] mul(int[][] a, int[][] b) {
   int row = a.length;
   int col = b[0].length;
   int[][] test = new int[row][col];
   for (int i = 0; i< row; i++) {
    for (int j = 0; j< col; j++) {
     for (int k = 0; k< a[0].length; k++) {
      test[i][j]=test[i][j]+a[i][k]*b[k][j];
     }
     test[i][j] = test[i][j] % 2005;
    }
   }
   return test;
}


private static void reset() {
   org = new int[4][4];
   int size = org.length;
   for(int i=0; i< size; i++) {
    org[i][i] = 1;
   }
   m = new int[4][4];
   m[0][0] = 1;
   m[0][1] = 0;
   m[0][2] = 1;
   m[0][3] = 1;
   for(int i=1; i< size; i++) {
    m[i][i-1] = 1;
   }
   f[0][0] = 25;
   f[1][0] = 15;
   f[2][0] = 9;
   f[3][0] = 6;
}

private static boolean test(int n) {
   if(n == 3) {
    System.out.println(6);
    return true;
   }
   else if(n == 4) {
    System.out.println(9);
    return true;
   }
   else if(n == 5) {
    System.out.println(15);
    return true;
   }
   else if(n == 6) {
    System.out.println(25);
    return true;
   }else if(n == 1) {
    System.out.println(2);
    return true;
   }else if(n == 2) {
    System.out.println(4);
    return true;
   }else if(n == 0) {
    System.out.println(1);
    return true;
   }
   return false;
}

}


