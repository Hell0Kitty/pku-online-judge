import java.util.Scanner;


public class Main {
 public static void main(String[] args)
  {
  Scanner in = new Scanner(System.in);
   while(true)
    {
	String first = in.next();
	String second = in.next();
	//System.out.println(first.length()+" "+second.length());
	if(first.equals("0") && second.equals("0"))
	{
		break;
	}
	int carry = 0;
	int result = 0;
	int n = first.length();
	int k = 0;
	if(first.length() > second.length())
	{
		n = first.length();
		k = first.length() - second.length();
		for(int i = 0; i < k; i++)
			second = '0'+second;
	}
	else if(first.length() < second.length())
	{
		n = second.length();
		k = second.length() - first.length();
		for(int i = 0; i < k; i++)
			first = '0'+first;
	}


	//System.out.println("first:"+first+"second:"+second+"n:"+n+"k"+k);
	for(int i = n-1; i>=0; i--)
	{
		int m = (first.charAt(i)-'0')+(second.charAt(i) -'0')+carry;
		if(m>9)
		{
			result++;
			carry = 1;
		}
		else
			carry =0;
	}


	//输出处理
    if( result == 0)
    {
    	System.out.println("No carry operation.");
    }
    else if(result == 1)
    {
    	System.out.println("1 carry operation.");
    }
    else
    {
    	System.out.println(result + " carry operations.");
    }
  }
 }
}

