 import java.io.BufferedInputStream;
 import java.util.Scanner;

 public class Main {

     String cipher;
     char[] message;
     char c;

     public Main() {
         Scanner scan = new Scanner(new BufferedInputStream(System.in));
         while (!(cipher = scan.nextLine()).equals("ENDOFINPUT")) {
             while (!(cipher = scan.nextLine()).equals("END")) {
                 message = cipher.toCharArray();
                 for (int i = 0; i < message.length; i++) {
                     c = message[i];
                     if (65 <= c && c <= 90) {
                         c = (char) (65 + (c - 65 - 5 + 26) % 26);
                         message[i] = c;
                     }
                 }
                 System.out.println(String.valueOf(message));
             }
         }
     }

     public static void main(String[] args) {
         new Main();
     } 
}