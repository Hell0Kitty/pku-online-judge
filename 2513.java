import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
 int sum = 0;
 int time[] = new int[500000];
 int parent[] = new int[500000];
 int rank[] = new int[500000];
 trieT root;

 void ini() {
  root = new trieT();
  for (int i = 0; i < 500000; i++)
	parent[i] = i;
 }

public static void main(String[] args) throws IOException {
  BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
  Main p = new Main();
  p.ini();
  int a = 0;
  int b = 0;
  int qtime = 0;

  String tmp = re.readLine();
  while (tmp!=null) {

	a = p.insert(tmp.split(" ")[0].toCharArray(), p.root);
	b = p.insert(tmp.split(" ")[1].toCharArray(), p.root);
	p.time[a]++;
	p.time[b]++;
	tmp = re.readLine();
	if (a != b)
		p.union(a, b);
    }

  for (int i = 0; i < p.sum; i++)
	if (p.time[i] % 2 != 0)
		qtime++;
  int k = p.find(0);
  for (int i = 1; i < p.sum; i++)
	if (k != p.find(i)) {
         System.out.println("Impossible");
	  return;
	}
  if (qtime <= 2)
	System.out.println("Possible");
  else
	System.out.println("Impossible");

 }


 int find(int x) {
   if (parent[x] != x) {
	parent[x] = find(parent[x]);
   }
  return parent[x];
 }

 void union(int a, int b) {
   int fa = find(a);
   int fb = find(b);
   if (fa == fb)
	return;
   if (rank[fa] > rank[fb])
	parent[fb] = fa;
   else if (rank[fa] < rank[fb])
	parent[fa] = fb;
   else {
	parent[fa] = fb;
	rank[fb]++;
   }
  }

  int insert(char[] key, trieT trie) {
   for (int i = 0; i < key.length; i++) {
	int index = key[i] - 'a';
	if (trie.child[index] == null) {
         trie.child[index] = new trieT();
	}
	trie = trie.child[index];
    }
    if (trie.count == -1)
	trie.count = sum++;
    return trie.count;
  }
}
class trieT {
	int count = -1;
	trieT child[] = new trieT[26];

	public trieT() {
         for (int i = 0; i < 26; i++)
		child[i] = null;

	}

}

