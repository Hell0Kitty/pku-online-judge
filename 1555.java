import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		while(in.hasNext())
		{
			StringBuffer bb=new StringBuffer();
			int[] a=new int[9];
			boolean b=true;
			for(int i=0;i<9;i++)
				a[i]=in.nextInt();
			for(int i=0;i<8;i++)
			{
				if(a[i]!=0)
				{
					if(b){
						if(a[i]<0)bb.append("-");
						b=false;
					}
					else if(a[i]>0)bb.append(" + ");
					else if(a[i]<0)bb.append(" - ");
					bb.append((Math.abs(a[i])==1?"":Math.abs(a[i]))+"x"+((8-i)==1?"":"^"+(8-i)));
				}
			}
			if(b)bb.append(a[8]);
			else if(a[8]>0)bb.append(" + "+Math.abs(a[8]));
			else if(a[8]<0)bb.append(" - "+Math.abs(a[8]));
			System.out.println(bb);
		}
	}
}