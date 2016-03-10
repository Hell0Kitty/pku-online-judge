//* @author
import java.util.*;
import java.io.*;
import java.math.*;

public class Main {

    /**
     * @param args the command line arguments
     */
    static BigInteger []a=new BigInteger[10005];
    public static void main(String[] args) {
       // TODO code application logic here
        int n;
        a[0]=BigInteger.ONE;
        a[1]=BigInteger.ONE;
        for(int i=2;i<=10000;i++) a[i]=a[i-1].add(a[i-2]);
        Scanner cin=new Scanner(System.in);
        while(cin.hasNext()){
            n=cin.nextInt();
            BigInteger ans=a[n-1].pow(4);
            ans=ans.add(a[n].pow(2).multiply(a[n-2].pow(2)));
            ans=ans.add(BigInteger.valueOf(6).multiply(a[n].multiply(a[n-2].multiply(a[n-1].pow(2)))));
            ans=ans.multiply(BigInteger.valueOf(2)).add(BigInteger.valueOf(2));
            String s=ans.toString();
            StringBuffer sbf=new StringBuffer();
            int p=0;
            for(int i=s.length()-1;i>=0;i--){
                p++;
            sbf.append(s.charAt(i));
                if(p==3&&i>0){
                    sbf.append(",");
                    p=0;
                }
            }
            sbf.reverse();
            System.out.println(sbf.toString());
        }

    }

}

