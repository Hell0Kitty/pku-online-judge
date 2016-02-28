
import java.util.*;

public class Main{
	public static void main(String[] args){
		LinkedList<Integer> list;
		Scanner in = new Scanner(System.in);
		int n;
		int left;
		int i, j;
		int count = 1;
		while(in.hasNext()){
			n = in.nextInt();
			left = in.nextInt();
			list = new LinkedList<Integer>();
			BinarySearchTreeWithRank bt = new BinarySearchTreeWithRank();
			for(i = 1; i <= n; i++){
				bt.insert(i);
			}
			for(i = 0; i < 20; i++){
				list.addLast(in.nextInt());
			}
			j = 0;
			//bt.inorder(bt.root);
			//System.out.println();
			while(j < list.size()){
				int cut = list.get(j);
				int p = cut, q = 0;
				int size0 = bt.size;
				while(p <= size0){
					if(bt.findKth(p-q) != -1){
						bt.remove(bt.findKth(p-q));
						q++;
					}
					//System.out.println(p +" : " + bt.size + " : " + q);
					p += cut;
					if(bt.size == left){
						break;
					}
					//bt.inorder(bt.root);
					//System.out.println();
				}
				if(bt.size == left){
					break;
				}
				j++;
			}
			System.out.println("Selection #" + count++);
			for(i = 1; i < left; i++){
				System.out.print(bt.findKth(i) + " ");
			}
			System.out.println(bt.findKth(left));
			System.out.println();
		}
		
		/*BinarySearchTreeWithRank bt = new BinarySearchTreeWithRank();
		int a[] = {11,24,27,46,79 ,95, 97};
		for(i = 1; i < a.length; i++ ){
			bt.insert(i);
			//int temp = (int)(Math.random()*100);
			//System.out.print(temp + ",");
			//bt.insert(temp);
		}
		System.out.println();
		bt.inorder(bt.root);
		System.out.println();
		System.out.println(bt.findKth(3));
		bt.remove(3);
		bt.inorder(bt.root);
		System.out.println();
		System.out.println(bt.findKth(3));
		bt.remove(bt.findKth(3));
		bt.inorder(bt.root);
		System.out.println();
		System.out.println(bt.findKth(4));
		bt.remove(2);
		System.out.println(bt.findKth(2));*/
	}
}

class BinarySearchTreeWithRank{
	
	BinaryNodeWithRank root;
	int size;
	
	class BinaryNodeWithRank{
		int v;
		BinaryNodeWithRank left, right;
		int rank;
		int height;
	}
	
	public BinaryNodeWithRank insert(int v, BinaryNodeWithRank t){
		if(t == null){
			t = new BinaryNodeWithRank();
			t.v = v;
			t.rank = 1;
			return t;
		}
		if(v < t.v){
			t.left = insert(v, t.left);
			t.rank ++;
			
			if(height(t.left) - height(t.right) == 2){
				if(v < t.left.v){
					t =  rotateWithLeftChild(t);
				}
				else{
					t = doubleWithLeftChild(t);
				}
			}
		}
		else if(v > t.v){
			t.right = insert(v, t.right);
			if(height(t.right) - height(t.left) == 2){
				if(v > t.right.v){
					t = rotateWithRightChild(t);
				}
				else{
					t = doubleWithRightChild(t);
				}
			}
		}
		t.height = Math.max(height(t.left), height(t.right)) + 1;
		return t;
	}
	
	private int height(BinaryNodeWithRank t){
		return t == null ? -1 : t.height;
	}
	
	public void insert(int v){
		root = insert(v, root);
		size++;
	}
	public void remove(int v){
		root = remove(v, root);
		size--;
	}
	public int findKth(int k){
		return findKth(k, root);
	}
	public int findKth(int k, BinaryNodeWithRank t){
		if(t == null){
			return -1;
		}
		if(t.rank < k){
			return findKth(k - t.rank, t.right);
		}
		else if(t.rank > k){
			return findKth(k, t.left);
		}
		else{
			return t.v;
		}
	}
	
	public BinaryNodeWithRank remove(int v, BinaryNodeWithRank t){
		if(v < t.v){
			t.left = remove(v, t.left);
			t.rank--;
		}
		else if(v > t.v){
			t.right = remove(v, t.right);
		}
		else if(t.left != null && t.right != null){
			t.v = findMin(t.right).v;
			t.right = removeMin( t.right );
		}
		else{
			return (t.left == null ? t.right : t.left);
		}
		return t;
	}
	
	private BinaryNodeWithRank removeMin(BinaryNodeWithRank tt){
		BinaryNodeWithRank t = tt;
		if( t.left == null )
            return t.right;
            
        t.left = removeMin( t.left );
        t.rank--;
        return t;
	}
	
	public BinaryNodeWithRank findMin(BinaryNodeWithRank t){
		while(t.left != null){
			t = t.left;
		}
		return t;
	}
	public void inorder(BinaryNodeWithRank t){
		if(t != null){
			inorder(t.left);
			System.out.print(t.v +" ");
			inorder(t.right);
		}
	}
	
	private BinaryNodeWithRank rotateWithLeftChild(BinaryNodeWithRank k2){
		BinaryNodeWithRank k1 = k2.left;
		k2.left = k1.right;
		k1.right = k2;
		k2.height = Math.max(height(k2.left), height(k2.right)) + 1;
		k1.height = Math.max(height(k1.left), k2.height) + 1;
		if(k2.left == null){
			k2.rank = 1;
		}
		else{
			k2.rank = k2.left.rank + 1;
		}
		return k1;
	}
	private BinaryNodeWithRank rotateWithRightChild(BinaryNodeWithRank k2){
		BinaryNodeWithRank k1 = k2.right;
		k2.right = k1.left;
		k1.left  = k2;
		k2.height = Math.max(height(k2.left), height(k2.right)) + 1;
		k1.height = Math.max(height(k1.right), k2.height) + 1;
		k1.rank += k2.rank;
		return k1;
	}
	private BinaryNodeWithRank doubleWithLeftChild(BinaryNodeWithRank k3){
		k3.left = rotateWithRightChild(k3.left);
		
		return rotateWithLeftChild(k3);
	}
	private BinaryNodeWithRank doubleWithRightChild(BinaryNodeWithRank k3){
		k3.right = rotateWithLeftChild(k3.right);
		
		return rotateWithRightChild(k3);
	}
}

