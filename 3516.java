//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;
class Queue{
    int pre;
    int cnt_posi;
    int cnt_num;
    int cnt_sum;
    void set(int pre_t,int cnt_num_t,int cnt_sum_t,int cnt_posi_t){
        this.pre = pre_t;
        this.cnt_num = cnt_num_t;
        this.cnt_sum = cnt_sum_t;
        this.cnt_posi = cnt_posi_t;
    }
}
class node{
    int who;
    int value;
}
public class Main {
    static final int N = 4000000+10,P=256;

    static int n,p;
    static Queue myque[] = new Queue[N];

    static HashMap map[] = new HashMap[P];
    static int ans[] = new int[P],num[][] = new int[P][6];

    static void start_que(){
        int i,j;
        for(i=0;i< N;++i)
            myque[i] = new Queue();
        for(i=0;i< P;++i)
            map[i] = new HashMap();
    }

public static void main(String []args) throws Exception{

  int i,j,cs=1;
  String str = new String();
  Scanner cin = new Scanner(System.in);
  //Scanner cin = new Scanner(new FileInputStream("input.txt"));
  start_que();
  while(cin.hasNext()){
    str = cin.next();
    if(str.equalsIgnoreCase("0=0"))
        break;
    for(i=0;i< str.length();++i){
        if(str.charAt(i)=='=')
            break;
    }
    n = i;
    p = Integer.valueOf(str.substring(i+1, str.length()));

    System.out.print(cs+". ");
    ++cs;
    solve(str,cs);
   }
 }

 public static void init_num(String str){
  int i,j;
  for(i=0;i< n;++i){
    num[i][0] = 0;
    for(j=1;j< 6 && i+j<=n;++j){
        num[i][j] = num[i][j-1]*10+str.charAt(i+j-1)-'0';
        //System.out.println(num[i][j]);
    }
   }
   for(i=0;i<=n;++i)
    map[i].clear();

   }


  static void get_ans(int cnt){
    String str="";
    int i,j,top=0;
    while(cnt>0){
        ans[top++] = myque[cnt].cnt_num;
        cnt = myque[cnt].pre;
    }
    str += String.valueOf(ans[top-1]);
    for(i=top-2;i>=0;--i){
        str+="+";
        str+=String.valueOf(ans[i]);
    }
    str+="="+String.valueOf(p);
    System.out.println(str);
  }

  public static void solve(String str,int cs){
   init_num(str);

   int i,j,k,left=0,right=0;

   myque[right].set(-1, 0, 0, 0);
   ++right;

   while(left< right){
    //System.out.println(left+" "+right);
    for(i=1;i< 6 && num[myque[left].cnt_posi][1]>0 && myque[left].cnt_posi+i<=n;++i){
    if(num[myque[left].cnt_posi][i]+myque[left].cnt_sum<=p){

      myque[right].set(left, num[myque[left].cnt_posi][i],
           num[myque[left].cnt_posi][i]+myque[left].cnt_sum, myque[left].cnt_posi+i);
      if(myque[right].cnt_posi==n && myque[right].cnt_sum==p){
        get_ans(right);
        return ;
        }
        if(!has_in_hash(myque[right].cnt_posi,myque[right].cnt_sum,cs))continue;
            ++right;
        }

    }
    ++left;
    }
    System.out.println("IMPOSSIBLE");
  }

  public static boolean has_in_hash(int posi,int sum,int cs){

        if(map[posi].containsKey(sum))
            return false;
        map[posi].put(sum, 1);
        return true;
    }

}

