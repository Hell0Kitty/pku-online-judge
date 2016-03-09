import java.io.*;
public class Main
{
    static int[] star=new int[32002];
    static int[] lev=new int[15000];
    public static void main(String[] args) throws NumberFormatException, IOException
    {
        InputStreamReader is=new InputStreamReader(System.in);
        BufferedReader in=new BufferedReader(is);
        int a=Integer.parseInt(in.readLine());
        int n=a;
        while((a--)!=0)
        {
            String[] ss=in.readLine().split(" ");
            int b=Integer.parseInt(ss[0]);
            lev[sum(b+1)]++;
            update(b+1);
        }
        for(int i=0;i< n;i++)
            System.out.println(lev[i]);
    }

    static int lowbit(int n)
    {
        return n&(-n);
    }

    static int sum(int n)
    {
        int r=0;
        while(n!=0)
        {
            r+=star[n];
            n-=lowbit(n);
        }
        return r;
    }

    static void update(int n)
    {
        while(n< 32002)
        {
            star[n]++;
            n+=lowbit(n);
        }
    }
}

