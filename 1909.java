//* @author: ccQ.SuperSupper
import java.util.*;
import java.io.*;
class node{
	int init_have;
	int sum_have;
	int nodes;
	Vector son = new Vector();
}
public class Main {

 static int N = 10000+100;
 public static void main(String []args) throws Exception{

  int n,i,j,ans,cnt,sons,root;
  node Tree[] = new node[N];
  for(i=0;i< N;++i) Tree[i] = new node();

   //Scanner cin = new Scanner(new FileInputStream("input.txt"));//System.in);
   Scanner cin = new Scanner(System.in);

   while(cin.hasNext()){
	n = cin.nextInt();
	if(n==0) break;
	for(i=0;i<=n;++i){
		Tree[i].sum_have = -1;
		Tree[i].son.clear();
		Tree[i].nodes = 0;
	}
	for(i=0;i< n;++i){
		cnt = cin.nextInt();
		Tree[cnt].init_have = cin.nextInt();
		sons = cin.nextInt();
		for(j=0;j< sons;++j){
			ans = cin.nextInt();
			Tree[cnt].son.add(ans);
			Tree[ans].sum_have = -2;
		}
	}
	root = 1;
	for(i=1;i<=n;++i) if(Tree[i].sum_have==-1)
		root = i;
	System.out.println(dfs(Tree,root));
   }
 }

public static int dfs(node Tree[],int root){

  int i,j,k,ans=0;
  Tree[root].sum_have = Tree[root].init_have;
  Tree[root].nodes = 1;
  for(i=0;i< Tree[root].son.size();++i){
	k = (Integer)Tree[root].son.get(i);
	if(Tree[k].sum_have< 0){
		ans+=dfs(Tree,k);
		Tree[root].sum_have+=Tree[k].sum_have;
		Tree[root].nodes+=Tree[k].nodes;
		ans+=abs(Tree[k].sum_have-Tree[k].nodes);
	}
   }
   return ans;
 }
	public static int abs(int a){
		return a<0?-a:a;
	}
}

