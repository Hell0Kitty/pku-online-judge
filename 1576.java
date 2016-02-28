import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
 public static void main(String[] args) throws Exception{
   BufferedReader br = new BufferedReader(new
               InputStreamReader(System.in));
   String s,board;
   String[] ss;
   int n;
   int[] p;
   boolean flag=false;
   while((s=br.readLine())!=null&&!s.startsWith("0")){
	ss=s.split(" ",3);
	p=new int[parseInt(ss[0])];
	for(int i=0;i< p.length;i++)
         p[i]=-1;
	n=parseInt(ss[2]);
	board=br.readLine();
	for(int i=0;i< n;i++){
	  s=br.readLine();
	  if(flag)continue;
	  if(win(p,board,s,i)){
	    flag=true;
	    System.out.println("Player "+(i%p.length+1)+" won after "+(i+1)+" cards.");
	  }
	}
	if(flag){
	  flag=false;
	}else{
	  System.out.println("No player won after "+n+" cards.");
       }
    }
    br.close();
   }


 static int parseInt(String s){
   int t = 0;
   for(char ch: s.toCharArray()){
      t *= 10;
      t += ch-'0';
   }
   return t;
 }

 static boolean win(int[] p,String board,String instruction,int n){

   int pos=n%p.length;
   char target=instruction.charAt(0);
   try {
	for(int i=0;i< instruction.length();i++){
	 do{
           p[pos]++;
	  }while(board.charAt(p[pos])!=target);
      }
   }catch(StringIndexOutOfBoundsException e) {
	return true;
   }
   return p[pos]==board.length()-1;
  }
}

