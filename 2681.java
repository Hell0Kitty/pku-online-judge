import java.util.Scanner;
class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int a=in.nextInt();
  in.nextLine();
  int u=0;
  while((a--)!=0)
  {
	u++;
	int[] p=new int[26];
	String s1=in.nextLine();
	String s2=in.nextLine();
	for(int i=0;i< s1.length();i++)
	{
		int t=s1.charAt(i)-'a';
		p[t]++;
	}
	for(int i=0;i< s2.length();i++)
	{
		int t=s2.charAt(i)-'a';
		p[t]--;
	}
	int cnt=0;
	for(int i=0;i< 26;i++)
		cnt+=Math.abs(p[i]);
	System.out.println("Case #"+u+":  "+cnt+" ");
   }
 }
}

