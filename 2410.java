//* @author:
import java.util.*;
import java.math.*;

public class Main {
 static String []s = new String [32];
 static int []memory = new int [32];
 static int []ans = new int [32];
 static int MAX = 256;

 static void deal()
 {
  Arrays.fill(memory, 0);
  int accu = 0, pc = 0, i = 0, j, k, pos;
  String str;
  while (true)
  {
   str = s[i].substring(0, 3);
   pc = (pc + 1) % 32;
   pos = 0;
   for (j = 3; j < 8; j++)
     pos = (pos < < 1) + (s[i].charAt(j) - '0');
     if (str.compareTo("000") == 0)
     {
        if (accu == 0)
          s[pos] = "00000000";
        else
         {
	    j = accu;
	    k = 0;
	    while (j != 0)
	    {
	       j >>= 1;
	        k++;
	    }
	    s[pos] = "";
	    for (j = 0; j < 8 - k; j++)
	         s[pos] += "0";
	    s[pos] += Integer.toBinaryString(accu);
          }
      }
     else if (str.compareTo("001") == 0)
     {
	accu = 0;
	for (j = 0; j < 8; j++)
	 accu = (accu < < 1) + (s[pos].charAt(j) - '0');
	accu %= MAX;
     }
    else if (str.compareTo("010") == 0 && accu == 0)
	pc = pos;
    else if (str.compareTo("100") == 0)
     {
	accu--;
	if (accu < 0)
	 accu += MAX;
     }
     else if (str.compareTo("101") == 0)
	   accu = (accu + 1) % MAX;
     else if (str.compareTo("110") == 0)
	  pc = pos;
     else if (str.compareTo("111") == 0)
	break;
      i = pc;
     }
	if (accu == 0)
	    System.out.println("00000000");
	else
	{
	  i = j = 0;
	  while (accu != 0)
	  {
	    ans[i++] = accu % 2;
	    accu >>= 1;
	   }
	  for (j = 0; j < 8 - i; j++)
	    System.out.print("0");
	   i--;
	  while (i >= 0)
	  {
	    System.out.print(ans[i]);
	    i--;
	   }
	   System.out.println();
	}
       }

     static void input()
      {
	Scanner cin = new Scanner (System.in);
	int i;
	while (cin.hasNext())
	{
	 for (i = 0; i < 32; i++)
	   s[i] = cin.next();
	 deal();
	}
     }

    public static void main (String []args)
	{
	input();
	}
 }

