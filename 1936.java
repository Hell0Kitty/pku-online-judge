import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        String[] str = new String[2];
        String a, b;
        boolean result;

        while(cin.hasNext())
        {
            str = cin.nextLine().split(" ");
            a = str[0];
            b = str[1];

            result = findit(a, b);
            if(result == true)
                System.out.println("Yes");
            else
                System.out.println("No");
        }
    }

    private static boolean findit(String lstr, String rstr)
    {
        char[] stra = lstr.toCharArray();
        char[] strb = rstr.toCharArray();

        int cura = 0;
        char curb = '\n';

        for(int j = 0; j < strb.length; j++)
        {
            curb = strb[j];
            if(curb != stra[cura])
                continue;
            else
            {
                if(cura == stra.length-1)
                    return true;
                else
                    cura ++;
            }
        }
        return false;
    }
}

