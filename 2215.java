//* @author:
import java.io.*;
import java.util.*;
public class Main {
   static int SZ=1005;
   public static void main(String[] args) throws Exception {
        int r,c,q;
        int sum;
        int i,j,x1,y1,x2,y2;
    int[][] area=new int[SZ][SZ];
    for(i=0;i< SZ;++i) area[i][0]=0;
    Scanner cin=new Scanner(System.in);
        int T=cin.nextInt();
    while(--T>=0) {
         r=cin.nextInt();
      c=cin.nextInt();
      for(i=0;i< r;++i)
           for(j=1;j<=c;++j){
        area[i][j]=cin.nextInt();
        area[i][j]+=area[i][j-1];
       }
       q=cin.nextInt();
       while(--q>=0)
           {
        x1=cin.nextInt();
        y1=cin.nextInt();
        x2=cin.nextInt();
        y2=cin.nextInt();
        sum=0;
        for(i=x1-1;i< x2;++i)
            sum+=area[i][y2]-area[i][y1-1];
              System.out.println("Absolutni hodnota pohodlnosti je "+sum+" bodu.");
            }
        System.out.println("");
        }
 }
}

