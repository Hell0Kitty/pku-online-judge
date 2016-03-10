//* @author  mekarlos@gmail.com
import java.util.Scanner;

/**
 *
 * @author usuario
 */
public class Main {

    public static void main(String[] args) {

        Scanner scan=new Scanner(System.in);
        int n;
        int[] m,o;
        while (scan.hasNext()){
            n=scan.nextInt();
            if (n==0) {
                break;
            }
            m=new int[n];
            o=new  int[n];

            for (int i = 0; i < m.length; i++) {
                m[i]=scan.nextInt();
            }
            int k;
            for (int i = 1; 1<< i <= m.length; i++) {
                o=java.util.Arrays.copyOf(m, n);
                k=1<< i;
                for (int j = 0; j < k/2; j++) {

                    //System.out.println("2*k+1 = " + (k-1+j));
                        m[2*j]=(o[j]+o[k/2+j])/2;
                        m[2*j+1]=(o[j]-o[k/2+j])/2;
                }
                // System.out.println("");


            }
           for (int K = 0; K < m.length; K++) {
                    System.out.print(m[K]+" ");
           }
            System.out.println("");
        }
        System.out.println("");
    }
}

