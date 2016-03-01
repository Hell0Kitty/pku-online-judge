import java.util.*;
import java.io.*;

public class Main {
 public static void main(String[] args) throws Exception{
   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
   int n = Integer.parseInt(br.readLine());
   IPAddress[] ips = new IPAddress[n];
   for(int i = 0; i < n; i++){
	ips[i] = new IPAddress();
	ips[i].read(br.readLine());
   }
  int minlen = -1;
  for(int i = 1; i < n; i++){
    for(int j = 31; j >= 0; j--){
	if(ips[i].bitSet.get(j) != ips[0].bitSet.get(j)){
	   if(j > minlen){
		minlen = j;
	   }
	   break;
	}
    }
  }
  for(int i = minlen; i >= 0; i--){
	ips[0].bitSet.set(i, false);
  }
  System.out.println(ips[0].write());
  IPAddress mask = new IPAddress();
  for(int i = 31; i > minlen; i--){
	mask.bitSet.set(i, true);
   }
  System.out.println(mask.write());
 }
}

class IPAddress{
 BitSet bitSet = new BitSet(32);
 IPAddress(){
 }

 public void read(String s){
   StringTokenizer st = new StringTokenizer(s, ".");
   LinkedList< Integer> stk = new LinkedList< Integer>();

   int k = 31;
   while(st.hasMoreTokens()){
    int t = Integer.parseInt(st.nextToken());
    int c = 0;
    while(t > 0){
	stk.addFirst((t%2));
	t /= 2;
	c++;
     }
     while(c < 8){
	stk.addFirst(0);
	c++;
     }
     while(!stk.isEmpty()){
	int v = stk.removeFirst();
	//q.addLast(v);
	bitSet.set(k, v == 1);
	k--;
      }
     }
   }

   public String write(){
     //System.out.println(bitSet);
     String strOut = "";
     for(int i = 31; i >= 0; i -= 8){
	int sum = 0;
	for(int j = i; j > i-8; j--){
		sum = sum * 2 + (bitSet.get(j) ? 1 : 0);
	}
	strOut += sum;
	if(i > 8){
		strOut += ".";
	}
     }
     return strOut;
   }
}

