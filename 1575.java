import java.io.*;
public class Main
{
	static int[][] sorce;
	public static void main(String[] args) throws IOException
	{
		InputStreamReader is=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(is);
		while(true)
		{
			String s=in.readLine();
			if(s.equals("end"))break;
			boolean bb=true,b1=false,b2;
			for(int i=0;i<s.length();i++)
			{
				if(isv(s.charAt(i)))
				{
					b1=true;
					break;
				}
			}
			if(!b1){
				System.out.println("<"+s+"> is not acceptable.");
				continue;
			}
			int cv=0,cf=0,mav=0,maf=0;
			for(int i=0;i<s.length();i++)
			{
				if(cv!=0||cf!=0){
					if(s.charAt(i)==s.charAt(i-1)&&s.charAt(i)!='e'&&s.charAt(i)!='o')
					{
						mav=100;
					    break;
					}
				}
				if(isv(s.charAt(i)))
				{
					cv++;
					if(maf<cf)maf=cf;
					cf=0;
				}
				else
				{
					cf++;
					if(mav<cv)mav=cv;
					cv=0;
				}
				if(cv>mav)mav=cv;
				if(cf>maf)maf=cf;
				if(mav>2||maf>2)break;
			}
			if(mav>2||maf>2)
			{
				System.out.println("<"+s+"> is not acceptable.");
				continue;
			}
			System.out.println("<"+s+"> is acceptable.");
		}
	}
	public static boolean isv(char c)
	{
		switch(c)
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
		}
		return false;
	}
}

