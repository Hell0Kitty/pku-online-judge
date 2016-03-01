import java.util.*;
import java.math.BigDecimal;
import java.lang.String;

class Main
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        BigDecimal bd;
        String out;
        int l, i;
        long n;
        while (cin.hasNext())
        {
          n = cin.nextLong();
          if (n == 0)
         	break;
          if (n <= 2)
          {
           System.out.println("1.00000000000000");
           continue;
           }
           bd = Make(n);
           bd = power(bd, n - 2);
	    out = bd.toString().substring(0, 16);
           System.out.println(out);
        }
    }

static BigDecimal power(BigDecimal bd, long n)
{
    	BigDecimal ans;
    	if (n == 0)
    	{
    		return BigDecimal.ONE;
    	}
    	ans = power(bd, n / 2);
    	ans = ans.multiply(ans);
    	if (n % 2 == 1)
    	{
    		ans = ans.multiply(bd);
    	}
    	if (ans.toString().length() > 50)
    	{
    		ans = new BigDecimal(ans.toString().substring(0, 50));
    	}
    	return ans;
    }

    static BigDecimal Make(long N)
    {
    	String s = "";
    	long v = N - 1;
    	int i;
    	for (i = 0; i < 50; i++)
    	{
    		v = (v % N) * 10;
    		s += v / N;
    	}
    	s = "0." + s;
    	return new BigDecimal(s);
    }
}

