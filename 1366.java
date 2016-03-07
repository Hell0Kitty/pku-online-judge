import java.util.*;
import java.io.*;

public class Main
{
    public static BufferedInputStream bis;
    public static StringBuilder str;
    public static char[][] rules;
    public static StringBuilder[] words;
    public static int k;
    public static void main(String[] args) throws Exception
    {
        bis = new BufferedInputStream(System.in);
        
	rules = new char[8][4];
	Map<String,Boolean> exist = new HashMap<String,Boolean>();
	words = new StringBuilder[40000];
	StringBuilder start,result, previous, key;
        str = new StringBuilder();
        start = new StringBuilder();
	result = new StringBuilder();
	previous = new StringBuilder();
        key = new StringBuilder();
        for(int i = 0; i < 40000; i++)
        {
            words[i] = new StringBuilder();
        }
	while(true)
	{
	    int n = (int)readLong();
            if(n == -1)
            {
                break;
            }
            k = 0;
            start.delete(0,start.length());
	    start.append(readString());
            readRules();
	    long s = readLong();
            result.delete(0,result.length());
	    result.append(start);
	    exist.clear();

            words[k].delete(0,words[k].length());
            words[k].append(lowest(result));
            k++;
	    for(int j=0;j<s;j++)
	    {
                previous.delete(0,previous.length());
		previous.append(result);
		result.delete(0,result.length());
	        for(int i=0;i<n;i++)
	        {
	            int i1 = (i-2+n)%n;
		    int i2 = i;
		    int i3 = (i+1)%n;
                    key.delete(0,key.length());
		    key.append(previous.charAt(i1));
		    key.append(previous.charAt(i2));
		    key.append(previous.charAt(i3));
		    result.append(getKey(key));
	        }
		String lw = lowest(result);
                
		if(exist.get(lw) == null)
		{
		    exist.put(lw,true);
		    words[k].delete(0,words[k].length());
                    words[k].append(lw);
                    k++;
		}else
		{
		    int index = find(lw);
		    int p = j + 1 - index;
		    long resultIndex = ((s - j) % p - 1 + p)%p  + index;
                    result.delete(0,result.length());
                    result.append(words[(int)resultIndex]);
		    break;
		}
	    }

	    System.out.println(lowest(result));
	}
    }
    
    public static int find(String lw)
    {
        int index = 0;
        for(int i = 0; i < k; i++)
        {
            boolean reached = true;
            for(int j = 0; j < lw.length(); j++)
            {
                if(lw.charAt(j) != words[i].charAt(j))
                {
                    reached = false;
                    break;
                }
            }
            if(reached)
            {
                index = i;
                break;
            }
        }
        return index;
    }
    
    public static char getKey(StringBuilder sb)
    {
        char result = '\0';
        for(int i = 0; i < 8; i++)
        {
            boolean reached = true;
            for(int j = 0; j < 3; j++)
            {
                if(rules[i][j] != sb.charAt(j))
                {
                    reached = false;
                    break;
                }
            }
            if(reached)
            {
                result = rules[i][3];
                break;
            }
        }
        return result;
    }
    
    public static void readRules() throws Exception
    {
        for(int i = 0; i < 8; i++)
	{
            for(int j = 0; j < 4; j++)
            {
                while(true)
                {
                    int bt = bis.read();
                    if(Character.isLetter(bt))
                    {
                        rules[i][j] = (char)bt;
                        break;
                    }
                }
            }
	}
    }
    
    static String lowest(StringBuilder sb)
    {
        String p = sb.toString();
	String min = p;
	int n = p.length();
	for(int i=0;i<n;i++)
	{
	    String next = p.substring(n-1,n) + p.substring(0,n-1);
	    if(next.compareTo(min) < 0)
	    {
	        min = next;
	    }
	    p = next;
	}
	return min;
    }
    
    public static long readLong() throws Exception
    {
        long num = 0;
        while(true)
        {
            int bt = bis.read();
            if(bt == -1)
            {
                return -1;
            }
            if(Character.isDigit(bt))
            {
                num = num*10 + bt - '0';
                break;
            }
        }
        
        while(true)
        {
            int bt = bis.read();
            if(!Character.isDigit(bt))
            {
                break;
            }
            num = num*10 + bt - '0';
        }
        return num;
    }
    
    public static StringBuilder readString() throws Exception
    {
        str.delete(0,str.length());
        while(true)
        {
            int bt = bis.read();
            if(Character.isLetter(bt))
            {
                str.append((char)bt);
                break;
            }
        }
        
        while(true)
        {
            int bt = bis.read();
            if(!Character.isLetter(bt))
            {
                break;
            }
            str.append((char)bt);
        }
        
        return str;
    }
}
