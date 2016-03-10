//* @author:
import java.util.*;
import java.math.*;
import java.io.FileReader;
public class Main {
    public static void main(String[] args) throws Exception{
        Scanner in=new Scanner(System.in);
        while (true) {
            int n;
            try {
                n=in.nextInt();
            }
            catch(Exception e) {return;}
            String []s=new String [n];
            for (int i=0;i< n;i++) s[i]=in.next();
            int m=s[0].length();
            String tp=new String();
            for (int i=m-1;i>=0;i--) for (int j=n-1;j>=0;j--)
                tp=tp.concat(String.valueOf(s[j].charAt(i)));
            int lastone=0;
            for (int i=tp.length()-1;i>=0;i--)
                if (tp.charAt(i)!='_') {lastone=i;break;}
            for (int i=0;i< tp.length();i++) {
                if (tp.charAt(i)=='_') System.out.print(' ');
                else if (tp.charAt(i)=='\\') System.out.println();
                else System.out.print(tp.charAt(i));
                if (i==lastone) break;
            }
            System.out.println();
            System.out.println();
        }
    }
}

