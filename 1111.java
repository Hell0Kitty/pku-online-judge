import java.io.*;
class Main
{
    static int cnt;
    static char[][] map;
    static int[][] bool;
    public static void main(String[] args) throws IOException
    {
        InputStreamReader is=new InputStreamReader(System.in);
        BufferedReader in=new BufferedReader(is);
        while(true)
        {
            cnt=0;
            String[] ss=in.readLine().split(" ");
            int row=Integer.parseInt(ss[0]);
            int col=Integer.parseInt(ss[1]);
            int x=Integer.parseInt(ss[2]);
            int y=Integer.parseInt(ss[3]);
            if(row==0&&col==0)break;
            map=new char[row+2][col+2];
            bool=new int[row+2][col+2];
            for(int i=1;i<=row;i++)
            {
                for(int j=1;j<=col;j++)
                    map[i][j]=(char)in.read();
                in.readLine();
            }
            f(x,y);
            System.out.println(cnt);
        }
    }
    static void f(int x,int y)
    {
        if(bool[x][y]==1)return;
        bool[x][y]=1;
        if (map[x-1][y]!='X')cnt++;
        if (map[x+1][y]!='X')cnt++;
        if (map[x][y-1]!='X')cnt++;
        if (map[x][y+1]!='X')cnt++;
        for(int i=x-1;i< x+2;i++)
            for(int j=y-1;j< y+2;j++)
                if(map[i][j]=='X')f(i,j);
    }
}


