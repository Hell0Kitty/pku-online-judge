import java.io.BufferedInputStream;   
import java.io.DataInputStream;   
import java.io.IOException;   
import java.util.Iterator;   
import java.util.Map;   
import java.util.Scanner;   
import java.util.Set;   
import java.util.TreeMap;   
  
/**  
 * poj1002  
 * 题意就是输入几组字符串，按照给出的形式转换为统一格式，  
 * 然后输出出现多于一次的字符串出现的次数，输出时按照字典顺序排列  
 * 测试过这样的数据量  
 * 10000 18s  
 * 20000 116s  
 * 50000 等了4分多钟没结果  
 * 一直过不了，有时是re，有时是超时  
 * 改成DataInputStream居然过了，太兴奋了！！！！！！！  
 * 太无语了。。。。痛苦了好久啊。。。。  
 * @author NC  
 */  
public class Main {   
  
    public static char getNum(char c) {   
        //注意对于数字字符要用''，如果没有的话，虽然也会自转，但是只当作对应0到9的ascii码   
        if (Character.isDigit(c)) {   
            return c;   
        }   
        if (c == 'A' || c == 'B' || c == 'C') {   
            return '2';   
        }   
        if (c == 'D' || c == 'E' || c == 'F') {   
            return '3';   
        }   
        if (c == 'G' || c == 'H' || c == 'I') {   
            return '4';   
        }   
        if (c == 'J' || c == 'K' || c == 'L') {   
            return '5';   
        }   
        if (c == 'M' || c == 'N' || c == 'O') {   
            return '6';   
        }   
        if (c == 'P' || c == 'R' || c == 'S') {   
            return '7';   
        }   
        if (c == 'T' || c == 'U' || c == 'V') {   
            return '8';   
        }   
        if (c == 'W' || c == 'X' || c == 'Y') {   
            return '9';   
        }   
        return '#';   
    }   
  
    public static void main(String[] args) throws IOException {   
//        Scanner scan = new Scanner(new BufferedInputStream(System.in));   
        DataInputStream scan = new DataInputStream(new BufferedInputStream(System.in));   
//      if (scan.hasNext()) {   
        Map<String, Integer> tm = new TreeMap();   
        //   int n = Integer.parseInt(scan.nextLine().trim());   
        int n = Integer.parseInt(scan.readLine().trim());//方法虽然过时了，但却更快   
        for (int i = 0; i < n; i++) {   
//                String s = scan.nextLine().replace("-", "");   
            String s = scan.readLine().replace("-", "");   
            StringBuilder sb = new StringBuilder();   
            //转字符电话号码为数字电话号码   
            for (int k = 0; k < s.length(); k++) {   
                char c = getNum(s.charAt(k));   
                if (Character.isDigit(c)) {   
                    sb.append(c);   
                }   
            }   
            String result = sb.toString().substring(0, 3) + '-' + sb.toString().substring(3);   
            //统计字符串出现的次数,因为要求是字典顺序，故选用TreeMap   
            if (tm.containsKey(result)) {   
                int count = tm.get(result) + 1;   
                tm.put(result, count);   
            } else {   
                tm.put(result, 1);   
            }   
        }   
        // System.out.println("111");   
        Set se = tm.keySet();   
        Iterator it = se.iterator();   
        boolean flag = false;   
        while (it.hasNext()) {   
            String s = it.next().toString();   
            int count = tm.get(s);   
            if (count > 1) {   
                flag = true;   
                System.out.println(s + " " + count);   
            }   
        }   
        if (!flag) {   
            System.out.println("No duplicates. ");   
        }   
    }   
    //  }   
}  
