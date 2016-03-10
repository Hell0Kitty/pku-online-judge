//* @author: 82638882@163.com
import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
    Scanner in=new Scanner(System.in);
    int a=in.nextInt();
    int b=in.nextInt();
    String[] s1=new String[a];
    String[] s2=new String[a];
    for(int i=0;i< a;i++)
    {
        s1[i]=in.next();
        s2[i]=in.next();
    }
    for(int i=0;i< b;i++)
    {
         String s=in.next();
      boolean bb=false;
      for(int j=0;j< a;j++)
      {
       if(s.equals(s1[j]))
       {
        System.out.println(s2[j]);
        bb=true;
        break;
        }
       }
      if(!bb){
        if(s.endsWith("y"))
        {
            if(s.endsWith("ay")||s.endsWith("ey")||s.endsWith("iy")||s.endsWith("oy")||s.endsWith("uy"))
            System.out.println(s+"s");
         else
            System.out.println(s.substring(0,s.length()-1)+"ies");
        }
        else if(s.endsWith("o")||s.endsWith("s")||s.endsWith("ch")||s.endsWith("sh")
                ||s.endsWith("x")) System.out.println(s+"es");
        else System.out.println(s+"s");
        }
      }
    }
}

