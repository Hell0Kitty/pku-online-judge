import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  while(true)
  {
   int a=in.nextInt();
   if(a==0) break;
   boolean bb=true;
   int b=in.nextInt();
   HashSet< Integer> hs=new HashSet< Integer>();
   while((a--)!=0) hs.add(in.nextInt());
   while((b--)!=0)
   {
	int c=in.nextInt();
	int d=in.nextInt();
	int cnt=0;
	while((c--)!=0)
	{
          int u=in.nextInt();
	  if(hs.contains(u))cnt++;
	}
	if(cnt< d) bb=false;
     }
     if(bb) System.out.println("yes");
     else System.out.println("no");
    }
  }
}

