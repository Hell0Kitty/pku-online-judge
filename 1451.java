import java.util.Comparator;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Scanner;

class node {
char ch;// 字符
int val;// 权值
int lv;// 层次
node father;// 父结点
HashMap<Character, node> next;

node(char ch, int val, int lv, node father) {
this.ch = ch;
this.val = val;
this.lv = lv;
this.father = father;
next = new HashMap<Character, node>();
}

node() {
next = new HashMap<Character, node>();
lv = 0;
}
}

class trie {
private static char t9[][] = { {}, {}, { 'a', 'b', 'c' }, { 'd', 'e', 'f' }, { 'g', 'h', 

'i' }, { 'j', 'k', 'l' }, { 'm', 'n', 'o' }, { 'p', 'q', 'r', 's' }, { 't', 'u', 'v' }, { 

'w', 'x', 'y', 'z' } };

node root = null;

public void add(String str, int val) {
node curr = root;
for (int i = 0; i < str.length(); i++) {
char ch = str.charAt(i);
// 没有结点就建立结点
node next;
if ((next = curr.next.get(ch)) == null) {
curr.next.put(ch, new node(ch, val, curr.lv + 1, curr));
curr = curr.next.get(ch);
} else {
curr = next;
curr.val += val;
}
}
}

public void find(String num_str) {
int length;
int num[];
// 找出1的位置，确定结束点
int one_pos = num_str.indexOf('1');
if (one_pos < 0) {
length = num_str.length();
} else {
length = one_pos;
}
// 字符转换为数字
num = new int[length];
for (int i = 0; i < length; i++) {
num[i] = num_str.charAt(i) - '0';
}
// 建立优先队列
PriorityQueue<node> pq = new PriorityQueue<node>(26, new Comparator<node>() {
// 优先规则：层次从小到大，权值从大到小，字母表顺序
public int compare(node a, node b) {
if (a.lv == b.lv) {
if (a.val == b.val) {
return a.ch - b.ch;
} else {
return b.val - a.val;
}
} else {
return a.lv - b.lv;
}
}
});
// 把根加入队列
pq.add(root);
// 对trie树进行BFS遍历
int lv = 0;
while (pq.size() > 0) {
// 把所有可能接下来的结点列出，加入队列
node curr = pq.poll();
// 反推结果
if (curr.lv > lv) {
char res[] = new char[curr.lv];
node c = curr;
while (c != root) {
res[c.lv - 1] = c.ch;
c = c.father;
}
System.out.println(res);
lv++;
}
if (lv < num.length) {
int dig = num[curr.lv];
for (int i = 0; i < t9[dig].length; i++) {
node next;
if ((next = curr.next.get(t9[dig][i])) != null) {
pq.add(next);
}
}
}
}
// 填空
for (int i = lv; i < length; i++) {
System.out.println("MANUALLY");
}
}

trie() {
root = new node();
}
}

public class Main {
public static void main(String[] args) throws Exception {
Scanner cin = new Scanner(System.in);
int cas = cin.nextInt();
for (int th = 1; th <= cas; th++) {
System.out.printf("Scenario #%d:\n", th);
// 对每一个测试用例建立一棵trie树
trie tr = new trie();
int w = cin.nextInt();
while (w-- > 0) {
tr.add(cin.next(), cin.nextInt());
}
int m = cin.nextInt();
while (m-- > 0) {
String src = cin.next();
tr.find(src);
System.out.println();
}
System.out.println();
}
}
}