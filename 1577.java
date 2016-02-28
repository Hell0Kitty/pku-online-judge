
import java.util.*;


public class Main {
	
	public static void main(String[] args){
		Scanner in =new Scanner(System.in);
		BinarySearchTree<Character> bt = new BinarySearchTree<Character>();
		boolean stop = false;
		while(true){
			String input = in.next();
			
			LinkedList<String> list = new LinkedList<String>();
			while(input.charAt(0) != '*'){
				if(input.charAt(0) == '$'){
					stop = true;
					break;
				}
				list.addFirst(input);
				input = in.next();
			}
			
			for(int i = 0; i < list.size(); i++){
				input = list.get(i);
				for(int j = 0; j < input.length(); j++){
					bt.insert((Character)input.charAt(j));
				}
			}
			bt.printTree();
			if(stop){
				return;
			}
			System.out.println();
			bt = new BinarySearchTree<Character>();
		}
	}
	
}

class BinaryNode<T extends Comparable<? super T>> {
	BinaryNode<T> left;
	BinaryNode<T> right;
	T element;
	
	public BinaryNode(T theElement){
		this(theElement, null, null);
	}
	public BinaryNode(T theElement, BinaryNode<T> lt, BinaryNode<T> rt){
		element = theElement;
		left = lt;
		right = rt;
	}
	public T getElement(){
		return this.element;
	}
	public BinaryNode<T> getLeft(){
		return this.left;
	}
	public BinaryNode<T> getRight(){
		return this.right;
	}
	public String toString(){
		return element + "";
	}
}

class BinarySearchTree<T extends Comparable<? super T>>{
	private BinaryNode<T> root;

	public BinarySearchTree(){
		root = null;
	}
	public BinarySearchTree(BinaryNode<T> t){
		root = t;
	}
	public void makeEmpty(){
		root = null;
	}
	public boolean isEmpty(){
		return root == null;
	}
	public T find(T x){
		return elementAt(find(x, root));
	}
	
	public void insert(T x){
		root = insert(x, root);
	}
	public void printTree(){
		printTree(root);
	}
	
	private T elementAt(BinaryNode<T> t){
		return t.element;
	}
	private BinaryNode<T> find(T x, BinaryNode<T> t){
		if(t == null){
			return null;
		}
		if(x.compareTo(t.element) < 0){
			return find(x, t.left);
		}
		else if(x.compareTo(t.element) == 0){
			return t;
		}
		else{
			return find(x, t.right);
		}
	}
	
	private BinaryNode<T> insert(T x, BinaryNode<T> t){
		if(t == null){
			t = new BinaryNode<T>(x, null, null);
		}
		else if(x.compareTo(t.element) < 0){
			t.left = insert(x, t.left);
		}
		else if(x.compareTo(t.element) > 0){
			t.right = insert(x, t.right);
		}
		else;
		return t;
	}
	private void printTree(BinaryNode<T> t){
		if(t != null){	
			System.out.print(t.element);
			printTree(t.left);
			printTree(t.right);
		}
	}
    
   
}

