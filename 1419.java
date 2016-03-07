import java.io.*;
import java.util.*;

public class Main{
	static Scanner cin;
	public static void main(String args[]){
		cin = new Scanner(System.in);
		
		int m = cin.nextInt();
		for(int i=0;i<m;i++)
			run();
	}
	
	static void run(){
		int n = cin.nextInt();
		int k = cin.nextInt();
		
		Graph graph = new Graph(n);
		for(int i=0;i<k;i++)
			graph.addEdge(cin.nextInt(), cin.nextInt());
		
		graph.Coloring(0);
		System.out.println(graph.maxBlack);
		graph.record.print();
	}
}

class Graph{
	int n;
	Node[] nodes;
	
	int maxBlack=-1;
	Record record;
	
	public Graph(int n){
		this.n = n;
		
		nodes = new Node[n];
		for(int i=0;i<n;i++)
			nodes[i] = new Node();
		
		record = new Record();
	}
	
	void addEdge(int m, int n){
		nodes[m-1].add(nodes[n-1]);
		nodes[n-1].add(nodes[m-1]);
	}
	
	void Coloring(int colored){
		if(colored<n){
			int position=0;
			while(nodes[position].color != 0)
				position = (position+1)%n;
			Node node = nodes[position];
			
			node.color = 'b';
			if(node.check() == true)
				Coloring(colored+1);
			
			node.color = 'w';
			Coloring(colored+1);
			
			node.color = 0;
			return;	
		}	
		
		int tmp = countBlack();
		if(tmp > maxBlack){
			maxBlack = tmp;
			record.clear();
			
			for(int i=0;i<n;i++)
				if(nodes[i].color == 'b')
					record.add(new Integer(i+1));
		}
			
		
	}
		
	
	int countBlack(){
		int count=0;
		for(int i=0;i<n;i++)
			if(nodes[i].color == 'b')
				count++;
		return count;
	}
}

class Node{
	char color=0;
	LinkedList<Node> linkList;
	
	void setColor(char c){
		color = c;
	}
	void add(Node another){
		if(linkList==null)
			linkList = new LinkedList<Node>();
		
		linkList.add(another);
	}
	
	boolean isEdgeColored(){
		for(Node n:linkList)
			if(n.color == 0)
				return false;
		return true;
	}
	
	boolean check(){
		if(color=='w')
			return true;
			
		for(Node n:linkList)
			if(n.color=='b')
				return false;
		return true;
	}
}

class Record extends ArrayList<Integer>{
	void print(){
		for(Integer p:this)
			System.out.print(p+" ");
		System.out.println();
	}
	
}