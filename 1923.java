/* @author: */
import java.util.Scanner;
public class Main {

static int com(int a)
{
	return a*(a-1)/2;
}

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    long line[][]=new long[101][10001];
	int i,j,k,p,q,cs=0;
    long  max,tmp;
    for(i=1;i<=100;i++)
	 line[i][0]=i+1;
    for(i=2;i<=100;i++)
	for(j=1;j<=com(i);j++)
	{
	   max=0;
	   for(k=1;k<=i-1;k++)
	   {
	     p=i-k;q=j-k*p;
	     if(q>=0)
	     {
	       if(line[p][q]!=0)
		{
		   tmp=line[p][q]+k*(p+1);
		   if(tmp>max)
		     max=tmp;
		}
	    }
	 }
	 line[i][j]=max;
       }
	while (sc.hasNext())
	{
        i=sc.nextInt();
        j=sc.nextInt();
	 if(i==0&&j==0)
		break;
	 cs++;
	if(line[i][j]>0)
      System.out.printf("Case %d: %d lines with exactly %d crossings can cut the plane into %d
	     pieces at most.\n",cs,i,j,line[i][j]);
	else System.out.printf("Case %d: %d lines cannot make exactly %d crossings.\n",cs,i,j);
	}
   }
}

