//* @author: 82638882@163.com
import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  String a=in.next();
  int t=0;
  int n=-1;
  for(int i=0;i< 10;i++)
  {
    char c=a.charAt(i);
    if(c!='?'&&c!='X'){
      t+=(c-'0')*(10-i);
    }
    else if(c=='X') t+=10;
    else if(c=='?') n=10-i;
   }
   int ans=-1;
   if(n!=1)
    for(int i=0;i< 10;i++)
    {
    if((t+n*i)%11==0){
        ans=i;
        break;
    }
    }
    else if(n==1)
    {
    for(int i=0;i< 11;i++)
      if((t+i)%11==0){
        ans=i;
        break;
      }
    }
    if(ans==10) System.out.println("X");
    else
    System.out.println(ans);
  }
}

