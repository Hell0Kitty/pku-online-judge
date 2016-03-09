import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class Main {

    /**
     * Parse the value.
     * @param s the given string such as  4.5A, 2.5MW
     * @return
     */
    private static double parseValue(String s) {
        int i = 0;
        while(i < s.length() && s.charAt(i) >= '0' && s.charAt(i) <= '9' || s.charAt(i) == '.') {
            i++;
        }

        if (i == s.length()) {
            return Double.parseDouble(s);
        }
        // in case that the end of string is not reached.
         double value = Double.parseDouble(s.substring(0, i));
        if (s.charAt(i) == 'm') {
            value = value / 1000.0;
        } else if (s.charAt(i) == 'M') {
            value = value * 1000000.0;
        } else if (s.charAt(i) == 'k') {
            value = value * 1000.0;
        }
        return value;
    }

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception  {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));

        String line = stdin.readLine();

        int n = Integer.parseInt(line);


        for (int i = 1; i<= n; i++){
            line = stdin.readLine();


            String[] t = line.split("[ ,]+");


            boolean u_value = false;
            boolean i_value = false;
            boolean p_value = false;

            double u = 0;
            double I = 0;
            double p = 0;

            for (int j = 0; j < t.length; j++) {

                if (t[j].indexOf("=") > 0) {

                    // split the kind of string like:U=200V
                    String[] temp = t[j].split("[=]");

                    if (temp[0].charAt(0) == 'U') {
                        u_value = true;

                        u = parseValue(temp[1]);
                    } else if (temp[0].charAt(0) == 'P') {
                        p_value = true;
                        p = parseValue(temp[1]);
                    } else if (temp[0].charAt(0) == 'I') {
                        i_value = true;
                        I = parseValue(temp[1]);
                    }

                }

            }

            System.out.println("Problem #" + i);

            if (u_value && i_value) {
                System.out.print("P=");
                System.out.print(new BigDecimal(I * u).setScale(2, RoundingMode.HALF_UP));
                System.out.println("W");
            } else if (p_value && u_value) {
                System.out.print("I=");
                System.out.print(new BigDecimal(p /u).setScale(2, RoundingMode.HALF_UP));
                System.out.println("A");
            } else if (p_value && i_value) {
                System.out.print("U=");
                System.out.print(new BigDecimal(p /I).setScale(2, RoundingMode.HALF_UP));
                System.out.println("V");
            }

            System.out.println();
        }
    }
}


