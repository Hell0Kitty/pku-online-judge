//* @author: 82638882@163.com
import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int[] bb=new int[10000];
  for(int i=0;i< 10;i++)
  {
	int aa=in.nextInt();
	while(aa!=1)
	{
          boolean r=false;
	  for(int j=2;j<=Math.sqrt(aa);j++)
	  {
	    if(aa%j==0){
		aa=aa/j;
		bb[j]++;
		r=true;
		break;
	     }
	   }
	   if(r==false){
		bb[aa]++;
		break;
	   }
	 }
    }
    int total=1;
    for(int i=0;i< 10000;i++)
    {
	if(bb[i]!=0) total*=(bb[i]+1);
    }
    System.out.println(total%10);
  }
}

