import java.io.*;
import java.util.*;
public class Main
{
 static String[] Num=new String[]{
    "zero","one","two","three","four","five","six","seven","eight","nine","ten",
    "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen",
    "nineteen","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety",
    "hundred","thousand","million"
  };

  public static void main(String[] args) throws IOException
  {
   InputStreamReader is=new InputStreamReader(System.in);
   BufferedReader in=new BufferedReader(is);
   String s;
   while(true)
    {
      s=in.readLine();
      if(s.equals("")) break;
      boolean bb=true;
      String[] ss=s.split(" ");
      int len=ss.length;
      long sum=0;
      long temp=0;
      int tag=0;
      if(ss[0].equals("negative")){
     bb=false;
     tag=1;
      }
      for(int i=tag;i< len;i++)
      {
     for(int j=0;j< 31;j++)
     {
        if(ss[i].equals(Num[j]))
        {
         if(j<=20) temp+=j;
         else if(j< 28) temp+=(j-18)*10;
         else if(j==28) temp*=100;
         else if(j==29)
         {
               temp*=1000;sum+=temp;temp=0;
         }
         else if(j==30)
         {
           sum+=temp;sum*=1000000;temp=0;
         }
         break;
         }
      }
       }
       sum+=temp;
       if(!bb) sum=-sum;
       System.out.println(sum);
    }
  }
}

