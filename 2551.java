import java.util.Scanner;


public class Main {
 public static void main(String[] args)
 {
  Scanner in = new Scanner(System.in);
  while(in.hasNext())
  {
	int input = in.nextInt();
	int result = 1;
	int begin = 1;
    while(true)
	{
	if(begin % input ==0)
		{
			System.out.println(result);
			break;
		}
	begin = begin%input;
	begin = begin*10 + 1;
	result ++;
    }
   }
 }
}

