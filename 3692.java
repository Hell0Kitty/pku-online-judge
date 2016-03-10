//* @author: Yeming Hu"cslittleye@gmail.com"
import java.util.*;

public class Main
{
    public static int b;
    public static int g;
    public static int m;
    public static boolean[][] graph;
    public static boolean[] checked;
    public static int[] link;

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
    graph = new boolean[200][200];
    checked = new boolean[200];
    link = new int[200];
    int t = 0;

    while(true)
    {
        b = sc.nextInt();
        g = sc.nextInt();
        m = sc.nextInt();

        if(b == 0 && g == 0 && m == 0)
        {
            break;
        }

        Arrays.fill(checked,false);
        Arrays.fill(link,-1);

        for(int i = 0; i < b; i++)
        {
            Arrays.fill(graph[i],true);
        }
        for(int i = 0; i < m; i++)
        {
            int a = sc.nextInt();
        int b = sc.nextInt();
        graph[a-1][b-1] = false;
        }
        int ans = 0;
        for(int i = 0; i < b; i++)
        {
            Arrays.fill(checked,false);
        if(find(i))
        {
            ans++;
        }
        }
        System.out.println("Case " + (++t) + ": " + (g+b-ans));
    }
    }

    public static boolean find(int a)
    {
        for(int i = 0; i < g; i++)
    {
        if(graph[a][i] && !checked[i])
        {
        checked[i] = true;
        if(link[i] == -1 || find(link[i]))
        {
            link[i] = a;
            return true;
        }
        }
    }
    return false;
    }
}

