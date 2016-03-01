//* @author: 82638882@163.com
import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  while(true)
   {
	String s=in.next();
	String[] s1=s.split("\\+");
	String[] s2=s1[1].split("\\=");
	StringBuffer b1=new StringBuffer(s1[0]);
	StringBuffer b2=new StringBuffer(s2[0]);
	StringBuffer b3=new StringBuffer(s2[1]);
	b1=b1.reverse();
        b2=b2.reverse();
	b3=b3.reverse();
	int a1=Integer.parseInt(b1.toString());
	int a2=Integer.parseInt(b2.toString());
	int a3=Integer.parseInt(b3.toString());
	if(a1+a2==a3) System.out.println("True");
	else System.out.println("False");
    }
  }
}

