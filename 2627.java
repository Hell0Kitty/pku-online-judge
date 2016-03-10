//* @author
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
    static int[] bookHeight;
    static int n;
    static BigInteger b;
    public static void main(String[] args) throws Exception
    {
        readFile();
    }
    public static void readFile() throws Exception
    {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(
            br.readLine()," ");
        n = Integer.valueOf(st.nextToken());
        b = new BigInteger(st.nextToken());
        int iCount = 0;
        bookHeight = new int[n];
        while(iCount< n)
        {
            bookHeight[iCount++] = Integer.valueOf(
                br.readLine());
        }
        process();
    }
    public static void defbug()
    {
        for(int i=0; i< bookHeight.length; i++)
            System.out.println(bookHeight[i]+" ");
        System.out.println();
    }
    public static void process()
    {
        Arrays.sort(bookHeight);
        BigInteger sum = BigInteger.valueOf(0L);
        BigInteger temp;
        int iCount = 0;
        for(int i=bookHeight.length-1; i>=0; i--)
        {
            sum = sum.add(BigInteger.valueOf(
                    (long)(bookHeight[i])));
            temp = sum.max(b);
            iCount++;
            if(temp.equals(sum))
                break;
        }
        System.out.print(iCount);
    }
}

