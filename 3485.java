mport java.util.*;
import java.math.*;
import java.io.FileReader;
class SEG implements Comparable
{
    double b,e;
    SEG(double x,double y) {
        b=x;e=y;
    }
    public int compareTo(SEG other) {
        if (b< other.b) return -1;
        else if (b==other.b) {
            if (e< other.e) return -1;
            else if (e==other.e) return 0;
        }
        return 1;
    }
}
public class Main {
    public static void main(String[] args) throws Exception{
        Scanner in=new Scanner(System.in);
        while (true) {
            double l,d;
            int n;
            try {
                l=in.nextDouble();
            }
            catch (Exception e) {return;}
            d=in.nextDouble();
            n=in.nextInt();
            int ans=1;
            double d2=d*d,r,x,y;
            SEG []s=new SEG[n];
            for (int i=0;i< n;i++) {
                x=in.nextDouble();
                y=in.nextDouble();
                r=Math.sqrt(d2 - y*y);
                s[i]=new SEG(x-r,x+r);
            }
            Arrays.sort(s);
            double cr=s[0].e;
            for(int i=1;i< n;i++) {
                if (s[i].b>cr) {
                    cr=s[i].e;
                    ans++;
                }
                else if (cr>s[i].e) cr=s[i].e;
            }
            System.out.println(ans);
        }
    }
}


