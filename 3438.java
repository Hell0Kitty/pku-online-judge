import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        int num = Integer.valueOf(cin.nextLine()).intValue();
        String rawStr = null;


        char repeatChar = '\n';
        int repeat = 0;
        char temp = '\n';
        int newLineFlag = 0;

        for(int i = 0; i < num; i++)
        {
            newLineFlag = 0;
            StringBuffer sb = new StringBuffer();
            boolean oneLetter = false;
            rawStr = cin.nextLine();

            for(int j = 0; j < rawStr.length(); j++)
            {
                temp = rawStr.charAt(j);
                if(newLineFlag == 0)
                {
                    repeatChar = temp;
                    repeat = 1;
                    newLineFlag = 1;
                    if(j == rawStr.length()-1)
                        oneLetter = true;
                    continue;
                }

                if(temp == repeatChar)
                {
                    repeat++;
                }else
                {
                    sb.append(repeat);
                    sb.append(repeatChar);
                    repeatChar = temp;
                    repeat = 1;
                }

                if(j == rawStr.length()-1)
                {
                    sb.append(repeat);
                    sb.append(repeatChar);
                }
            }

            if(oneLetter == true)
            {
                System.out.println("1" + temp);
            }else
            {
                System.out.println(sb.toString());
            }

        }

    }

}

