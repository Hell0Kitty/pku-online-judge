//* @author: 82638882@163.com
import java.io.*;
public class Main
{
 static int[] next;
 static String s1,s2;
 static int l1,l2,cnt;
 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  int a=Integer.parseInt(in.readLine());
  while((a--)!=0)
  {
    s1=in.readLine();
    s2=in.readLine();
    l1=s1.length();
    l2=s2.length();
    cnt=0;
    next=new int[l1];
    next();
    kmp();
    System.out.println(cnt);
   }
 }

 static void kmp()
 {
  int i=0,j=0;
  while(i< l2&&j< l1)
  {
    if(j==-1||s2.charAt(i)==s1.charAt(j))
    {
    i++;
    j++;
    }
    else j=next[j];
    if(j==l1)
    {
    cnt++;
    i=i-1;
    j=next[j-1];
    }
   }
 }

  static void next()
  {
   int i = 0;
   next[0] = -1;
   int j = -1;
   while(i < l1 - 1)
   {
    if(j == -1 || s1.charAt(i) == s1.charAt(j))
    {
        ++i;
        ++j;
        next[i] = j;
    }
    else
        j = next[j];
    }
  }

}

