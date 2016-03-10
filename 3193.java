 //* @author: Yeming Hu"cslittleye@gmail.com"
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
    String mn = sc.nextLine();
    Scanner lmn = new Scanner(mn);
    int m = lmn.nextInt();
    int n = lmn.nextInt();
    String[] phrases = new String[m];
    for(int i = 0; i < m; i++)
    {
        phrases[i] = sc.nextLine();
    }
    Arrays.sort(phrases);
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        String line = sc.nextLine();
        int index = Arrays.binarySearch(phrases,line);
        if(index >= 0)
        {
            result++;
        }else
        {
            index = -1 * index - 1;
        if(index == m)
        {
            continue;
        }
        if(phrases[index].startsWith(line))
        {
            result++;
        }
        }
    }
    System.out.println(result);
    }
}

