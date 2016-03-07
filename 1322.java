import java.util.*;
 public class Main{
  public static void main(String args[]){
      
      Scanner in=new Scanner(System.in);
     
      while(true){
       int c=in.nextInt();
       if(c==0) break;
       int n=in.nextInt();
       int m=in.nextInt();
       double arr[][]=new double[1002][101];
        if (m>c||m>n){   
         System.out.printf("0.000\n");
         continue;
        }
        if (n>1000) {
          if ((n%2)!=0) n = 1001;
          else     n = 1000;
        }
              
         arr[0][0] = 1;
         for (int i=1;i<=n;++i){
          arr[i][1] += arr[i-1][0];
          arr[i][c-1] += arr[i-1][c];
          for (int j = 1 ; j < c ; j++){
            arr[i][j-1] += arr[i-1][j] * j / c;
            arr[i][j+1] += arr[i-1][j] * (c-j) / c;       
          }
         }
         System.out.printf("%.3f\n",arr[n][m]);
        }
   }
}