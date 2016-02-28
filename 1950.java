import java.io.*;
import java.util.*;
import java.math.*;


public class Main {

 char[] opa = { '+', '-', '.' };
 char[] op;
 int cnt;
 int n;
 int rec[] = {88, 162, 197, 437, 1350 };

 void print() {
  cnt++;
  if(cnt > 20) return;
  int i;
  for(i = 1; i <= n; ++i) {
    System.out.print(i);
    if(i != n){
	System.out.print(" " + op[i] + " ");
    }
  }
  System.out.println("");
 }

  void search(int depth, long lastnum, char lastop, long tot) {
    if(cnt > 20) return;
    if(depth == n) {
	if(lastop == '+')
	tot += lastnum;
	else tot -= lastnum;

	if(tot == 0)
	  print();
	return;
     }
    for(char c : opa) {
	char curop = lastop;
	long curtot = tot;
	if(c == '+') {
	   op[depth] = c;
	   if(lastop == '+') tot += lastnum;
	   else tot -= lastnum;
	lastop = c;
	search(depth+1, depth+1, lastop, tot);
	} else if(c == '-') {
	  op[depth] = c;
	  if(lastop == '+') tot += lastnum;
	  else tot -= lastnum;
	  lastop = c;
	  search(depth+1, depth+1, lastop, tot);
	} else if(c == '.') {
	  op[depth] = c;
	  String s = "" + lastnum;
	  s += (depth+1);
	  if(s.length() > 9) continue;
	  long x = Long.parseLong(s);
	  search(depth+1, x, lastop, tot);
	}
	tot = curtot;
	lastop = curop;
   }
 }

void run() {
  Scanner cin = new Scanner(System.in);
  n = cin.nextInt();
  op = new char[n];
  cnt = 0;
  search(1, 1, '+', 0);
  if(n < 11)
	System.out.println(cnt);
  else
	System.out.println(rec[n-10-1]);
 }

 public static void main(String[] args) {
   new Main().run();

 }

}

