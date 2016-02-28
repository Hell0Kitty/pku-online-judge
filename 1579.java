import java.util.Scanner;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

	public static void main(String[] args) throws Exception{
		
         int [][][]w = new int[21][21][21];
          for(int i=0;i<21;i++){
             for(int j=0;j<21;j++){
              for(int k=0;k<21;k++){
               if(i==0||j==0||k==0)
                w[i][j][k] = 1;
               else{
                if(i<j&&j<k)
                  w[i][j][k] = w[i][j][k-1] + w[i][j-1][k-1] - w[i][j-1][k];
               else
                  w[i][j][k] = w[i-1][j][k] + w[i-1][j-1][k] + w[i-1][j][k-1] - w[i-1][j-1][k-1];
              }
            }
          }
         }
		
        Scanner  in = new Scanner(System.in);
        String input = new String();
        while(!(input=in.nextLine()).equals("-1 -1 -1")) {
          StringTokenizer toke = new StringTokenizer(input);
          int a = Integer.parseInt(toke.nextToken());
          int b = Integer.parseInt(toke.nextToken());
          int c = Integer.parseInt(toke.nextToken());
			
          int result = 0;
          if (a<=0||b<=0||c<=0)
            result = 1;
          else {
            if(a>20||b>20||c>20)
             result = w[20][20][20];
            else
              result = w[a][b][c];
          }
         System.out.println("w("+a+", "+b+", "+c+") = "+result);
     }
 }
	
}