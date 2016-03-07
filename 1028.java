 import java.util.Scanner;
 import java.util.Stack;

 public class Main {

     String command;
     Stack<String> back = new Stack<String>();
     Stack<String> forward = new Stack<String>();
     String current = "http://www.acm.org/";
     String display;

     public Main() {
         Scanner scan = new Scanner(System.in);
         while (!(command = scan.next()).equals("QUIT")) {
             if (command.equals("BACK")) {
                 doBack();
             } else if (command.equals("FORWARD")) {
                 doForward();
             } else if (command.equals("VISIT")) {
                 doVisit(scan);
             }
             System.out.println(display);
         }
     }

     public void doBack() {
         if (back.isEmpty()) {
             display = "Ignored";
         } else {
             forward.push(current);
             current = back.pop();
             display = current;
         }
     }

     public void doForward() {
         if (forward.isEmpty()) {
             display = "Ignored";
         } else {
             back.push(current);
             current = forward.pop();
             display = current;
         }
     }

     public void doVisit(Scanner scan) {
         if (current != null) {
             back.push(current);
         }
         current = scan.next();
         display = current;
         forward.clear();
     }

     public static void main(String[] args) {
         new Main();
     }
}