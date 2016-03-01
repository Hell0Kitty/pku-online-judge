import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        int num = Integer.valueOf(cin.nextLine()).intValue();

        for(int i = 0; i < num; i++)
        {
            String[] str = cin.nextLine().split(" ");
            BigInteger a = new BigInteger(str[0]);
            BigInteger b = new BigInteger(str[1]);
            BigInteger result = new BigInteger("0");

            if((a.intValue() >= 0 && b.intValue() >= 0)
                    || (a.intValue() < 0 && b.intValue() < 0))
            {
                int times = (Math.abs(b.intValue()-a.intValue())+1);
                result = result.add(a);
                result = result.add(b);
                result = result.multiply(new BigInteger(times + ""));
                result = result.divide(new BigInteger("2"));
            }
            else
            {
                int times1 = (Math.abs(b.intValue()-0)+1);
                BigInteger r1 = new BigInteger("0");
                r1 = r1.add(b);
                r1 = r1.multiply(new BigInteger(times1 + ""));
                r1 = r1.divide(new BigInteger("2"));

                int times2 = (Math.abs(a.intValue()-0)+1);
                BigInteger r2 = new BigInteger("0");
                r2 = r2.add(a);
                r2 = r2.multiply(new BigInteger(times2 + ""));
                r2 = r2.divide(new BigInteger("2"));

                result = r1.add(r2);
            }

            System.out.println("Scenario #" + (i+1) + ":");
            System.out.println(result.toString());
            if(i != num-1)
                System.out.println();
        }

    }

}

