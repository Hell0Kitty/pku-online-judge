import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Main {

/**
 * @param args
 * @throws IOException
 * @throws NumberFormatException
 */
public static void main(String[] args) throws NumberFormatException,
    IOException {
// TODO Auto-generated method stub
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  while (true) {
    Map< String, Integer> map = new HashMap< String, Integer>();
    int max = 0;
    int n = Integer.parseInt(br.readLine());
    if (n == 0)
        break;
    for (int i = 0; i < n; i++) {
        String s = br.readLine();
        String[] array = s.split(" ");
        Arrays.sort(array);
        String key = new String();
        for (int j = 0; j < array.length; j++) {
            key += array[j];
        }
        // System.out.println("key:"+key);
        if (map.get(key) == null)
            map.put(key, 1);
        else {
            // System.out.println("here");
            map.put(key, map.get(key) + 1);
        }
        if (max < map.get(key))
            max = map.get(key);
    }
    int result = 0;
    Set set = map.keySet();
    for (String s : set) {
        if (max == map.get(s))
            result += max;
    }
    System.out.println(result);
  }
 }

}

