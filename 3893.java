import java.util.*;
public class Main{
  public static void main(String args[]){
   Scanner in=new Scanner(System.in);
   char s[]=new char[10001];
   int v[]=new int[10001];
   v[1]=1;v[2]=2;v[3]=3;
   int a,b,len;
   while(in.hasNext()){
    a=in.nextInt();
    s=in.next().toCharArray();
    b=in.nextInt();
    b=v[b];
    len=s.length;
    for(int i=len-1; i>=0; i--){
     if(s[i]=='< ')
      v[a]=b;
     if(s[i]=='=')
      System.out.println(v[a]==b?"=":"#");
     if(s[i]=='k')
      System.out.printf("%d\n",b);
     if(s[i]=='b')
       b-=2;
     if(s[i]=='f'){
       if((b&1)!=0)
         b++;
       else
         b+=3;
     }
     }
    }
  }
}

