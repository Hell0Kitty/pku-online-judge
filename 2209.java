import java.util.Scanner;


public class Main {
 public static void main(String[] args)
 {
    Scanner in = new Scanner(System.in);
    int numOfSon = in.nextInt();
    int power = in.nextInt();
    int[] potential = new int[numOfSon];
    int sum = 0;
    if(power%2==1)
    {
         for(int i = 0; i< numOfSon; i++)
      {
        potential[i] = in.nextInt();
        if(potential[i]>0)
            sum = (int) (sum + Math.pow(potential[i],power));
      }
    }
    else
    {
      for(int i = 0; i< numOfSon; i++)
    {
    potential[i] = in.nextInt();
    sum = (int) (sum + Math.pow(potential[i],power));
       }
    }
   System.out.println(sum);
  }
}

