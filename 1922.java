mport java.util.Scanner;

public class Main{

public static void main(String[] args) {
   Scanner s = new Scanner(System.in);
   while(true) {
    int n = s.nextInt();
    if(n == 0)
     System.exit(-1);
    double min = 1000000000;
    while(n > 0) {
     int v = s.nextInt();
     int t = s.nextInt();
     if(t < 0) {
      n--;
      continue;
     }
     double time = 4.5 / v * 3600 + t;
     if(time < min)
      min = time;
     n--;
    }
    System.out.println((int)Math.ceil(min));
   }
}

}

