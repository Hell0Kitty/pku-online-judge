//* @author 洪晓鹏<hongxp11@163.com>
import java.util.Scanner;


public class Main {
 public static void main(String[] args)
 {
    Scanner in = new Scanner(System.in);
    while(true)
    {
        String input = in.nextLine();
        if(input.equals("R0C0"))
            break;
        int index = 0;
        while(input.charAt(index)!='C')
        {
            index++;
        }
        int num = Integer.parseInt(input.substring(1, index));
        int letter = Integer.parseInt(input.substring(index+1, input.length()));

        String result = "";
        result = change(letter) + result;
        while(true)
        {
            if(letter/26.0>1)
            {
                if(letter%26!=0)
                {
                    letter = letter/26;
                    result = change(letter) + result;
                }
                else
                {
                    letter = letter/26;
                    letter--;
                    result = change(letter) + result;
                }
            }
            else
                break;
        }
        System.out.println(result+num);
    }
   }

  public static char change(int letter)
  {
    char m;
    if(letter % 26 == 0)
        m = 'Z';
    else
        m = (char) (letter%26 + 'A' -1);
    return m;
  }
}

