import java.io.*;
public class Main {
    static double A = Math.PI*2/3;
    public static void main(String[] args)throws Exception{

        BufferedReader br = new BufferedReader(new
                InputStreamReader(System.in));
        String s = br.readLine();
        String[] ss;
        int num = Integer.parseInt(s);
        int x1, y1, x2, y2, x3, y3;
        for(int i=0;i< num;i++){
            s = br.readLine();
            ss = s.split(" ",7);
            x1 = Integer.parseInt(ss[1]);
            y1 = Integer.parseInt(ss[2]);
            x2 = Integer.parseInt(ss[3]);
            y2 = Integer.parseInt(ss[4]);
            x3 = Integer.parseInt(ss[5]);
            y3 = Integer.parseInt(ss[6]);
            System.out.println(checkPos(x1, y1, x2, y2, x3, y3)?"Yes":"No");
        }
    }

    static boolean checkPos(int x1, int y1, int x2, int y2, int x3, int y3){
        //if one is in the center, this is impossible
        if(x1==0 && y1==0 || x2==0 && y2==0 || x3==0 && y3==0)
            return false;
        double angle = Math.atan2(x1, y1);
        double angle2 = Math.atan2(x2, y2);
        double angle3 = Math.atan2(x3, y3);
        //if two points are of the same angle
        if(angle==angle2 || angle2==angle3 || angle3==angle)
            return false;
        double d12 = get(angle, angle2);
        double d23 = get(angle2, angle3);
        double d31 = get(angle3, angle);
        //120 degrees each
        if(d12==d23 && d23==d31 && d31==d12)
            return true;
        //maximum distinction is less than 120 degrees
        if(checkVal(d12) && checkVal(d23) && checkVal(d31))
            return false;
        return true;
    }
    static double get(double a, double a2){
        double dis = Math.abs(a-a2);
        return dis>Math.PI ? 2*Math.PI-dis:dis;
    }
    static boolean checkVal(double d){
        return d<=A;
    }
}

