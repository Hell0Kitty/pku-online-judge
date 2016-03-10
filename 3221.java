//* @author:
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;
public class Main
{
    private static BufferedReader in;
    private static Scanner        scan;
    static
    {
        in = new BufferedReader(new InputStreamReader(System.in));
        scan = new Scanner(in);
    }
    private static int[][]  move = new int[][] { { 2, 4, 6 }, { 2, 6 }, { 0, 1, 3 }, { 2, 4 },
            { 0, 3, 5 }, { 4, 6 }, { 0, 1, 5 } };
    public void run() throws Exception
    {
        HashMap< String, Integer> map = new HashMap< String, Integer>();
        LinkedList< int[]> list = new LinkedList< int[]>();
        LinkedList< String> listString = new LinkedList< String>();
        int[] array = new int[] { 0, 1, 2, 3, 4, 5, 6 };
        String string = join(array);
        list.add(array);
        listString.add(string);
        map.put(string, 0);
        while (!list.isEmpty())
        {
            array = list.pop();
            string = listString.pop();
            int index = 0;
            for (; array[index] != 0; index++);
            for (int newIndex : move[index])
            {
                int[] newArray = array.clone();
                int tmp = newArray[index];
                newArray[index] = newArray[newIndex];
                newArray[newIndex] = tmp;
                String newString = join(newArray);
                if (!map.containsKey(newString))
                {
                    map.put(newString, map.get(string) + 1);
                    list.add(newArray);
                    listString.add(newString);
                }
            }
        }
        int n = Integer.parseInt(in.readLine());
        for (int i = 0; i < n; i++)
        {
            String str = in.readLine().trim();
            if (map.containsKey(str))
            {
                System.out.println(map.get(str));
            }
            else
            {
                System.out.println(-1);
            }
        }
    }
    private String join(int[] array)
    {
        StringBuilder buffer = new StringBuilder();
        for (int i : array)
        {
            buffer.append(i);
        }
        return buffer.toString();
    }
    public static void main(String[] args) throws Exception
    {
        new Main().run();
    }
}
