//* @author: 82638882@163.com
import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  char[][] arr=new char[8][8];
  String s1=in.nextLine();
  s1=s1.substring(7);
  String[] ws=s1.split(",");
  for(int i=0;i< ws.length;i++)
  {
	if(ws[i].length()==3)
	{
         int x=8-ws[i].charAt(2)+'0';
	  int y=ws[i].charAt(1)-'a';
	  arr[x][y]=ws[i].charAt(0);
	}
	else if(ws[i].length()==2)
	{
	  int x=8-ws[i].charAt(1)+'0';
	  int y=ws[i].charAt(0)-'a';
	  arr[x][y]='P';
	 }
  }
  String s2=in.nextLine();
  s2=s2.substring(7);
  String[] bs=s2.split(",");
  for(int i=0;i< bs.length;i++)
  {
   if(bs[i].length()==3)
   {
	int x=8-bs[i].charAt(2)+'0';
	int y=bs[i].charAt(1)-'a';
	arr[x][y]=(char)(bs[i].charAt(0)+32);
   }
   else if(bs[i].length()==2)
   {
	int x=8-bs[i].charAt(1)+'0';
	int y=bs[i].charAt(0)-'a';
	arr[x][y]='p';
   }
  }
  for(int i=0;i< 8;i++)
  {
	System.out.println("+---+---+---+---+---+---+---+---+");
	for(int j=0;j< 8;j++)
	{
	  if(arr[i][j]==0)
	  {
		if((i+j)%2==0)System.out.print("|...");
		else System.out.print("|:::");
	  }
	  else
	  {
		if((i+j)%2==0)System.out.print("|."+arr[i][j]+".");
		else System.out.print("|:"+arr[i][j]+":");
	  }
	}
	System.out.println("|");
   }
   System.out.println("+---+---+---+---+---+---+---+---+");
 }
}

