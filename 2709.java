import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    static int Gray = 0;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while(in.hasNext())
        {
            int nCase = in.nextInt();
            if(nCase==0)
                break;
            int max = 0;
            Integer[] array = new Integer[nCase];
            for(int i=0;i< nCase;i++)
            {
                array[i]=in.nextInt();
                if(array[i]>max)
                    max = array[i];
            }
            Gray = in.nextInt();
            System.out.println(getAns(array,max));
        }

    }
    static int getAns(Integer[] array,int max)
    {
        int count=0;
        count+=max/50;
        if(max%50!=0)
            count++;
        for(int i=0;i< array.length;i++)
        {
            array[i] = count*50-array[i];
        }
        while(Gray>0)
        {
            Arrays.sort(array,Collections.reverseOrder());
            if(array[2]>0)
            {
                Gray--;
                array[0]--;
                array[1]--;
                array[2]--;
            }
            else
            {
                count++;
                for(int i=0;i< array.length;i++)
                    array[i]+=50;
            }
        }
        return count;
    }

}

