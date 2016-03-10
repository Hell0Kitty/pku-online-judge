import java.util.Scanner;


public class Main {
 public static void main(String[] args)
 {
    Scanner in = new Scanner(System.in);
    float[] input = new float[6];
    while(true)
    {
        input[0] = in.nextFloat();
        float max = input[0];
        float min = input[0];
        float sum = input[0];
        for(int i = 1; i < 6; i++)
        {
            input[i] = in.nextFloat();
            if(max < input[i])
                max = input[i];
            if(min > input[i])
                min = input[i];
            sum = sum + input[i];
        }
        if(sum == 0.0)
            break;
        else
        {
            sum -= min;
            sum -= max;
        }
        float result = sum/4;
        int res = (int)sum/4;
        if(res*4 == sum)
            System.out.println(res);
        else
            System.out.println(result);
    }
  }
}

