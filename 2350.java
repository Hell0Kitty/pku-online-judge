import java.util.Scanner;

/**
 * poj2350 easy
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        if (scan.hasNext()) {
            int n = scan.nextInt();
            for (int i = 0; i < n; i++) {
                int nn = scan.nextInt();
                float sum = 0f;
                int[] aa = new int[nn];
                for (int j = 0; j < nn; j++) {
                    aa[j]= scan.nextInt();
                    sum = sum + aa[j];
                }
                float average = sum/nn;
                float count = 0f;
                for(int j = 0; j < nn; j++){
                    if(aa[j]>average){
                        count++;
                    }
                }
                System.out.printf("%.3f",count/nn*100);
                System.out.println("%");

            }
        }
    }
}

