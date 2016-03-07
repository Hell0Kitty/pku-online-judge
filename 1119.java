import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.HashMap;
import java.util.Map;

public class Main{

 private static String convertString(String s) {

  StringBuilder sb = new StringBuilder();

  for (int i = 0; i < s.length(); i++) {
   if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
    sb.append(s.charAt(i));
   } else if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
    sb.append(s.charAt(i));
   }
  }

  return sb.toString();
 }

 public static void main(String[] args) throws Exception {
  BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));

  String pre = "";

  String line = "";

  Map< String, Integer> document = new HashMap< String, Integer>();

  while (true) {
   line = stdin.readLine().trim().toLowerCase();

   pre = line;

   if ("----------".equals(line)) {
    break;
   }

   String[] s = line.split("[ ]+");

   for (int i = 0; i < s.length; i++) {
    String str = convertString(s[i]);

    if (str.length() > 0) {
     Integer number = document.get(str);

     if (number == null) {
      document.put(str, 1);
     } else {
      document.put(str, number + 1);
     }
    }
   }

  }

  // System.out.println(document);

  while (true) {

   double sum = 0;

   Map< String, Integer> search = new HashMap< String, Integer>();

   while (true) {

    pre = line;
    line = stdin.readLine().trim().toLowerCase();

    if ("----------".equals(line)) {
     break;
    }

    String[] temp = line.split("[, ]+");

    for (int i = 0; i < temp.length; i++) {
     String str = convertString(temp[i]);

     if (str.length() > 0) {
      Integer number = search.get(str);

      if (number == null) {
       search.put(str, 1);
      } else {
       search.put(str, number + 1);
      }
     }
    }
   }

   for (Map.Entry< String, Integer> entry : search.entrySet()) {
    if (document.keySet().contains(entry.getKey())) {

     sum += Math.sqrt(entry.getValue() * document.get(entry.getKey()));
    }
   }

   if ("----------".equals(line) && "----------".equals(pre)) {
    break;
   }

   System.out.println(new BigDecimal(sum).setScale(2, RoundingMode.HALF_UP));

   // double sum =0;

  }

 }

}
