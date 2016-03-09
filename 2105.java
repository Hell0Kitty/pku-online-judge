import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        int num = Integer.valueOf(cin.nextLine()).intValue();



        for(int i = 0; i < num; i++)
        {
            String str, temp;
            int a,b,c,d = 0;
            StringBuffer sb = new StringBuffer();

            str = cin.nextLine();
            temp = str.substring(0, 8);
            sb.append(convert(temp));
            sb.append('.');
            temp = str.substring(8, 16);
            sb.append(convert(temp));
            sb.append('.');
            temp = str.substring(16, 24);
            sb.append(convert(temp));
            sb.append('.');
            temp = str.substring(24);
            sb.append(convert(temp));

            System.out.println(sb.toString());
        }

    }

    private static int convert(String str)
    {
        int value = 0;
        if(str.charAt(0) == '1')
            value += 128;
        if(str.charAt(1) == '1')
            value += 64;
        if(str.charAt(2) == '1')
            value += 32;
        if(str.charAt(3) == '1')
            value += 16;
        if(str.charAt(4) == '1')
            value += 8;
        if(str.charAt(5) == '1')
            value += 4;
        if(str.charAt(6) == '1')
            value += 2;
        if(str.charAt(7) == '1')
            value += 1;

        return value;
    }

}

