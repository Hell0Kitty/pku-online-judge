import java.util.Scanner;


public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner in = new Scanner(System.in);
        int M = in.nextInt();
        int T = in.nextInt();
        int U = in.nextInt();
        int F = in.nextInt();
        int D = in.nextInt();
        int num = 0;
        int sum = 0;
        for(int i = 0; i < T; i++)
        {
            String s = in.next();
            if(sum > M)
                break;
            if(s.equals("u") || s.equals("d"))
                sum += U + D;
            else if(s.equals("f"))
                sum += F + F;
            num++;
        }
        System.out.println(num - 1);
    }

}

