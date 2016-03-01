//* @author: 82638882@163.com
import java.io.*;
import java.util.Arrays;
public class Main
{
 public static void main(String[] args) throws NumberFormatException, IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  String[] ss=in.readLine().split(" ");
  int a=Integer.parseInt(ss[0]);
  int b=Integer.parseInt(ss[1]);
  boolean[][] p=new boolean[a][b];
  my[] p2=new my[a];
  for(int i=0;i< a;i++)
    p2[i]=new my();
  while(in.ready())
   {
    ss=in.readLine().split(" ");
    int x=Integer.parseInt(ss[0]);
    int y=Integer.parseInt(ss[1]);
    p[x-1][y-1]=true;
   }
  for(int i=0;i< a;i++)
    for(int j=0;j< b;j++)
	if(p[i][j]){
	  p2[i].cnt++;
	  p2[i].n+=(j+1)*(j+1)*(j+1)*(j+1);
	}

  Arrays.sort(p2);
  int sum=1;
  for(int i=1;i< a;i++)
  {
   if(p2[i].n==p2[i-1].n&&p2[i].cnt==p2[i-1].cnt) continue;
   sum++;
  }
  System.out.println(sum);
 }
}

class my implements Comparable< my>
{
    int n=0,cnt=0;

    public int compareTo(my o) {
	 if(cnt==o.cnt)
	 return n-o.n;
	 return cnt-o.cnt;
    }
}

