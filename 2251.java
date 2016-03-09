//* @author:
import java.util.*;

class  point {
    int x;
    int y;
    int z;
    int step;

  public point(int x,int y,int z,int step){
    this.x=x;
    this.y=y;
    this.z=z;
    this.step=step;
  }


 public int  getX(){
   return this.x;
 }

 public int getY(){
   return this.y;
 }

public int getZ(){
  return this.z;
 }

 public int getStep(){
   return this.step;
}

}

public class Main {
  //移动方向可以是上，下，左，右，前，后，六个方向
 static int dir[][] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
 char map[][][];//三维地图,有三层
 int R, L, C;

 public Main(char map[][][],int L,int R,int C){
    this.map=map;
    this.L=L;
    this.R=R;
    this.C=C;
}

int bfs(int x, int y, int z) {

    ArrayList queue=new ArrayList();

    queue.add(new point(x,y,z,0));

    while(queue.size()!=0) {

        for(int i = 0; i < 6; i++) {
            //队头元素出队；
             point head=queue.get(0);
            int a = head.x + dir[i][0];
            int b = head.y + dir[i][1];
            int c = head.z + dir[i][2];
            if(a >= 0 && a < L && b >= 0 && b < R && c >= 0 && c < C && map[a][b][c] == 'E')
                return head.step + 1;
            if(a >= 0 && a < L && b >= 0 && b < R && c >= 0 && c < C && map[a][b][c] != '#') {
                  //元素入队；
                queue.add(new point(a,b,c,head.step+1));

                map[a][b][c] = '#';

            }
        }
       queue.remove(0);
    }
    return -1;
}


 public static void main(String[] args){
  Scanner in = new Scanner(System.in);
    int a, b, c;
    int L1,R1,C1;
    while(in.hasNext()) {
       L1=in.nextInt();
       R1=in.nextInt();
       C1=in.nextInt();
       if(L1==0&&R1==0&&C1==0) break;
        a = b = c = 0;

        char map1[][][]=new char[L1][R1][C1];

        for(int i = 0; i < L1; i++)
          for(int j = 0; j < R1; j++){
           map1[i][j]=in.next().toCharArray();
           for(int k=0;k< C1;k++){
                if(map1[i][j][k] == 'S') {
                    a = i;
                    b = j;
                    c = k;
                }
            }
         }


        Main m=new Main(map1,L1,R1,C1);

        int sum = m.bfs(a, b, c);
        if(sum != -1)
            System.out.printf("Escaped in %d minute(s).\n", sum);
        else
            System.out.printf("Trapped!\n");
    }
   }
}

