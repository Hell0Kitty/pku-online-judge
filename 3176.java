import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int height = cin.nextInt();
        int[][] tree = new int[height][height];
        int[][] max = new int[height][height];
        int maxValue = 0;
        int left, right = 0;

        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                tree[i][j] = cin.nextInt();
//              System.out.print(tree[i][j] + " ");
            }
//          System.out.println("\n");
        }

        max[0][0] = tree[0][0];



        for(int i = 1; i < height; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j == 0)
                    max[i][j] = max[i-1][j] + tree[i][j];
                else if(j == i)
                    max[i][j] = max[i-1][j-1] + tree[i][j];
                else
                {
                    if(max[i-1][j-1] >= max[i-1][j])
                        max[i][j] = max[i-1][j-1] + tree[i][j];
                    else
                        max[i][j] = max[i-1][j] + tree[i][j];
                }
            }
        }

        for(int j = 0; j < height; j++)
        {
            if(max[height-1][j] > maxValue)
                maxValue = max[height-1][j];
        }

        System.out.println(maxValue);


    }

}

