import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * 
 * Accepted. BigInteger is used here.
 * 
 * 
 */
public class Main {

    /**
     * Check if the given string is in numberic format.
     * 
     * @param a
     * @return
     */
    private static boolean isNumber(String a) {
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) >= '0' && a.charAt(i) <= '9') {
                // ignore
            } else {
                return false;
            }
        }

        return true;
    }

    /**
     * Format the given number.  such as 1234 to 1,234
     * 
     * @param a
     * @return
     */
    private static String format(String a) {
        StringBuffer sb = new StringBuffer();
        for (int j = a.length() - 1; j >= 0; j--) {
            if ((j != a.length() - 1) && ((a.length() - 1 - j) % 3 == 0)) {
                sb.append(",");
            }

            sb.append(a.charAt(j));
        }

        return sb.reverse().toString();
    }

    /**
     * Translate the words to number.
     * 
     * @param a
     * @return
     */
    private static String transalteToNumber(String a) {
        BigInteger m = new BigInteger("26");
        BigInteger ret = BigInteger.ZERO;

        BigInteger b = BigInteger.ONE;

        for (int i = a.length() - 1; i >= 0; i--) {
            BigInteger temp = new BigInteger("" + (a.charAt(i) - 'a' + 1));
            temp = temp.multiply(b);

            b = b.multiply(m);

            ret = ret.add(temp);
        }

        return ret.toString();
    }

    /**
     * Translate number to words.
     * 
     * @param a
     * @return
     */
    private static String translateString(String a) {
        BigInteger b = new BigInteger(a);

        BigInteger m = new BigInteger("26");

        StringBuffer sb = new StringBuffer();

        while (b.compareTo(BigInteger.ZERO) > 0) {

            BigInteger k = b.mod(m);

            if (k.intValue() <= 0) {
                sb.append("z");
                b = b.subtract(m);
            } else {
                sb.append((char) (k.intValue() - 1 + 'a'));

                b = b.subtract(k);
            }
            b = b.divide(m);
        }

        return sb.reverse().toString();
    }

    /**
     * Delete the leading zero.
     * 
     * @param a
     * @return
     */
    private static String deleteLeadingZero(String a) {
        int i = 0;
        while (a.charAt(i) == '0') {
            i++;
        }

        StringBuilder sb = new StringBuilder();
        while (i < a.length()) {
            sb.append(a.charAt(i));
            i++;
        }

        return sb.toString();
    }

    /**
     * Format and print the result string.
     * 
     * @param s
     */
    private static void print(String s) {
        int max = 22;
        String[] temp = s.split("[ ]+");

        System.out.print(temp[0]);

        for (int j = temp[0].length(); j < max; j++) {
            System.out.print(" ");
        }

        System.out.println(temp[1]);
    }

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        Scanner cin = new Scanner(System.in);

        while (true) {

            String line = cin.nextLine();

            line = deleteLeadingZero(line.trim());
            if (line.equals("*")) {
                break;
            }

            String word = "";

            String number = "";

            if (isNumber(line)) {

                word = translateString(line);

                number = format(line);

                print(word + " " + number);

            } else {

                word = line;
                number = format(transalteToNumber(line));

                print(word + " " + number);
            }
        }
    }

}

