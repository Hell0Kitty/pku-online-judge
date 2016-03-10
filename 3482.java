//* @author:
import java.util.*;
import java.io.FileReader;
import java.math.*;
public class Main {
    public static void main(String[] args)  throws Exception{
        int n=0;
        int [] dx=new int[1000];
        Scanner in=new Scanner(System.in);
        int fir=1;
        while (true) {
            String s;
            try {
                while (true) {
                    s=in.nextLine();
                    if (s.length()!=0) break;
                }
            }
            catch(Exception e) {
                break;
            }
            if (fir==1) fir=0;
            else System.out.println();
            int ll=s.length();
            n=0;
            for (int i=0;i< ll;i++) if (s.charAt(i)>0x20) {
                dx[s.charAt(i)]=n++;
            }
            while (true) {
                try{
                    s=in.nextLine();
                }
                catch(Exception e2) {
                    return;
                }
                int l=s.length();
                if (l==0) break;
                int max=0;
                for (int i=0;i< l;i++)
                 if (s.charAt(i)>0x20&&max< dx[s.charAt(i)]) max=dx[s.charAt(i)];
                BigInteger ans=BigInteger.ZERO;
                for (int dig=max+1;dig<=n;dig++) {
                    BigInteger tmp=BigInteger.ZERO;
                    for (int i=0;i< l;i++) if (s.charAt(i)>0x20) {
                        tmp=tmp.multiply(BigInteger.valueOf(dig));
                        tmp=tmp.add(BigInteger.valueOf(dx[s.charAt(i)]));
                    }
                    ans=ans.add(tmp);
                }
                System.out.println(ans);
            }
        }
    }
}


