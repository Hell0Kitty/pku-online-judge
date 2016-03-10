//* @author:
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.Comparator;
import java.util.ArrayList;
public class Main {
 public static class node
 {
  double x,y,s,r,d,t;
  node(double xx,double yy,double ss,double rr,double dd,double tt)
  {
   x=xx;y=yy;s=ss;r=rr;d=dd;t=tt;
  }
  double getx(){return x;}
  double gety(){return y;}
  double gets(){return s;}
  double getr(){return r;}
  double getd(){return d;}
  double gett(){return t;}
 }
/* class MyComparator implements Comparator
 {
     public int compare(Object  obj1, Object obj2)
     {
      node w1 = (node)obj1;
      node w2 = (node)obj2;
         return w1.get() < w2.get() ? 1 : -1;
     }
 }*/

 public static void main(String[] args) {
    int n,i;
    double pt,hp,x,y,s,r,d,t;
    Scanner in =new Scanner(System.in);

    node p[] = new node [101];
    while(in.hasNext())
    {
     n=in.nextInt();
     pt=100;
        for(i=0;i< n;i++)
        {
         x=in.nextDouble();
         y=in.nextDouble();
         s=in.nextDouble();
         r=in.nextDouble();
         d=in.nextDouble();
         t=Math.sqrt((x-100.0)*(x-100.0)+y*y)-r;
         if(t< 0) t=0;
         p[i]=new node(x,y,s,r,d,t);
        }
        hp=in.nextDouble();
           Arrays.sort(p, 0, n, new Comparator< node>(){
               public int compare(node w1, node w2) {
                  return w1.gett() > w2.gett() ? 1 : -1;
               }
           });

//    for(i=0;i< n;i++)System.out.println(p[i].t);
           i=0;
           while(p[i].gett()<=pt)
           {
              hp-=p[i].getd();
              pt+=p[i].gets();
              i++;
              if(i==n)break;
           }
           if(hp<=0)System.out.println("Danger!");
           else System.out.println("Safe!");
    }
    }
}

