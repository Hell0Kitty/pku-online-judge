//* @author: 82638882@163.com
import java.io.*;
import java.util.*;
public class Main
{
 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  String[] ss;
  String s;
  int count=0;
  while(true)
  {
    count++;
    node[] arr=new node[1001];
    node[] pp=new node[1001];
    int i=0,j,zNum,maxNum,x,y,p,max=-1, a=0;
    while(true)
    {
         s=in.readLine();
      if(s.charAt(0)=='-'&&s.charAt(1)=='-') break;
      ss=s.split(" ");
      x=Integer.parseInt(ss[0]);
      y=Integer.parseInt(ss[1]);
      arr[a]=new node(x,y);
      pp[a]=new node();
      a++;
     }
     if(a==0) break;
     for(i=0;i< a-1;i++)
     {
       int k=0;
       zNum=maxNum=-1;
       for(j=i+1;j< a;j++)
       {
        x=arr[i].x-arr[j].x;
        y=arr[i].y-arr[j].y;
        if(y==0) zNum++;
        else if(x==0) maxNum++;
        else
        {
             p=gcd(Math.abs(x),Math.abs(y));
          pp[k].x=x/p;
          pp[k].y=y/p;
          if(pp[k].x< 0)
          {
           pp[k].x*=-1;
           pp[k].y*=-1;
          }
          k++;
        }
         }
         max=Math.max(max,Math.max(zNum, maxNum));
         int cnt=0;
         Arrays.sort(pp, 0, k);
         for(j=0;j< k-1;j++)
         {
        if(pp[j].x==pp[j+1].x&&pp[j].y==pp[j+1].y) cnt++;
        else{
            if(cnt>max) max=cnt;
            cnt=0;
        }
         }
         max=Math.max(max, cnt);
      }
     System.out.println(count+". "+(max+2));
     }
  }

  static int gcd(int a,int b)
  {
   if(b==0) return a;
   else return gcd(b,a%b);
  }
}

class node implements Comparable< node>{
    public int x,y;
    public node(){}
    public node(int a,int b)
    {
        x=a;
        y=b;
    }
    public int compareTo(node o) {
        if(x==o.x) return y-o.y;
        return x-o.x;
    }
}

