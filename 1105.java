import java.util.Scanner;
import java.util.Arrays;
public class Main{

 public static void main(String args[]){
  Scanner sc=new Scanner(System.in);
  int n,m,times=1,map[]=new int[7];
  char bits[]=new char[129],s[]=new char[20];
  while(true){
    n=sc.nextInt();
    if(n==0)
    break;
    for(int i=0;i< n;i++){
    s=sc.next().toCharArray();
    map[s[1]-'1']=(char)i;
    }
    bits=sc.next().toCharArray();
    m=sc.nextInt();
    System.out.printf("S-Tree #%d:\n",times++);
    while((m--)!=0){
    char tem[]=new char[20];
    int res=0;
    s=sc.next().toCharArray();;
    for(int i=0;i< n;i++)
      tem[map[i]]=(char)(s[i]-'0');
    for(int i=0;i< n;i++){
      res<<=1;
      if(tem[i]!=0)
        res++;
    }
    System.out.printf("%c",bits[res]);
     }
     System.out.println();
     System.out.println();
   }
  }
}

