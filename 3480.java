//* @author:
import java.util.*;
import java.math.*;
public class Main {
    public static void main(String[] args)  throws Exception{
        int nn;
        Scanner in=new Scanner(System.in);
        nn=in.nextInt();
        while ((nn--)!=0) {
            int n=in.nextInt();
            long ans=0,max=0;
            for (int i=1;i<=n;i++) {
                long j=in.nextLong();
                if (j>max) max=j;
                ans=ans^j;
            }
            if ((ans!=0)&&(max>1)||(ans==0)&&(max<=1)) System.out.println("John");
            else System.out.println("Brother");
        }
    }
}

