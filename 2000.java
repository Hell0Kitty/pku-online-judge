import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        while(true)
        {
            int day = Integer.valueOf(cin.nextLine()).intValue();
            if(day == 0)
                break;

            System.out.println(day + " " + getTotalCoin(day));
        }
    }

    private static int getTotalCoin(int day)
    {
        int total = 1;
        int factor = 2;
        int index = 0;

        if(day == 1)
            return 1;

        for(int i = 2; i <= day; i++)
        {
            if(index == factor)
            {
                index = 0;
                factor ++;
            }

            total += factor;
            index ++;
        }
        return total;
    }
}

