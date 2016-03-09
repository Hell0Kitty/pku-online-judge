import java.io.*;
public class Main
{
 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  while(true)
  {
   String s=in.readLine();
   if(s.equals("0")) break;
   int l=s.length();
   int[] arr=new int[l];
   int count=0;
   for(int i=0;i< l-1;i++)
   {
    if(s.charAt(i+1)!='0')
    arr[count++]=s.charAt(i)-'0';
    else {
        arr[count++]=(s.charAt(i)-'0')*10;
    i++;
     }
    }
   if(s.charAt(l-1)!='0') arr[count++]=s.charAt(l-1)-'0';
   int[] arr2=new int[count+1];
   arr2[count-1]=arr2[count]=1;
   for(int i=count-2;i>=0;i--)
    {
    if((arr[i]*10+arr[i+1]>26)||arr[i+1]>9) arr2[i]=arr2[i+1];
    else{
        arr2[i]=arr2[i+1]+arr2[i+2];
    }
     }
   System.out.println(arr2[0]);
  }
 }
}

