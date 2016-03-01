import java.io.*;
import java.util.*;
public class Main {
 static final int N = 1000+10;
 static int n,m;
 static int value[] = new int[N];
 public static void main(String []args) throws Exception{

  int i,t;
  //Scanner cin = new Scanner(new FileInputStream("input.txt"));
  Scanner cin = new Scanner(System.in);

  t = cin.nextInt();
  while(t--!=0){
	n = cin.nextInt();
	m = cin.nextInt();
	for(i=0;i< m;++i)
		value[i] = cin.nextInt();
	System.out.println(solve());
   }
 }

 public static int binary_search(int num[],int key){
  int Min=0,Max=m-1,Mid;
  while(Min+1< Max){
	Mid = (Min+Max)/2;
	if(num[Mid]>key)
		Max = Mid;
	else Min = Mid;
   }
  if(num[Min]==key) return Min;
  return Max;
 }

 public static void make_mapping(){
  int i,j,k;
  int num[] = new int[N];
  int scan[] = new int[N];

  for(i=0;i< m;++i) num[i] = value[i];
  Arrays.sort(num,0,m);
  scan[0] = 1;
  for(i=1;i< m;++i){
	if(num[i]==num[i-1]) scan[i] = scan[i-1];
	else scan[i] = scan[i-1]+1;
  }
  for(i=0;i< m;++i){
	value[i] = scan[binary_search(num,value[i])];
  }
 }

 public static int get_last(int cnt,int who){
  int i=cnt+1;
  for(i=cnt+1;i< m;++i)
   if(value[i]==who)
     return i;
   return i;
  }

  public static int solve(){
   make_mapping();

   int i,j,k,cnt,last,ans=0,top=0;
   int contain[] = new int [N];
   for(i=0;i< ;++i){
	for(j=0;j< top;++j){
		if(contain[j] == value[i]) break;
	}
	if(j>=top){
		ans++;
		if(top< n){
			contain[top++] = value[i];
		}
		else{
		  cnt = 0;last = get_last(i,contain[0]);
		  for(j=1;j< top;++j){
			k = get_last(i,contain[j]);
			if(k>last){
				cnt = j;
				last = k;
			}
		  }
		  contain[cnt] = value[i];
		}
	}
   }
   return ans;
  }

}

