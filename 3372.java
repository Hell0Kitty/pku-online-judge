import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
    Scanner in=new Scanner(System.in);

    while(in.hasNext())
    {
        int a=in.nextInt();
        while(a%2==0)
            a=a/2;
        if(a==1) System.out.println("YES");
        else System.out.println("NO");
    }
  }
}

