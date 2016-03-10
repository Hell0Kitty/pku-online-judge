import java.util.Scanner;

    public class Main{

        static int n,m,d,k;


        public static void main(String[] args) {

            Scanner scan = new Scanner(System.in);

            while(scan.hasNext()){
                n = scan.nextInt();
                m = scan.nextInt();
                d = scan.nextInt();
                k = scan.nextInt();

                long[] init = new long[n];
                long[] tmp = new long[n];

                for(int i=0;i< n;i++)
                    init[i] = scan.nextInt();
                tmp[0] = 1;
                for(int i=1;i<=d;i++)
                    tmp[i] = tmp[n-i] = 1;


                while(k!=0){
                    if(k%2==1)
                        mul(tmp,init);
                    mul(tmp,tmp);
                    k >>= 1;
                }

                for(int i=0;i< n;i++)
                    System.out.print(init[i]+" ");
                System.out.println();

            }

        }


        public static void mul(long[] tmp, long[] init) {

            long c[] = new long[n];

            for(int i=0;i< n;i++){
                for(int j=0;j< n;j++)
                 //由矩阵第一行 可以通过 平衡获得所有列
                    c[i] += tmp[j]*init[(i+j)%n];
            }

            for(int i=0;i< n;i++)
                init[i] = c[i]%m;


        }

    }

