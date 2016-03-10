//* @author: 82638882@163.com
import java.io.*;
public class Main
{
    static long[] a=new long[]{
        1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000
    };
    static long[] b=new long[]{
        0,1,11,192,2893,38894,488895,5888896,68888897,788888898
    };
    static long[] c=new long[]{
        0,1,20,300,4000,50000,600000,7000000,80000000,900000000
    };
    public static void main(String[] args) throws IOException
    {
        InputStreamReader is=new InputStreamReader(System.in);
        BufferedReader in=new BufferedReader(is);
        while(true)
        {
            String[] ss=in.readLine().split(" ");
            long a=Long.parseLong(ss[0]);
            long b=Long.parseLong(ss[1]);
            if(a==-1&&b==-1)break;
            if(a==0)System.out.println(f(b)+1);
            else System.out.println(f(b)-f(a-1));
        }
    }
    static long f(long w)
    {
        int i;
        long q=w;
        for(i=0;i< 10;i++)
            if(a[i]>w)break;
        long sum=0;
        for(int j=i-1;j>0;j--)
        {
            long u=w/a[j];
            if(u>0)
                sum+=b[j]+(u-1)*c[j];
            w=w%a[j];
        }
        long total=0,oo=0;
        w=q;
        String s=w+"";
        for(int j=1;j< i-1;j++)
        {
            if(w%(a[j]*10)>=a[j]){
                total+=a[j]-1;
                oo+=total;
            }
            else oo+=w%(a[j]*10);
        }
        int bb=0;
        long yy=0;
        for(int g=1;g< s.length();g++)
        {
            if(s.charAt(g)!='0'){
                bb++;
                continue;
            }
            yy+=(Math.pow(10, s.length()-g-1)-1)*bb;
        }
        sum+=oo;
        sum+=yy;
        return sum;
    }
}

