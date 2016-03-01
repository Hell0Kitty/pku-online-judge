import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  StringBuffer[] sb=new StringBuffer[13];
  sb[0]=new StringBuffer("-");
  for(int i=1;i< 13;i++)
  {
	sb[i]=new StringBuffer(sb[i-1]);
	int k=(int)Math.pow(3, i-1);
	for(int w=0;w< k;w++)
		sb[i].append(" ");
	sb[i].append(sb[i-1]);
   }
  while(in.hasNext())
  {
	int a=in.nextInt();
	System.out.println(sb[a]);
  }
 }
}

