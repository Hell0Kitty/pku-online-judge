import java.io.*;
class Main
{
 public static void main(String[] args) throws IOException

  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  int a=Integer.parseInt(in.readLine());
  int[] fb=new int[75000];
  fb[0]=1;
  fb[1]=1;
  for(int i=2;i< 75000;i++)
	  fb[i]=(3*fb[i-1]-fb[i-2]+200000)%100000;
  while((a--)!=0)
  {
   int b=Integer.parseInt(in.readLine());
   System.out.println(fb[b%75000]);
  }
 }
}

