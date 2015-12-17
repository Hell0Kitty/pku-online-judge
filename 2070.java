import java.util.Scanner;
public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    while (in.hasNext()) {
      float a = in.nextFloat();
      float b = in.nextFloat();
      float c = in.nextFloat();
      if (a == 0 && b == 0 && c == 0)
        break;
      boolean s = true;
      if (a <= 4.5 && b >= 150 && c >= 200) {
        System.out.print("Wide Receiver ");
        s = false;
      }
      if (a <= 6 && b >= 300 && c >= 500) {
        System.out.print("Lineman ");
        s = false;
      }

      if (a <= 5 && b >= 200 && c >= 300) {
        System.out.print("Quarterback ");
        s = false;
      }
      if (s)
        System.out.print("No positions");
      System.out.println();
    }
  }
}