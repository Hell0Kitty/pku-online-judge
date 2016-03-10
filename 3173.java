 import java.util.*;

 public class Main {

     public static void main(String[] args) {
         Scanner cin = new Scanner(System.in);

         String[] str = cin.nextLine().split(" ");
         int N = Integer.valueOf(str[0]).intValue();
         int S = Integer.valueOf(str[1]).intValue();

         int[][] Tri = new int[N][N];

         for(int j = 0; j < N; j++)
         {
             for(int i = 0; i <= j; i++)
             {
                 Tri[i][j] = S;

                 if(S == 9)
                     S = 1;
                 else
                     S++;
             }
         }
         print(Tri);
     }


     private static void print(int[][] tri)
     {
         for(int i = 0; i < tri.length; i++)
         {
             for( int j = 0; j < tri.length - 1; j++)
             {
                 if(tri[i][j] < 1 || tri[i][j] > 9)
                     System.out.print(" ");
                 else
                     System.out.print(tri[i][j]);
                 System.out.print(" ");

             }
             System.out.println(tri[i][tri.length -1]);
         }
     }
}

