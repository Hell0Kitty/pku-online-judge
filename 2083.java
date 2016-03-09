import java.util.Scanner;
class Main
{
 static StringBuffer sb=new StringBuffer();
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  while(true)
  {
    int a=in.nextInt();
    if(a==-1) break;
    else if(a==1) System.out.println('X');
    else g("",a-1);
    System.out.println("-");
  }
 }


 static void p(int a)
 {
  int t=(int)Math.pow(3, a-1);
  for(int i=0;i< t;i++)
    sb.append(" ");
 }

  static void g(String s,int a)
  {
   if(a==0)
   {
    sb.delete(0, sb.length()+1);
    print(s);
    System.out.println(sb.toString().subSequence(0, sb.lastIndexOf("X")+1));
    return;
    }
    g(s+"A",a-1);
    g(s+"B",a-1);
    g(s+"A",a-1);

    }


 static void print(String s)
 {
    int l=s.length();
    char c=s.charAt(0);
    if(l==1)
    {
          if(c=='A') sb.append("X X");
      else sb.append(" X ");
      return;
    }
    if(c=='A')
    {
       print(s.substring(1));
       p(l);
       print(s.substring(1));
    }
    else
    {
       p(l);
       print(s.substring(1));
       p(l);
    }
   }
}

