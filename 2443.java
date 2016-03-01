//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;
class Set{
	void init(){
		for(int i=0;i< 35;++i) state[i] = 0;
	}
	void get_int(int cnt){
		int k = cnt/30;
		int posi = cnt%30;
		state[k]|=dir[posi];
	}
	int dir[] = {1,1<<1,1<<2,1<<3,1<<4,1<<5,1<<6,1<<7,1<<8,1<<9,1<<10,1<<11,1<<12,1<<13,1<<14,
1<<15,1<<16,1<<17,1<<18,1<<19,1<<20,1<<21,1<<22,1<<23,1<<24,1<<25,1<<26,1<<27,
1<<28,1<<29,1<<30,1<<31};
	int state[] = new int[35];
}

public class Main {

  static final int N = 10000+2;
  public static int get_num(StreamTokenizer in) throws Exception{

   in.nextToken();
   return (int) in.nval;
  }

  public static void main(String []args) throws Exception{

   int i,j,n,m,u,v;
   Set set[] = new Set[N];
   for(i=0;i< N;++i){
	set[i] = new Set();
	set[i].init();
   }
   //Scanner cin = new Scanner(new FileInputStream("input.txt"));
   //Scanner cin = new Scanner(System.in);
   StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

   n = get_num(in);
   //n = cin.nextInt();
   for(i=1;i<=n;++i){
	//m = cin.nextInt();
	m = get_num(in);
	for(j=0;j< m;++j){
		//set[cin.nextInt()].get_int(i);
		set[get_num(in)].get_int(i);
	}
    }
	//m = cin.nextInt();
	m = get_num(in);
	for(i=1;i<=m;++i){
		//u = cin.nextInt();
		//v = cin.nextInt();
		u = get_num(in);
		v = get_num(in);
		for(j=0;j< 35;++j){
			if((set[u].state[j]&set[v].state[j])>0){
				System.out.println("Yes");
				break;
			}
		}
		if(j>=35) System.out.println("No");
	}

   }

}

