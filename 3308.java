mport java.util.ArrayList;
    import java.util.LinkedList;
    import java.util.List;
    import java.util.Queue;
    import java.util.Scanner;

    public class Main{

        static List< Integer> map[];
        static double cap[][];
        static double flow[][];
        static int s,t;
        static int R,C;
        public static final double INF = 1e8;
        static double minCost;
        static int dist[];

        public static void main(String[] args) {

            Scanner scan = new Scanner(System.in);

            int N = scan.nextInt();

            for(int c=0;c< N;c++){
                R = scan.nextInt();
                C = scan.nextInt();
                int L = scan.nextInt();

                minCost = 0;
                cap = new double[R+C+2][R+C+2];
                flow = new double[R+C+2][R+C+2];
                map = new ArrayList[R+C+2];
                for(int i=0;i< R+C+2;i++)
                    map[i] = new ArrayList< Integer>();

                s = 0;
                t = R+C+1;
                for(int i=1;i<=R;i++){
                    cap[0][i] = Math.log10(scan.nextDouble());
                    map[0].add(i);
                    map[i].add(0);
                }
                for(int i=1;i<=C;i++){
                    cap[i+R][t] = Math.log10(scan.nextDouble());
                    map[i+R].add(t);
                    map[t].add(i+R);
                }

                for(int i=0;i< L;i++){
                    int a = scan.nextInt();
                    int b = scan.nextInt();
                    cap[a][b+R] = INF;
                    map[a].add(b+R);
                    map[b+R].add(a);
                }

                while(BFS())
                    minCost += DFS(s,INF);

                System.out.printf("%.4f",Math.pow(10, minCost));
                System.out.println();

            }

        }

        public static double DFS(int s, double flow) {

            if(s == t)
                return flow;
            double subFlow = 0;

            for(int i=0;i< map[s].size();i++){
                int j = map[s].get(i);
                if(dist[s]+1==dist[j]&&eps(cap[s][j])>0){
                    double adjustFlow = DFS(j,Math.min(flow-subFlow, cap[s][j]));
                    subFlow += adjustFlow;

                    cap[s][j] -= adjustFlow;
                    cap[j][s] += adjustFlow;
                }
            }

            return subFlow;
        }

        public static boolean BFS() {
            Queue< Integer> q = new LinkedList< Integer>();
            dist = new int[R+C+2];
            boolean visit[] = new boolean[R+C+2];
            q.add(s);
            visit[s] = true;
            dist[s] = 1;
            while(!q.isEmpty()){
                int v = q.poll();
                for(int i=0;i< map[v].size();i++){
                    int j = map[v].get(i);
                    if(!visit[j]&&eps(cap[v][j])>0){
                        visit[j] = true;
                        dist[j] = dist[v] + 1;
                        q.add(j);
                    }
                }
            }

            return visit[t];
        }

        public static double eps(double ds) {

            return ds< 1e-8?0:ds;
        }
    }
