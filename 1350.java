import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
	while(true)
	{
	    String num = sc.next();
	    if(num.equals("-1"))
	    {
	        break;
	    }
	    System.out.println("N="+num+":");
	    if(num.length()!=4||(num.charAt(0)==num.charAt(1)&&
	                               num.charAt(1)==num.charAt(2)&&
	                               num.charAt(2)==num.charAt(3)))
	    {
		System.out.println("No!!");
	    }else
	    {
	        int count = 0;
	        while(true)
		{
		    char[] chs = new char[num.length()];
		    for(int i = 0;i < num.length(); i++)
		    {
		        chs[i] = num.charAt(i);
		    }
		    Arrays.sort(chs);
		    int small = Integer.parseInt(new String(chs));
		    for(int i=0;i<chs.length/2;i++)
		    {
		        char temp = chs[i];
			chs[i] = chs[chs.length-1-i];
			chs[chs.length-1-i] = temp;
		    }
		    int big = Integer.parseInt(new String(chs));
		    int diff = big - small;
		    num = Integer.toString(diff);
		    count++;
		    System.out.println(big+"-"+small+"="+diff);
		    if(diff==6174 || diff == 0)
		    {
		        System.out.println("Ok!! " + count  + " times");
			break;
		    }
		}
	    }
	}
    }
}
