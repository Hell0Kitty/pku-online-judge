import java.io.*;
import java.util.*;
import java.math.*;
/**
 *
 * @author gongshaoqing
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        // TODO code application logic here
        Scanner cin=new Scanner(System.in);
        String str;
        int inbas,oubas;
        while(cin.hasNext())
        {
            str=cin.next();
            inbas=cin.nextInt();
            oubas=cin.nextInt();
            BigInteger tmp=new BigInteger(str,inbas);

            str=tmp.toString(oubas);
            int len=str.length();
            if(len>7)System.out.println("  ERROR");
            else
            {
                str=str.toUpperCase(Locale.FRENCH);
                for(int i=0;i< 7-len;i++)System.out.print(" ");
                System.out.println(str);
            }
        }
    }

}
