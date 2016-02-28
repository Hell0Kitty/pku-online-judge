import java.io.*;
import java.util.*;

public class Main{
	static Scanner cin;
	static int count=0;
	public static void main(String args[]){
		cin = new Scanner(System.in);
		int n;
		while((n=cin.nextInt())!=0)
			run(n);
		
	}
	
	static void run(int n){
		Point start,end;
		start = new Point(n, cin);
		end   = new Point(n, cin);
		
		ArrayList<PointSet> Mset = new ArrayList<PointSet>();
		
		PointSet startSet = new PointSet();
		PointSet endSet = new PointSet();
		startSet.add(start);
		endSet.add(end);
		
		Mset.add(startSet);
		Mset.add(endSet);
		
		Point A,B;
		PointSet setA=new PointSet(), setB=new PointSet();
		while(true){
			if(cin.hasNext("-1") == true){
				cin.nextInt();
				break;
			}
				
			setA = null;
			setB = null;
			A = new Point(n, cin);
			B = new Point(n, cin);
			
			for(PointSet set:Mset){
				if(set.contains(A))
					setA = set;
				if(set.contains(B))
					setB = set;
			}
			
			if((setA != null)&&(setB != null)){
				if(setA != setB){
					setA.addAll(setB);
					Mset.remove(setB);
				}	
			}
			else if(setA != null)
				setA.add(B);
			else if(setB != null)
				setB.add(A);
			else{
				setA = new PointSet();
				setA.add(A);
				setA.add(B);
				Mset.add(setA);
			}
										
		}
		
		startSet = null;
		endSet   = null;
		for(PointSet set:Mset){
			if(set.contains(start))
				startSet = set;
			if(set.contains(end))
				endSet = set;
		}
		
		if(startSet == endSet)
			System.out.println("Maze #"+(++count)+" can be travelled");
		else
			System.out.println("Maze #"+(++count)+" cannot be travelled");
	}
}

class Point implements Comparable{
	int num;
		
	public Point(int n, Scanner cin){
		num=0;
		for(int i=0;i<n;i++)
			num = 10*num+cin.nextInt();
	}
	
	public int compareTo(Object another){
		Point p = (Point)another;
		
		return this.num-p.num;
	}
}

class PointSet extends TreeSet<Point>{
	
}