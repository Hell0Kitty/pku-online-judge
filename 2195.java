    import java.util.LinkedList;
    import java.util.Queue;
    import java.util.Scanner;

    public class Main{

        static int flow[][];
        static int cap[][];
        static int cost[][];
        static int n ;
        public static final int MAX = 1000001;
        static int s,t;

        public static void main(String[] args) {

            Scanner scan = new Scanner(System.in);

            while(true){
                int r = scan.nextInt();
                int c = scan.nextInt();
                if(r==0&&c==0)
                    break;

                char map[][] = new char[r][c];
                n = 0;

                for(int i=0;i< r;i++){
                    map[i] = scan.next().toCharArray();
                    for(int j=0;j< c;j++){
                        if(map[i][j]=='H'){
                            n++;
                        }
                    }
                }

                N h[] = new N[n];
                N m[] = new N[n];
                int hNum = 0;
                int mNum = 0;

                for(int i=0;i< r;i++){
                    for(int j=0;j< c;j++){
                        if(map[i][j] == 'H')
                            h[hNum++] = new N(i,j);
                        if(map[i][j] == 'm')
                            m[mNum++] = new N(i,j);
                    }
                }
                cost = new int[2*n+2][2*n+2];
                cap = new int[2*n+2][2*n+2];
                flow = new int[2*n+2][2*n+2];

                s = 0;
                t = 2*n+1;

                for(int i=1;i<=n;i++){
                    cap[s][i] = 1;
                    cap[i+n][t] = 1;
                }
                for(int i=0;i< n;i++){
                    for(int j=0;j< n;j++){
                        cap[i+1][j+n+1] = 1;
                        cost[i+1][j+n+1] = Math.abs(m[i].x-h[j].x)+Math.abs(m[i].y-h[j].y);
                        cost[j+n+1][i+1] = -cost[i+1][j+n+1];
                    }
                }

                minCost();

                int minCostFlow = 0;

                for(int i=1;i<=n;i++){
                    for(int j=n+1;j<=2*n;j++)
                        minCostFlow += cost[i][j]*flow[i][j];
                }

                System.out.println(minCostFlow);
            }

        }

        public static void minCost() {

            int dist[] = new int[2*n+2];
            int pre[] = new int[2*n+2];
            boolean visit[] = new boolean[2*n+2];
            Queue< Integer> q = new LinkedList< Integer>();

            while(true){
                java.util.Arrays.fill(dist, MAX);
                java.util.Arrays.fill(pre, -1);
                java.util.Arrays.fill(visit, false);

                q.add(s);
                visit[s] = true;
                dist[s] = 0;

                while(!q.isEmpty()){
                    int v = q.poll();
                    visit[v] = false;
                    for(int i=1;i< 2*n+2;i++){
                        if(flow[v][i]< cap[v][i]&&dist[i]>dist[v]+cost[v][i]){
                            dist[i] = dist[v] + cost[v][i];
                            pre[i] = v;
                            if(!visit[i]){
                                q.add(i);
                                visit[i] = true;
                            }
                        }
                    }
                }

                if(pre[t]==-1)
                    break;
                int minFlow = MAX;
                for(int u=t;pre[u]!=-1;u=pre[u])
                    minFlow = Math.min(minFlow, cap[pre[u]][u]-flow[pre[u]][u]);
                for(int u=t;pre[u]!=-1;u=pre[u]){
                    flow[pre[u]][u] += minFlow;
                    flow[u][pre[u]] -= minFlow;
                }

            }

        }

    }

    class N{
        int x;
        int y;
        public N(int x, int y) {
            super();
            this.x = x;
            this.y = y;
        }

    }

