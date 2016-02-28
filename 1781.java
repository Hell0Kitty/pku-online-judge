import java.io.*;
public class Main
{
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		InputStreamReader is=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(is);
		while(true)
		{
			String s=in.readLine();
			if(s.equals("00e0"))break;
			int a=(int)(((s.charAt(0)-'0')*10+s.charAt(1)-'0')*Math.pow(10, s.charAt(3)-'0'));
			s=Integer.toBinaryString(a);
			s=s.substring(1)+s.charAt(0);
			a=Integer.parseInt(s, 2);
			System.out.println(a);
		}
	}
}