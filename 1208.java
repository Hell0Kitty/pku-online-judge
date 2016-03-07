import java.util.*;

public class Main{
	static Scanner cin;
	static MyList list;
	public static void main(String args[]){
		cin = new Scanner(System.in);
		int n = cin.nextInt();
		list = new MyList();
		for(int i = 0;i < n;i++)
			list.add(new Stack(new Integer(i)));
		
		
		while(true)
			if(run() == false)
				break;
		
		show();

		return;
	}
	
	static boolean run(){
		String command = cin.next();
		
		if(command.equals("quit"))
			return false;
		
		Integer a = new Integer(cin.nextInt());
		String scommand = cin.next();
		Integer b = new Integer(cin.nextInt());
		
		if(command.equals("move"))
			return move(a,b,scommand);
		else
			return pile(a,b,scommand);
	}
	
	static boolean move(Integer a,Integer b,String command){
		Stack A = list.contains(a);
		Stack B = list.contains(b);
		if(A == B)
			return true;
		
		if(command.equals("over")){
			B.add(a);
			A.removeSingle(a);
		}
		else{
			Iterator<Integer> iterator = B.getLast(b).iterator();
			while(iterator.hasNext())
				list.get(iterator.next()).selfadd();
			B.removeLast(b).add(a);
			A.removeSingle(a);
		}


		
		return true;	
	}
	
	static boolean pile(Integer a,Integer b,String command){
		Stack A = list.contains(a);
		Stack B = list.contains(b);
		if(A == B)
			return true;
		
		if(command.equals("over")){
			B.add(a).add(A.getLast(a));
			A.removeLast(a).removeSingle(a);
		}
		else{
			Iterator<Integer> iterator = B.getLast(b).iterator();
			while(iterator.hasNext())
				list.get(iterator.next()).selfadd();
			B.removeLast(b).add(a).add(A.getLast(a));
			A.removeLast(a).removeSingle(a);
		}

		return true;		
	}

	static void show(){
		for(Stack stack:list)
			stack.show();
	}
}


class Stack{
	ArrayList<Integer> contents;
	Integer n;
	public Stack(Integer n){
		this.n = n;
		contents = new ArrayList<Integer>();
		contents.add(n);
		return;
	}
	
	boolean contains(Integer value){
		for(Integer p:contents)
			if(p.equals(value))
				return true;
		return false;
	}
	
	Stack add(List<Integer> others){
		contents.addAll(others);
		return this;
	}
	void selfadd(){
		contents.add(n);
	}
	Stack add(Integer n){
		contents.add(n);
		return this;
	}
	
	Stack removeLast(Integer value){
		int num = contents.indexOf(value);
		int size = contents.size();
		for(int i = num+1;i < size;i++)
			contents.remove(num+1);
		return this;
	}
	Stack removeSingle(Integer value){
		contents.remove(value);
		return this;
	}
	
	List<Integer> getLast(Integer value){
		int num = contents.indexOf(value);
		return contents.subList(num+1,contents.size());
	}
	
	void show(){

		System.out.print(n+":");
		for(Integer p:contents)
			System.out.print(" "+p);
		System.out.println();
	}
	
	
}


class MyList extends ArrayList<Stack>{
	Stack contains(Integer value){
		for(Stack stack:this)
			if(stack.contains(value)){
				return stack;
			}
		return null;
	}
}