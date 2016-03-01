import java.util.*;

    public class Main{

        static long height[];
        static long tree[];
        static XY p[];
        static TreeSet< Long> ts;
        static Iterator< Long> iterator;
        static int m;
        static long sum[];
        static long maxSum[];

        public static void main(String[] args)throws Exception {

            Scanner scan = new Scanner(System.in);

            while(scan.hasNext()){
                int n = scan.nextInt();
                int W = scan.nextInt();
                int H = scan.nextInt();
                height = new long[2*n];
                ts = new TreeSet< Long>();

                p = new XY[n << 1];

                for(int i=0;i< n;i++){
                  p[i] = new XY(scan.nextLong(),scan.nextLong(),scan.nextLong());
			 //x扫描线当遇到p[i].x+W 表示 以p[i].x为左下角的矩形已搜索结束
                    p[i+n] = new XY(p[i].x+W,p[i].y,-p[i].c);
                    ts.add(p[i].y); //所以是-p[i].c 这样刚好可以中和成0表示没有加上它
                    ts.add(p[i].y+H);
                }
                m = ts.size();
                iterator = ts.iterator();
                tree = new long[m<< 1];
                sum = new long[(m<< 1)+2];
                maxSum = new long[(m<< 1)+2];

                createLineTree(1);

                java.util.Arrays.sort(p);

                n *= 2;

                long ans = 0;
                for(int i=0;i< n;i++){             //原理同 x扫描线 相似
                    insert(p[i].y,p[i].c);
                    insert(p[i].y+H,-p[i].c);
                    ans = Math.max(ans, maxSum[1]);
                }
                System.out.println(ans);
            }

        }

        private static void insert(long y, long c) {

            int p = 1;
            while(tree[p]!=y){            // 搜索要修改的点
                if(y< tree[p])
                    p <<= 1;
                else
                    p = (p<<1)+1;
            }

            while(p!=0){//更新 前面找到的修改点以及 它所有祖先点
                sum[p] += c;
                long t1 = maxSum[2*p]; //每个根结点是左右子树一起更新的结果
		//  因为此树是有序的 所以每一棵子树代表一个范围左根右）
                long t2 = sum[p]-sum[2*p+1]+maxSum[2*p+1];
	    // 而这个范围的maxSum 值 就放在根中根中的sum值是其所有子树的总和
                maxSum[p] = Math.max(t1, t2);
                p /= 2;
            }

        }

        public static void createLineTree(int p) {

            if(2*p<=m)  // 建立二叉 排序树
                createLineTree(2*p);
            tree[p] = iterator.next();
            if(2*p+1<=m)
                createLineTree(2*p+1);
        }

    }
    class XY implements Comparable< XY>{

        long x;
        long y;
        long c;

        public XY(long x, long y, long c) {
            super();
            this.x = x;
            this.y = y;
            this.c = c;
        }


        public int compareTo(XY e) {

            if(this.x< e.x)
                return -1;
            else if(this.x>e.x)
                return 1;
            else{
                if(this.c< e.c)
                    return -1;
                else if(this.c>e.c)
                    return 1;
                return 0;
            }

        }

    }

