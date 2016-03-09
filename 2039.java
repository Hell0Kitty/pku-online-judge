import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        int num = 0;
        String str;
        char[][] array;
        while(true)
        {
            num = Integer.valueOf(cin.nextLine()).intValue();
            if(num == 0)
                break;
            else
            {
                str = cin.nextLine();
                array = convert(str, num);
                System.out.println(getRawStr(array));
            }
        }
    }

    private static char[][] convert(String str, int col)
    {
        int toRight = 1;

        int row = 0;
        if(str.length()%col == 0)
            row = str.length()/col;
        else
            row = str.length()/col + 1;

        char[][] array = new char[col][row];

        int index = 0;
        for(int i = 0; i < row; i++)
        {
            if(toRight % 2 == 1)
                for(int j = 0; j < col; j++)
                    array[j][i] = str.charAt(index++);
            else
                for(int j = col-1; j >= 0; j--)
                    array[j][i] = str.charAt(index++);

            toRight++;
        }

        return array;
    }

    private static String getRawStr(char[][] array)
    {
        StringBuffer sb = new StringBuffer();
        for(int i = 0; i < array.length; i++)
            for(int j = 0; j < array[0].length; j++)
                sb.append(array[i][j]);
        return sb.toString();
    }
}

