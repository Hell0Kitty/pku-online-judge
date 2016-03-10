import java.io.*;
public class Main
{
    static int[] p;
    static int a,k;
    public static void main(String[] args) throws IOException
    {
        InputStreamReader is=new InputStreamReader(System.in);
        BufferedReader in=new BufferedReader(is);
        a=Integer.parseInt(in.readLine());
        p=new int[a];
        String[] ss=in.readLine().split(" ");
        long total=0;
        for(int i=0;i< a;i++){
            p[i]=Integer.parseInt(ss[i]);
            total+=p[i];
        }

        k=Integer.parseInt(in.readLine());
        int v=k+a-1;
        long min=total/v;
        long high=total;
        while(high>min)
        {
            long mid=(high+min)/2;
            if(f(mid)) high=mid;
            else min=mid+1;
        }
        System.out.println(min);
    }
    static boolean f(long t)
    {
        long u=t;
        for(int i=0;i< a;i++)
        {
            if(p[i]<=t)continue;
            long sy=p[i]-t;
            u-=sy/(k-1);
            if(sy%(k-1)!=0)
                u--;
        }
        if(u< 0) return false;
        else return true;
    }
}

