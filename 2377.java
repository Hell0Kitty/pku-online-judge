import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] mind = new int[n];
        boolean[] reached = new boolean[n];
        int[][] dist = new int[n][n];

        for(int i = 0; i < n; i++)
        {
            mind[i] = 0;
            reached[i] = false;

            for(int j = 0; j < n; j++)
            {
                dist[i][j] = 0;
            }
        }

        for(int i = 0; i < m; i++)
        {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();

            if(dist[a-1][b-1] < c)
            {
                dist[a-1][b-1] = c;
                dist[b-1][a-1] = c;
            }
        }

        boolean isPossible = true;
        int total = 0;
        reached[0] = true;
        for(int j = 0; j < n; j++)
        {
            if(!reached[j] && dist[j][0] > mind[j])
            {
                mind[j] = dist[j][0];
            }
        }
        for(int i = 1; i < n; i++)
        {
            int max = 0;
            int index = -1;
            for(int j = 0; j < n; j++)
            {
                if(!reached[j] && mind[j] > max)
                {
                    max = mind[j];
                    index = j;
                }
            }
            if(index == -1)
            {
                isPossible = false;
                break;
            }
            reached[index] = true;
            total += mind[index];
            for(int j = 0; j < n; j++)
            {
                if(!reached[j] && dist[j][index] > mind[j])
                {
                    mind[j] = dist[j][index];
                }
            }
        }
        if(isPossible)
        {
            System.out.println(total);
        }else
        {
            System.out.println(-1);
        }
    }

}

