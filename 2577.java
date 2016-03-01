//* @author  mekarlos@gmail.com
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main {
 public static void main(String[] args) throws IOException {
  BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
  int[] ram=new int[1000];
  int[] reg=new int[10];
  int pos=0;
  int num=1;
  while(stdin.ready()){
   ram[pos++]=new Integer(stdin.readLine());
  }
  pos=0;
  while(ram[pos]!=100){
   switch(ram[pos]/100){
    case 0:
	if(reg[ram[pos]%10]==0){
		pos++;
	}
	else{
		pos=reg[(ram[pos]%100)/10];
	}
	break;
    case 2:
	reg[(ram[pos]%100)/10]=ram[pos]%10;
	reg[(ram[pos]%100)/10]%=1000;
	pos++;
	break;
    case 3:
	reg[(ram[pos]%100)/10]+=(ram[pos]%10);
	reg[(ram[pos]%100)/10]%=1000;
	pos++;
	break;
    case 4:
	reg[(ram[pos]%100)/10]*=(ram[pos]%10);
	reg[(ram[pos]%100)/10]%=1000;
	pos++;
	break;
    case 5:
	reg[(ram[pos]%100)/10]=reg[ram[pos]%10];
	reg[(ram[pos]%100)/10]%=1000;
	pos++;
	break;
    case 6:
	reg[(ram[pos]%100)/10]+=reg[ram[pos]%10];
	reg[(ram[pos]%100)/10]%=1000;
	pos++;
	break;
    case 7:
	reg[(ram[pos]%100)/10]*=reg[ram[pos]%10];
	reg[(ram[pos]%100)/10]%=1000;
	pos++;
	break;
    case 8:
	reg[(ram[pos]%100)/10]=ram[reg[ram[pos]%10]];
	pos++;
	break;
    case 9:
	ram[reg[ram[pos]%10]]=reg[(ram[pos]%100)/10];
	pos++;
	break;
   }
  num++;
 }
  System.out.println(num);
 }
}

