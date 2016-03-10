import java.util.HashMap;
    import java.util.Scanner;

    public class Main{

        public static final int size = 100001;
        static int max_dis ;

        public static void main(String[] args) {

            Scanner scan = new Scanner(System.in);
            while(scan.hasNext()){
            max_dis = 0;
            int N = Integer.parseInt(scan.next());
            int K = Integer.parseInt(scan.next());
            HashMap< String,Integer> hm = new HashMap< String,Integer>();
            StringBuffer sb = new StringBuffer();
            for(int i=0;i< K;i++)
                sb.append(0);
            hm.put(sb.toString(),0);
            int sum[][] = new int[N+1][K];
            int c[][]= new int[N+1][K];

            for(int i=1;i<=N;i++){
                int p = Integer.parseInt(scan.next());
                int feature  ;
                for(int j=0;j< K;j++){
                    feature = p%2;
                    sum[i][j] = sum[i-1][j] + feature;
                    c[i][j] = sum[i][j]-sum[i][0];
                    p /= 2;
                }
                add(c[i],i,hm);
            }
            System.out.println(max_dis);

            }
        }

        public static void add(int[] a, int i,HashMap< String,Integer> hm) {
            String data = null;
            StringBuffer sb = new StringBuffer();
            for(int k=0;k< a.length;k++)
                sb.append(a[k]);
            data = sb.toString();
            if(hm.get(data)==null){
                hm.put(data, i);
            }else{
                if(max_dis< i-(hm.get(data)))
                    max_dis = i-hm.get(data);
            }

        }

    }

