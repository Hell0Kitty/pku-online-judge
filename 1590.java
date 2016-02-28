import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.io.BufferedInputStream;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
	Map<Character,Character> map = new HashMap<Character,Character>();
	map.put('A','A');
	map.put('E','3');
	map.put('H','H');
	map.put('I','I');
	map.put('J','L');
	map.put('L','J');
	map.put('M','M');
	map.put('O','O');
	map.put('S','2');
	map.put('T','T');
	map.put('U','U');
	map.put('V','V');
	map.put('W','W');
	map.put('X','X');
	map.put('Y','Y');
	map.put('Z','5');
	map.put('1','1');
	map.put('2','S');
	map.put('3','E');
	map.put('5','Z');
	map.put('8','8');
        while(sc.hasNext())
	{
	    String original = sc.next();
	    boolean isPalindrome = true;
	    boolean isMirrored = true;
	    int len = original.length();
	    for(int i = 0; i < len/2; i++)
	    {
	        if(original.charAt(i) != original.charAt(len - i - 1))
		{
		    isPalindrome = false;
		    break;
		}
	    }
	    for(int i = 0; i <= len/2; i++)
	    {
	        Character mirror = map.get(map.get(original.charAt(len - i -1)));
	        if(mirror == null || original.charAt(i) != map.get(mirror).charValue())
		{
		    isMirrored =false;
		    break;
		}
	    }
	    System.out.print(original + " -- is ");
	    if(isPalindrome && isMirrored)
	    {
	        System.out.println("a mirrored palindrome.");
	    }else if(isPalindrome)
	    {
	        System.out.println("a regular palindrome.");
	    }else if(isMirrored)
	    {
	        System.out.println("a mirrored string.");
	    }else
	    {
	        System.out.println("not a palindrome.");
	    }
	    System.out.println();
	}
    }
}
