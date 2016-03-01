import java.util.Scanner;

public class Main{

public static void main(String[] args) {
   Scanner cin = new Scanner(System.in);
   while(true) {
    String str = cin.nextLine();
    char c = str.charAt(0);
    int re = 0;
    if(c == '0')
     break;
    int size = str.length();
    for(int i=0; i< size; i++) {
     c = str.charAt(i);
     if(c -'4' > 0)
      c -= 1;
     re = (int) (re + (c-'0') * Math.pow(9, size-1-i));
    }
    System.out.println(str + ": " +re);
   }

}

}

