import java.io.*;
import java.util.*;
import java.math.*;
public class Main 
{
    static int n,m,match[]=new int[201];
    static boolean mat[][]=new boolean[201][201],v[]=new boolean[201];
    static boolean findmatch(int pre)
    {
        int i;
        for(i=0;i<m;i++)
        {
            if(mat[pre][i]&&!v[i])
            {
                v[i]=true;
                int buf=match[i];
                match[i]=pre;
                if(buf==-1||findmatch(buf))return true;
                match[i]=buf;
            }
        }
        return false;
    }
    static int bmatch()
    {
        int ret=0,i;
        for(i=0;i<n;i++)
        {
            Arrays.fill(v, false);
            if(findmatch(i))ret++;
        }
        return ret;
    }
    public static void main(String args[]) throws Exception {
        Scanner cin=new Scanner(System.in);
        int t=cin.nextInt(),k,a,b;
        while(t-->0)
        {
            m=n=cin.nextInt();
            int i,j;
            for(i=0;i<n;i++)for(j=0;j<n;j++)mat[i][j]=false;
            k=cin.nextInt();
            while(k-->0)
            {
                a=cin.nextInt();
                b=cin.nextInt();
                a--;
                b--;
                mat[a][b]=true;
            }
            Arrays.fill(match, -1);
            System.out.println(n-bmatch());
        }
    }
}

