import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        while(cin.hasNext())
        {
            int num = cin.nextInt();
            int index = 1;
            int result = 0;
            while(result <= num)
            {
                result += index;
                index ++;
            }
            result -= (index-1);

            int layer = index - 1;
            int offset = num - result;
            int up, down = 0;

            if(layer % 2 == 0)
            {
                if(offset == 0)
                {
                    up = 1;
                    down = layer - 1;
                }
                else
                {
                    up = offset;
                    down = layer + 1 - offset;
                }
            }
            else
            {
                if(offset == 0)
                {
                    up = layer - 1;
                    down = 1;
                }
                else
                {
                    up = layer + 1 - offset;
                    down = offset;
                }
            }
            System.out.println("TERM " + num + " IS " + up + "/" + down);
        }
    }
}


