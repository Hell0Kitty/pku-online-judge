//* @author 洪晓鹏<hongxp11@163.com>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

/**
 * @param args
 * @throws IOException
 */
public static int count(String a, String b) {
 int len = a.length();
 int result = 1;
 for (int i = 0; i < len; i++) {
    if (Character.isDigit(a.charAt(i))) {
        if (a.charAt(i) > b.charAt(i)) {
            for (int j = i + 1; j < len; j++) {
                if (a.charAt(j) == '?')
                    result *= 10;
            }
            return result;
        }
        if (a.charAt(i) < b.charAt(i))
            return 0;
    } else {
        if (len == i + 1)
            return '9' - b.charAt(i);
        else {
            String new_a = a.substring(i + 1);
            String new_b = b.substring(i + 1);
            for (int j = i + 1; j < len; j++) {
                if (a.charAt(j) == '?')
                    result *= 10;
            }
            return ('9' - b.charAt(i)) * result + count(new_a, new_b);
        }
    }
  }
  return 0;
}

 public static void main(String[] args) throws IOException {
    // TODO Auto-generated method stub
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    while (true) {
        String wild = br.readLine();
        if (wild.equals("#"))
            break;
        String num = br.readLine();
        System.out.println(count(wild, num));
    }
 }

}

