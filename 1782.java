import java.io.*;
import java.util.*;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		
		int i,j,n,cotinue;
		boolean is_first;
		String str;
		
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			str = cin.nextLine();
			n = str.length();
			
			cotinue = 1;
			is_first = false;
			
			for(i=0;i<n;)
			{
				if(i+1<n&&str.charAt(i)==str.charAt(i+1))
				{
					while(i+1<n&&str.charAt(i)==str.charAt(i+1)&&cotinue<9)
					{
						cotinue++;
						i++;
					}
					System.out.print(cotinue);
					System.out.print(str.charAt(i));
					i++;
					is_first = false;
					cotinue = 1;
				}
				else{
					cotinue = 1;
					if(!is_first)
						System.out.print("1");
					if(str.charAt(i)=='1')
						System.out.print("11");
					else
						System.out.print(str.charAt(i));
					if(i==n-1||(i<n-2&&str.charAt(i+1)==str.charAt(i+2)))
							System.out.print("1");
					i++;
					is_first = true;
				}
			}
			System.out.println("");
		}
	}

}
