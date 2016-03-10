import java.util.*;

 public class Main {

     public static void main(String[] args) {
         Scanner cin = new Scanner(System.in);

         int num = Integer.valueOf(cin.nextLine()).intValue();
         int[][] array = new int[num][num];

         int max = 0;
         int index = 0;

         for(int i = 0; i < num; i++)
         {
             int rsum = 0;
             for(int j = 0; j < num; j++)
             {
                 array[i][j] = cin.nextInt();
                 if(array[i][j] == 3)
                     rsum++;
                 if(rsum > max)
                 {
                     max = rsum;
                     index = i;
                 }
             }
         }
         System.out.println(index + 1);

     }
}
