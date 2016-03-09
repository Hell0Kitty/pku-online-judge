import java.io.*;
import java.util.Arrays;
class Main
{
 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  String[] ss=in.readLine().split(" ");
  int a=Integer.parseInt(ss[0]);
  int k=Integer.parseInt(ss[1]);
  my[] p=new my[a];
  ss=in.readLine().split(" ");
  for(int i=0;i< a;i++)
    p[i]=new my(i,Integer.parseInt(ss[i]));
  Arrays.sort(p);
  while((k--)!=0)
   {
    ss=in.readLine().split(" ");
    int l=Integer.parseInt(ss[0])-1;
    int r=Integer.parseInt(ss[1]);
    int cnt=Integer.parseInt(ss[2]);
    for(int i=0;i< a;i++)
    {
          if(p[i].num>=l&&p[i].num< r)
       {
        cnt--;
        if(cnt==0)
         {
        System.out.println(p[i].t);
        break;
         }
       }
    }
     }
   }

 }

 class my implements Comparable< my>
 {
    int num,t;
    public my(int a,int b)
    {
        num=a;
        t=b;
    }
    public int compareTo(my arg0) {
        return t-arg0.t;
    }
}

