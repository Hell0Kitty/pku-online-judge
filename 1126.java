import java.util.Scanner;

public class Main {

/**
* @param args
*/

public static void main(String[] args) {
 Scanner s = new Scanner(System.in);
 String sentence = null;
 int count;
 char ch;
 while ((sentence = s.nextLine()) != null) {
   count = 0;// 当前句子数
   for (int i = sentence.length() - 1; i >= 0; i--) {
    ch = sentence.charAt(i);
    if (ch >= 'p' && ch <= 'z') {
      count++;
    } else if (ch == 'C' || ch == 'D' || ch == 'E' || ch == 'I') {
      count--;
   if (count < 1)
     break;
   } else if (ch == 'N') {
     if (count < 1)
       break;
     } else {
       count = -1;
       break;
     }
   }
   if (count == 1) {
     System.out.println("YES");
   } else {
     System.out.println("NO");
   }
  }
 }
}

