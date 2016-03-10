//* @author 洪晓鹏<hongxp11@163.com>
import java.util.Scanner;


public class Main {
 public static void main(String[] args)
 {
    Scanner in = new Scanner(System.in);
    int n = Integer.parseInt(in.nextLine());
    for(int j = 0; j< n; j++)
    {
        String first = in.next();
        String second = in.next();
        int res1 = 0;
        int res2 = 0;
        int[] done = new int[4];
        for(int i = 0; i< 4; i++)
        {
            if(first.charAt(i)==second.charAt(i))
            {
                res1++;
                done[i]=1;
            }
        }
        for(int i = 0; i< 4; i++)
        {
                for(int k = 0; k< 4; k++)
           {
            if(first.charAt(i)==second.charAt(k))
            {
                if(done[i]==0)
                    res2++;
            }
        }
    }
    System.out.println(res1+"A"+res2+"B");
  }
 }
}

