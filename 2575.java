import java.util.HashSet;
import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  while(in.hasNext())
   {
	int a=in.nextInt();
	int[] b=new int[a];
	for(int i=0;i< a;i++)
		b[i]=in.nextInt();
	HashSet< Integer> h=new HashSet< Integer>();
	for(int i=1;i< a;i++)
		h.add(Math.abs(b[i]-b[i-1]));
	boolean bb=true;
	for(int i=1;i< a;i++)
	{
		if(!h.contains(i)){
                  bb=false;
		  break;
	        }
	}
	if(bb) System.out.println("Jolly");
	else System.out.println("Not jolly");
    }
  }
}

