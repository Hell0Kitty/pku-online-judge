    import java.io.*;

    public class Main{

        //题意   将所有城市分成三部份（每个城市拥有一定的牛） 问至少有两个部份的各自的总牛数大于 500*k
        // 将所有城市按牛数量排序，从最大的2*k个城市中分成两组（我们已经舍弃最小的k只牛会胜出
        //（当然会不会胜出得看给得数据));
        // 调整使得剩下 2*k个城市 分成两组都会胜出即大于500*k （注等于500*k不算胜出)

        public static void main(String[] args) throws Exception{

            BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));

            int k = Integer.parseInt(buf.readLine());

            A2 a[] = new A2[3*k];



            for(int i=0;i< 3*k;i++)
                a[i] = new A2(Integer.parseInt(buf.readLine()),i);

            java.util.Arrays.sort(a);

            int sa = 0;
            int sb = 0;

            for(int i=k;i< 2*k;i++){
                sa += a[i].v;
                sb += a[i+k].v;
            }

            while(true){

                int b1 = (int)(Math.random()*70)%k+k;
                int b2 = (int)(Math.random()*70)%k+2*k;
                sa = sa-a[b1].v+a[b2].v;
                sb = sb-a[b2].v+a[b1].v;
                int v = a[b1].v;
                int s = a[b1].s;
                a[b1].v = a[b2].v;
                a[b1].s = a[b2].s;
                a[b2].v = v;
                a[b2].s = s;
                if(sa>500*k&&sb>500*k)
                    break;
            }

            for(int i=0;i< 3*k;i++)
                System.out.println(a[i].s+1);

        }

    }
    class A2 implements Comparable< A2>{
        int v;
        int s;
        public A2(int v, int s) {
            super();
            this.v = v;
            this.s = s;
        }

        public int compareTo(A2 e) {
            if(this.v< e.v)
                return -1;
            else if(this.v>e.v)
                return 1;
            return 0;
        }

    }

