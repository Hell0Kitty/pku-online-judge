import java.io.*;
public class Main {
  public static void main(String[] args) throws Exception{
//System.setIn(new FileInputStream(new File("E:\\in.txt")));
//System.setOut(new PrintStream(new File("E:\\out.txt")));
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  String s;
  Node root=new Node("ROOT",null);
  Node curr=root;
  Node t,n;
  int count=1;
  tag:
  while(true){
    switch((s=br.readLine()).charAt(0)){
       case 'f':
         t=new Node(s,curr);
	  if(curr.fleftmost==null)
	  	curr.fleftmost=t;
	  else{
	     if(t.compareTo(curr.fleftmost)< 0){
	     	t.frightsib=curr.fleftmost;
	     	curr.fleftmost=t;
	     }else{
		n=curr.fleftmost;
		while(n.frightsib!=null&&t.compareTo(n.frightsib)>0){
		   n=n.frightsib;
		}
		t.frightsib=n.frightsib;
		n.frightsib=t;
	     }
	 }
	 break;
      case 'd':
	  t=new Node(s,curr);
	  if(curr.dleftmost==null)
	    curr.dleftmost=curr.drightmost=t;
	  else{
	    curr.drightmost.drightsib=t;
	    curr.drightmost=t;
	   }
	   curr=curr.drightmost;
	   break;
	case ']':
	   curr=curr.parent;
	   break;
	case '*':
	    print(root,count++);
	    curr=root=new Node("ROOT",null);
	    break;
	case '#':
	    break tag;
     }
   }
  }

 static void print(Node root,int count) {
   System.out.println("DATA SET "+count+":");
   print0(root,0);
   System.out.println();
 }

static void print0(Node root, int d) {
   for(int i=0;i< d;i++){
	System.out.print("|     ");
    }
    System.out.println(root.content);
	Node t=root.dleftmost;
	while(t!=null){
		print0(t,d+1);
		t=t.drightsib;
	}
	t=root.fleftmost;
	while(t!=null){
		print0(t,d);
		t=t.frightsib;
	}
  }
}
class Node implements Comparable< Node>{
	String content;
	Node parent;
	Node fleftmost;
	Node frightsib;
	Node dleftmost;
	Node drightsib;
	Node drightmost;
	Node(String c,Node n){
		content=c;
		parent=n;
	}
	@Override
	public int compareTo(Node o) {
		return this.content.compareTo(o.content);
	}
}

