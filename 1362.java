import java.util.*;

public class Main
{
    public static final int max = 30;
    public static void main(String[] args)
    {
        int[] weights = new int[max];
	int p = 2;
	for(int i = 0; i < max; i++)
	{
	    weights[i] = p - 1;
	    p *= 2;
	    //System.out.println(weights[i]);
	}
	
	Scanner sc = new Scanner(System.in);
	int tc = sc.nextInt();
	for(int i = 0; i < tc; i++)
	{
	    int[] digits = new int[max];
	    int num = sc.nextInt();
	    int out = num;
	    for(int j = max - 1; j >= 0; j--)
	    {
	        if(num == 0)
		{
		    break;
		}

	        if(num < weights[j])
		{
		    continue;
		}else if(num == 2 * weights[j])
		{
		    digits[j] = 2;
		    num -= 2*weights[j];
		}else
		{
		    digits[j] = 1;
		    num -= weights[j];
		}
	    }
	    boolean bg = true;
	    System.out.print(out + " [");
	    for(int j = 0; j < max; j++)
	    {
	        if(digits[j] != 0)
		{
		    if(!bg)
		    {
		        System.out.print(",");
		    }else
		    {
		        bg = false;
		    }
		    if(digits[j] == 1)
		    {
		        System.out.print(j);
		    }else
		    {
		        System.out.print(j + "," +j);
		    }
		}
	    }
	    System.out.println("]");
	}
    }
}
