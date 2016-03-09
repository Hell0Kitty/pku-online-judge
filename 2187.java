 import java.util.*;
class Line {//线
 Point p1, p2;
 Line(Point p1, Point p2) {
  this.p1 = p1;
  this.p2 = p2;
 }
  public Point getP1(){
    return p1;
  }

  public Point getP2(){
    return p2;
  }

  public double getLength() {
    double dx = Math.abs(p1.x - p2.x);
    double dy = Math.abs(p1.y - p2.y);
    return Math.sqrt(dx * dx + dy * dy);
  }


}

class Point{//点
  double x;
  double y;

  public Point(double x,double y){
     this.x=x;
     this.y=y;
  }
}


/*
*   分治法求凸包
*/
class QuickTuBao  {
  List< Point> pts = null;//点集
  List< Line> lines = new ArrayList< Line>();//点集pts的凸包

  public void setPointList(List< Point> pts) {
      this.pts = pts;
  }

  public QuickTuBao(List< Point> pts){
      this.pts=pts;
  }

  //求凸包，结果存入lines中
  public List< Line> eval() {
      lines.clear();
      if (pts == null || pts.isEmpty()) { return lines; }
          List< Point> ptsLeft = new ArrayList< Point>();//左凸包中的点
          List< Point> ptsRight = new ArrayList< Point>();//右凸包中的点

        //按x坐标对pts排序
         Collections.sort(pts, new Comparator< Point>() {
             public int compare(Point p1, Point p2) {
              if(p1.x-p2.x>0) return 1;
              if(p1.x-p2.x< 0) return -1;
              return 0;
             }

        });

            Point p1 = pts.get(0);//最左边的点
            Point p2 = pts.get(pts.size()-1);//最右边的点,用直线p1p2将原凸包分成两个小凸包
            Point p3 = null;
            double area = 0;
            for (int i = 1; i < pts.size(); i++) {
              p3 = pts.get(i);
              area = getArea(p1, p2, p3);//求此三点所成三角形的有向面积
                if (area > 0) {
                 ptsLeft.add(p3);
                } else if (area < 0) {
                  ptsRight.add(p3);
                }
              }
              d(p1, p2, ptsLeft);//分别求解
              d(p2, p1, ptsRight);
              return lines;
   }

   private void d(Point p1, Point p2, List< Point> s) {
     //s集合为空
     if (s.isEmpty()) {
       lines.add(new Line(p1, p2));
       return;
     }
     //s集合不为空，寻找Pmax
     double area = 0;
     double maxArea = 0;
     Point pMax = null;
     for (int i = 0; i < s.size(); i++) {
      area = getArea(p1, p2, s.get(i));//最大面积对应的点就是Pmax
      if (area > maxArea) {
        pMax = s.get(i);
        maxArea = area;
       }
      }
      //找出位于(p1, pMax)直线左边的点集s1
      //找出位于(pMax, p2)直线左边的点集s2
       List< Point> s1 = new ArrayList< Point>();
       List< Point> s2 = new ArrayList< Point>();
       Point p3 = null;
       for (int i = 0; i < s.size(); i++) {
         p3 = s.get(i);
         if (getArea(p1, pMax, p3) > 0) {
            s1.add(p3);
         } else if (getArea(pMax, p2, p3) > 0) {
            s2.add(p3);
         }
        }
       //递归
       d(p1, pMax, s1);
       d(pMax, p2, s2);
    }
    // 三角形的面积等于返回值绝对值的二分之一
    // 当且仅当点p3位于直线(p1, p2)左侧时，表达式的符号为正
    private double getArea(Point p1, Point p2, Point p3) {
           return p1.x * p2.y + p3.x * p1.y + p2.x * p3.y -
             p3.x * p2.y - p2.x * p1.y - p1.x * p3.y;
    }
}

public class Main {

  private static double dis(Point p1,Point p2){
     double dx = Math.abs(p1.x - p2.x);
     double dy = Math.abs(p1.y - p2.y);
     return (dx * dx + dy * dy);
  }

  //计算最长距离的平方
  private static void answer(List< Line> ls) {

    List< Point> l=new ArrayList< Point>();
   for (int i = 0; i < ls.size(); i++) {
      Line line=ls.get(i);
      Point p1=line.getP1();
      Point p2=line.getP2();
      if(!l.contains(p1)) l.add(p1);
      if(!l.contains(p2)) l.add(p2);

   }
   double ans=0;
    for (int i=0;i< l.size()-1;i++)
        for (int j=i+1;j< l.size();j++){
           double tem=dis(l.get(i),l.get(j));
            if (ans< tem)
                ans=tem;
        }
    System.out.printf("%.0f\n",ans);

  }

  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    int n = cin.nextInt();
    List< Point> pts = new ArrayList< Point>(n);
    int x, y;
    for (int i = 0; i < n; i++) {
      x = cin.nextInt();
      y = cin.nextInt();
      pts.add(new Point(x, y));
    }
    QuickTuBao qt = new QuickTuBao(pts);
    List< Line> ls = qt.eval();
    answer(ls);
  }
}


