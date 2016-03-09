import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            int num = cin.nextInt();
            int ways = 1;
            int index = num/2+1;
            for(int i = index; i > 1; i--)
            {
                int tmpNum = i;
                for(int j = i - 1; j > 0; j--)
                {
                    tmpNum += j;
                    if(tmpNum == num)
                    {
                        ways++;
                        break;
                    }else if(tmpNum > num)
                        break;
                }
            }
            System.out.println(ways);


        }

    }

}

