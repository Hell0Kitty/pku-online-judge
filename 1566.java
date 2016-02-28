import java.util.*;
import java.io.BufferedInputStream;


public class Main
{
    public static int[] numbers = {5,7,5};
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        sc.useDelimiter("\n");
        while(true)
        {
            String line = sc.next();
            line = line.trim();
            if(line.equals("e/o/i"))
            {
                break;
            }
            String[] parts = line.split("/");
            int i;
            for(i = 0; i < parts.length; i++)
            {
                String[] words = parts[i].split("\\s+");
                int numOfSyllables = 0;
                for(String word : words)
                {
                    numOfSyllables += getNumOfSyllables(word);
                }
                if(numOfSyllables != numbers[i])
                {
                    break;
                }
            }
            if( i == parts.length)
            {
                System.out.println("Y");
            }else
            {
                System.out.println(i+1);
            }
        }
    }
    
    public static int getNumOfSyllables(String word)
    {
        boolean pre = false;
        int result = 0;
        for(int i = 0; i < word.length(); i++)
        {
            if(isSyllable(word.charAt(i)))
            {
                if(!pre)
                {
                    result++;
                    pre = true;
                }
            }else
            {
                pre = false;
            }
        }
        return result;
    }
    
    public static boolean isSyllable(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'
                || ch == 'u' || ch == 'y';
    }
}
