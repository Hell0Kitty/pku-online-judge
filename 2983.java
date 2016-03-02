//* @author:
import java.io.*;
import java.util.Scanner;
/*
 *SPFA 解决差分约束问题.一开始没另加源点一直WA....- -!~~~~
 */

class Node
{
 int dian,value;
 Node next;
 Node(int x,int h)
 {
  dian=x;
  value=h;
  next=null;
 }
 void insert(Node a)
 {
  next=a;
 }
}

class Point
{
 int dian;
 Node head;
 Node last;
 Point(int d)
 {
  dian=d;
  head=new Node(0,0);
  last=head;
 }
 void insert(Node a)
 {
  last.insert(a);
  last=last.next;
 }
}

class Quen
{
 int front,rear,num;
 int data[];
 boolean include[];

 Quen(int n)
 {
  front=rear=0;
  num=n+1;
  data=new int[n+1];
  include=new boolean[n+1];
  for(int i=0;i<=n;i++)include[i]=false;
 }

 boolean isEmpty()
 {
  if(rear==front)return true;
  return false;
 }

    boolean add(int s)
    {
     if(include[s])return false;
     data[rear]=s;
     include[s]=true;
     rear=(++rear)%num;
     return true;
    }

    int get()
    {
     int s=data[front];
     include[s]=false;
     front=(++front)%num;
     return s;
    }
}

class SPFA
{
    int numOfD;
    int distance[],count[];
    Point dian[];
    Quen q;

    SPFA(int n,Point s[])
    {
     numOfD=n;
     dian=s;
     q=new Quen(n);
     distance=new int[numOfD+1];
     count=new int[numOfD+1];
    }

    boolean haveMin()
    {
     q.add(0);
     int now,i;
     Node p;
     for(i=1;i<=numOfD;i++)
     {
      distance[i]=Integer.MAX_VALUE;
      count[i]=0;
     }
     distance[0]=0;
     count[0]=1;
     while(true)
     {
      if(q.isEmpty())break;
      now=q.get();
      p=dian[now].head;
      while(p.next!=null)
      {
       p=p.next;
       if(distance[p.dian]>distance[now]+p.value)
       {
        distance[p.dian]=distance[now]+p.value;
        if(q.add(p.dian))
        {
         count[p.dian]++;
         if(count[p.dian]==numOfD)return false;
        }
       }
      }
     }
     return true;
    }
}

public class Main {
    public static void main(String args[]) throws IOException
    {
     Scanner cin=new Scanner(System.in);
     int n,m,i,x,y,h;
     String str;
     SPFA data;
     Point points[];
     Node temp;
     boolean ok;
     while(cin.hasNextInt())
     {
      n=cin.nextInt();
      m=cin.nextInt();
      points=new Point[n+1];
      points[0]=new Point(0);
      for(i=1;i<=n;i++)
      {
       points[i]=new Point(i);
       temp=new Node(i,0);
       points[0].insert(temp);
      }
      for(i=0;i< m;i++)
      {
       str=cin.next();
       if(str.charAt(0)=='P')
       {
        x=cin.nextInt();
        y=cin.nextInt();
        h=cin.nextInt();
        temp=new Node(x,h);
        points[y].insert(temp);
        temp=new Node(y,-h);
        points[x].insert(temp);
       }
       else
       {
        x=cin.nextInt();
        y=cin.nextInt();
        temp=new Node(y,-1);
        points[x].insert(temp);
       }
      }
      data=new SPFA(n,points);
      ok=data.haveMin();
      if(ok)System.out.println("Reliable");
      else System.out.println("Unreliable");
     }
    }
}

