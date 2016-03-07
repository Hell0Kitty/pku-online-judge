import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
public class Main {
    public static void main(String[] args) throws IOException {
        BigInteger a;
        BigInteger b;
        BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
        long c=0,d=0;
        long n=0;
        while((n=Long.parseLong(stdin.readLine()))!=0){
        //for(n=1;n<=200;n++)   {
        b=new BigInteger(1+"");
        d=1;
            while(true){
                c=Long.parseLong(Long.toBinaryString(d));
                //a=new BigInteger(b.toString(2));
                //if(a.mod(new BigInteger(n+"")).toString().equals("0"))break;
                if(c%n==0) break;
                //b=b.add(new BigInteger("1"));
                d++;
            }
            System.out.println(Long.toBinaryString(d));
        }
    }
}