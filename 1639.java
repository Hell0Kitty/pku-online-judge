import java.util.*;
import java.io.*;
import java.util.concurrent.*;

public class Main {
	private static class UFSets {
		UFSets(int l) {
			s = new int[l];
			for(int i=0; i!=l; ++i)
				s[i] = i;
		}
		void union(int x, int y) {
			s[find(x)] = s[find(y)];
		}
		int find(int x) {
			if(x>=s.length) while(true) ;
			if(s[x]!=x) return s[x] = find(s[x]);
			return x;
		}
		private int[] s;
	}
	private static class Node extends LinkedBlockingDeque<Edge>{
		private static final long serialVersionUID = 1L;
		void updatePath(Integer path) {
			if(this.path == null || this.path.compareTo(path) > 0) 
				this.path = path;
		}
		static Node getNearestNodeFrom(Node e) {
			++cnt;
			return e.getNearesNode();
		}
		private Node getNearesNode() {
			if(lab==cnt) return this;
			lab = cnt;
			Node ans = this;
			for(Edge e: this) {
				Node another = e.target(this).getNearesNode();
				if(another.path == null) continue;
				if(ans.path == null || ans.path.compareTo(another.path)>0) ans = another;
			}
			return ans;
		}
		void update() {
			lab = ++cnt;
			cut = null;
			ans += path;
			for(Edge e: this)
				e.target(this).update(e);
		}
		private void update(Edge edge) {
			if(lab==cnt) return;
			cut = edge;
			lab = cnt;
			for(Edge e: this)
			{
				Node v = e.target(this);
				if(e.compareTo(edge)>0) v.update(e);
				else v.update(edge);
			}
		}
		static int cnt = 0;
		int lab = 0;
		Integer path = null;
		Edge cut;
	}
	private static class Edge implements Comparable<Edge>{
		public int compareTo(Edge e) {
			return this.l-e.l;
		}
		Edge(int cx, int cy, Node x, Node y, int l) {
			this.cx = cx;
			this.cy = cy;
			this.x = x;
			this.y = y;
			this.l = l;
		}
		void activate() {
			x.addFirst(this);
			ix = x.iterator();
			ix.next();
			y.addFirst(this);
			iy = y.iterator();
			iy.next();
			ans += l;
		}
		void disable() {
			ix.remove();
			iy.remove();
			ans -= l;
		}
		Node target(Node v) {
			if(x==v) return y;
			return x;
		}
		final Node x, y;
		Iterator<Edge> ix, iy;
		final int cx, cy, l;
	}
	private static final Scanner in = new Scanner(System.in);
	private static final Formatter out = new Formatter(System.out);
	private static final int m = in.nextInt();
	private static List<Node> nodes = new ArrayList<Node>();
	private static List<Edge> edges = new ArrayList<Edge>();
	private static int ans = 0;
	static Map<String, Integer> hash = new HashMap<String, Integer>();
	static {
		nodes.add(new Node());
		hash.put("Park", 0);
	}
	static int getHash(String s) {
		if(!hash.containsKey(s)) {
			hash.put(s, hash.size());
			nodes.add(new Node());
		}
		return hash.get(s);
	}
	public static void main(String[] args) {
		for(int i=0; i!=m; ++i) {
			int x = getHash(in.next());
			int y = getHash(in.next());
			int l = in.nextInt();
			if(y==0) {
				if(x==0) continue;
				y = x;
				x = 0;
			}
			if(x==0) nodes.get(y).updatePath(l);
			else edges.add(new Edge(x, y, nodes.get(x), nodes.get(y), l));
		}
		Collections.sort(edges);
		UFSets s = new UFSets(nodes.size());
		for(Edge e: edges) {
			if(s.find(e.cx)==s.find(e.cy)) continue;
			e.activate();
			s.union(e.cx, e.cy);
		}
		int degree = in.nextInt();
		for(int i=1; i!=nodes.size(); ++i) {
			if(s.find(i)!=i) continue;
			Node v = Node.getNearestNodeFrom(nodes.get(i));
			v.update();
			--degree;
		}
		while(degree-->0) {
			Node v = null;
			for(Node cand: nodes) {
				if(cand.path == null) continue;
				if(cand.cut == null) continue;
				if(v == null || cand.path - cand.cut.l < v.path - v.cut.l) v = cand;
			}
			if(v==null || v.path - v.cut.l >= 0) break;
			v.cut.disable();
			v.update();
		}
		out.format("Total miles driven: %d\n", ans);
	}
}
