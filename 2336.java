import java.util.Scanner;


public class Main {
 public static void main(String[] args)
 {
  Scanner in = new Scanner(System.in);
  int num = in.nextInt();
  for(int i = 0; i< num; i++)
  {
    int n = in.nextInt();
    int t = in.nextInt();
    int m = in.nextInt();
    int[] time = new int[m];
    int starttime = 0;
    for(int j = 0; j< m; j++)
    {
        time[j] = in.nextInt();
    }
    if(m % n == 0)
    {
        starttime = time[n-1];
        for(int k = 1; k< m/n; k++)
        {
            if(time[n*(k+1)-1] > starttime + 2*t)
                starttime = time[n*(k+1)-1];
            else
                starttime += 2*t;

        }
    }
    else
    {
        starttime = time[m%n -1];
        int p = m/n;
            int index = m%n -1;
        for(int k = 0; k< p; k++)
        {
          if(time[n*(k+1)+ index] > starttime + 2*t)
           starttime = time[n*(k+1)+ index];
          else
           starttime += 2*t;
        }
    }
    int result = (int)Math.ceil(1.0*m/n);
    System.out.println(starttime+t+" "+ result);
  }
 }

}

