import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static final int a[][] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
    static int n ;
    public static final int sx0[][] = {{-2,0},{-2,1},{-1,0},{-1,1},{-1,0},{-1,-1},{-1,1},{-1,1},{-2,2}};
    public static final int sy0[][] = {{0,1},{0,2},{1,1},{1,2},{0,2},{0,1},{0,3},{1,0},{0,1}};

    public static final int sx1[][] = {{0,1},{0,2},{1,1},{1,2},{-1,1},{0,1},{1,1},{0,-1},{1,0}};
    public static final int sy1[][] = {{1,-1},{1,0},{2,-1},{2,0},{1,0},{2,0},{3,0},{1,1},{2,2}};

    public static final int s[][] = {{-1,-1},{-1,1},{1,1},{-1,1},{1,1},{1,-1},{-1,-1},{1,-1}};

    static int cx[] ;
    static int cy[] ;

    public static void main(String[] args) {


        Scanner scan = new Scanner(System.in);

        while(true){
            n = scan.nextInt();
            int m = scan.nextInt();

            if(n == 0&& m==0)
                break;

            cx = new int[m];
            cy = new int[m];
            boolean link[][] = new boolean[m][m];
            int map[][] = new int[n+1][n+1];
            for(int i=0;i<=n;i++)
            java.util.Arrays.fill(map[i], -1);

            for(int d=0;d< m;d++){
                int y = scan.nextInt();
                int x = scan.nextInt();
                map[x][y] = d;
                cx[d] = x;
                cy[d] = y;
                drawLine(link,map,x,y);

            }



            boolean flag1 = false;
            boolean flag2 = false;
            for(int i=0;i<=n;i++){
                if(map[i][0]%2==0&&bfs(map[i][0],link,m)){
                    flag1 = true;
                    break;
                }
            }
            if(!flag1){
                System.out.println("no");
                continue;
            }

            for(int i=0;i<=n;i++){
                if(map[i][0]%2==0&&map[i][0]!=m-1&&bfs(map[i][0],link,m-1)){
                    flag2 = true;
                    break;
                }
            }
            if(flag2)
                System.out.println("no");
            else
                System.out.println("yes");

        }

    }

    public static boolean bfs(int v,boolean[][] link,int m) {

        Queue< Integer> q = new LinkedList< Integer>();
        q.add(v);
        boolean visit[] = new boolean[m];
        visit[v] = true;
        while(!q.isEmpty()){
            v = q.poll();
            for(int i=0;i< m;i++){
                if(!visit[i]&&link[v][i]){
                    if(cy[i]==n)
                        return true;
                    q.add(i);
                    visit[i] = true;
                }
            }
        }

        return false;
    }

    public static void drawLine(boolean[][] link, int[][] map,int xs,int ys) {

        for(int i=0;i< 8;i++){

            int x = xs + a[i][0];
            int y = ys + a[i][1];

       if(x>=0&&x<=n&&y>=0&&y<=n&&map[x][y]%2==map[xs][ys]%2&&!link[map[x][y]][map[xs][ys]]){

                if(i==2||i==3||i==6||i==7){
                    int k ;
                    for(k=0;k< 9;k++){
                        int xa = xs + s[i][0]*sx0[k][0];
                        int ya = ys + s[i][1]*sx0[k][1];

                        int xb = xs + s[i][0]*sy0[k][0];
                        int yb = ys + s[i][1]*sy0[k][1];
                       if(check(xa,ya)&&check(xb,yb)&&map[xa][ya]!=-1
                            &&map[xb][yb]!=-1&&link[map[xa][ya]][map[xb][yb]]){
                            break;
                        }
                    }
                    if( k == 9){
                        link [map[x][y]][map[xs][ys]] = true;
                        link [map[xs][ys]][map[x][y]] = true;
                    }

                }else{
                    int k ;
                    for(k=0;k< 9;k++){
                        int xa = xs + s[i][0]*sx1[k][0];
                        int ya = ys + s[i][1]*sx1[k][1];

                        int xb = xs + s[i][0]*sy1[k][0];
                        int yb = ys + s[i][1]*sy1[k][1];
                        if(check(xa,ya)&&check(xb,yb)&&map[xa][ya]!=-1&&
	map[xb][yb]!=-1&&link[map[xa][ya]][map[xb][yb]]){
                            break;
                        }
                    }
                    if( k == 9){
                        link [map[x][y]][map[xs][ys]] = true;
                        link [map[xs][ys]][map[x][y]] = true;
                    }

                }

            }

        }

    }

    public static boolean check(int a, int b) {

        return a>=0&&b>=0&&a<=n&&b<=n;
    }
}

