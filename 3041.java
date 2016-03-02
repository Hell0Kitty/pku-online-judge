 import java.util.Scanner;
public class Main
{
 static int a,b;
 static int[][] map;
 static int[] used;
 static int[] match;
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  a=in.nextInt();
  b=in.nextInt();
  map=new int[a+1][a+1];
  for(int i=0;i< b;i++)
	map[in.nextInt()][in.nextInt()]=1;
  match=new int[a+1];
  used=new int[a+1];
  int count=0;
  for(int i=1;i<=a;i++)
  {
   for(int j=0;j<=a;j++)
	used[j]=0;
	if(find(i))count++;
  }
  System.out.print(count);
}

public static boolean find(int k)
{
 for(int i=1;i<=a;i++)
  if(map[k][i]==1&&used[i]==0)
  {
	used[i]=1;
	if(match[i]==0||find(match[i]))
	{
         match[i]=k;
	  return true;
	}
   }
  return false;
 }
}

