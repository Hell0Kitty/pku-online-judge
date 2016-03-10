import java.util.Scanner;


public class Main {
 public static void main(String[] args)
 {
  Scanner in = new Scanner(System.in);
   while(true)
    {
       String input = in.nextLine();
    if(input.equals("#"))
        break;
    int len = input.length();
    for(int i = 0; i < len; i++)
    {
        if(input.charAt(i)==' ')
            System.out.print("%20");
        else if(input.charAt(i)=='!')
            System.out.print("%21");
        else if(input.charAt(i)=='$')
            System.out.print("%24");
        else if(input.charAt(i)=='%')
            System.out.print("%25");
        else if(input.charAt(i)=='(')
            System.out.print("%28");
        else if(input.charAt(i)==')')
            System.out.print("%29");
        else if(input.charAt(i)=='*')
            System.out.print("%2a");
        else
            System.out.print(input.charAt(i));
    }
    System.out.println();
    }
  }
}

