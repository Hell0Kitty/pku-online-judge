import java.util.*;
public class Main
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		while(true)
		{
			String s=in.nextLine();
			if(s.equals("."))break;
			s=s.substring(0,s.length()-1);
			String[] arr=s.split(", ");
			int l=arr.length;
			int[] kk=new int[l];
			ArrayList<Integer> arrI=new ArrayList<Integer>();
			TreeMap<String,String> arrS=new TreeMap<String,String>();
			for(int i=0;i<l;i++)
			{
				if(isNum(arr[i])){
					arrI.add(Integer.parseInt(arr[i]));
					kk[i]=1;
				}
				else arrS.put(arr[i].toLowerCase(), arr[i]);
			}
			Collections.sort(arrI);
			int w=0,q=0;
			for(int i=0;i<l;i++)
			{
				if(kk[i]==1)System.out.print(arrI.get(w++));
				else {
					System.out.print(arrS.get(arrS.firstKey()));
					arrS.remove(arrS.firstKey());
				}
				if(i!=l-1)System.out.print(", ");
			}
			System.out.println(".");
		}
	}
	public static boolean isNum(String str)
	{
		char w=str.charAt(0);
		if(w!='-'&&(w>57||w<48))return false;
		for(int i=1;i<str.length();i++)
		{
			char c=str.charAt(i);
			if(c>57||c<48)return false;
		}
		return true;
	}
}