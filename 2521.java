import java.util.*;

    public class Main {

        public static void main(String[] args) {
            Scanner cin = new Scanner(System.in);
            while(cin.hasNext())
            {
                String tmp = cin.nextLine();
               if(tmp.equals("0 0 0 0"))
                   break;
               String[] tmp1 = tmp.split(" ");
               int N = Integer.valueOf(tmp1[0]);
               int M = Integer.valueOf(tmp1[1]);
               int P = Integer.valueOf(tmp1[2]);
               int C = Integer.valueOf(tmp1[3]);

               int totalPaid = M + C;
              int totalTrue = totalPaid - P;

               int earn = totalTrue - N - C;

              System.out.println(earn*-1);

           }

       }

   }

