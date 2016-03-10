 //* @author: Yeming Hu"cslittleye@gmail.com"
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
    while(sc.hasNext())
    {
        long a = sc.nextLong();
        long b = sc.nextLong();
        double c = sc.nextDouble();
        double d = sc.nextDouble();
        int steps = 0;
        if(a > b)
        {
            long temp = a;
        a = b;
        b = temp;
        }
        while(true)
        {
            if(c > d)
        {
            double temp = c;
            c = d;
            d = temp;
        }

        if(a >= c && b >=d)
        {
            break;
        }else if(b < d)
        {
            d = d/2;
            steps++;
        }else
        {
            c = c/2;
            steps++;
        }
        }
        System.out.println(steps);
    }
    }
}

