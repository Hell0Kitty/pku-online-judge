import java.io.*;
public class Main
{
	public static void main(String[] args) throws IOException
	{
		InputStreamReader is=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(is);
		int a=Integer.parseInt(in.readLine());
		int[] N=new int[]{
				119,36,93,109,46,107,123,37,127,111
			};
		while((a--)!=0)
		{
			int[] Num1=new int[4];
			int[] Num2=new int[4];
			String line=in.readLine();
			///////////////////第一行///////////////////////////
			for(int i=0;i<4;i++)
			{
				if(line.charAt(i*3+1)!=' ')Num1[i]|=1;
				if(line.charAt(i*3+14)!=' ')Num2[i]|=1;
			}
			//////////////////////二///////////////////////
			line=in.readLine();
			for(int i=0;i<4;i++)
			{
				if(line.charAt(i*3)!=' ')Num1[i]|=2;
				if(line.charAt(i*3+13)!=' ')Num2[i]|=2;
				if(line.charAt(i*3+1)!=' ')Num1[i]|=8;
				if(line.charAt(i*3+14)!=' ')Num2[i]|=8;
				if(line.charAt(i*3+2)!=' ')Num1[i]|=4;
				if(line.charAt(i*3+15)!=' ')Num2[i]|=4;
			}
			/////////////////////////三/////////////////////////
			line=in.readLine();
			for(int i=0;i<4;i++)
			{
				if(line.charAt(i*3)!=' ')Num1[i]|=16;
				if(line.charAt(i*3+13)!=' ')Num2[i]|=16;
				if(line.charAt(i*3+1)!=' ')Num1[i]|=64;
				if(line.charAt(i*3+14)!=' ')Num2[i]|=64;
				if(line.charAt(i*3+2)!=' ')Num1[i]|=32;
				if(line.charAt(i*3+15)!=' ')Num2[i]|=32;
			}
			/////////////////////////////////////////
			int cnt=0,clo1,clo2,tim1,tim2;
			int a1=0,a2=0,a3=0,a4=0;
			for(int i=0;i<6;i++)
			{
				if((Num1[2]|N[i])!=N[i])continue;
				for(int j=0;j<10;j++)
				{
					if((Num1[3]|N[j])!=N[j])continue;
					for(int m=0;m<6;m++)
					{
						if((Num2[2]|N[m])!=N[m])continue;
						for(int n=0;n<10;n++)
						{
							if((Num2[3]|N[n])!=N[n])continue;
							for(int u1=0;u1<3;u1++)
							{
								if((Num1[0]|N[u1])!=N[u1])continue;
								for(int u2=0;u2<3;u2++)
								{
									if((Num2[0]|N[u2])!=N[u2])continue;
									for(int d1=0;d1<10;d1++)
									{
										if(u1==2&&d1>3)break;
										if((Num1[1]|N[d1])!=N[d1])continue;
										for(int d2=0;d2<10;d2++)
										{
											if(u2==2&&d2>3)break;
											if((Num2[1]|N[d2])!=N[d2])continue;
											tim1=10*i+j;
											tim2=10*m+n;
											clo1=10*u1+d1;
											clo2=10*u2+d2;
											if((clo1==clo2&&tim1==tim2+15)||(clo1==clo2+1&&tim1+45==tim2)
													||(clo1==0&&clo2==23&&tim1+45==tim2))
												{
													cnt++;
													a1=u1;
													a2=d1;
													a3=i;
													a4=j;
												}
											
										}
									}
								}
							}
						}
					}
				}
			}
			if(cnt>1)System.out.println("Not Sure");
			else 
				System.out.println(a1+""+a2+""+a3+""+a4);
		}
	}
}