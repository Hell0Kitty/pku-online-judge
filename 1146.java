import java.io.*;
import java.util.*;

public class Main{
	static Scanner cin;
	public static void main(String args[]){
		cin = new Scanner(System.in);
		while(run(cin.next()))
				;
	}

	static boolean run(String input){
		if(input.compareTo("#") == 0)
			return false;
		
		System.out.println(next(input));
		return true;
	}

	static String next(String s){
		char[] map = s.toCharArray();

		int count = map.length-1;

		while(count>0){
			if(map[count-1] < map[count])
				break;
			count--;
		}	

		if(count==0)
			return "No Successor";
		
		char node = map[count];
		int position = count;
		for(int i=count;i<map.length;i++)
			if((map[i]>map[count-1])&&(map[i]<node)){
				node = map[i];
				position = i;
			}

		map[position] = map[count-1];
		map[count-1]  = node;

		PriorityQueue<Char> heap = new PriorityQueue<Char>();
		for(int i=count;i<map.length;i++)
			heap.add(new Char(map[i]));

		for(int i=count;i<map.length;i++)
			map[i] = heap.poll().c;

		return new String(map);

	}

}

class Char implements Comparable{
	char c;

	public Char(char c){
		this.c = c;
	}
	public int compareTo(Object o){
		Char another = (Char)o;
		return this.c-another.c;
	}
}
