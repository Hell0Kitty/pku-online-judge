import java.util.*;
public class Main {
    public static void main(String[] args){
    int[] p=new int[1001];
    p[1]=3;
    p[2]=5;
Scanner cin=new Scanner(System.in);
int T=cin.nextInt();
for(int a=3;a<=1000;a++){
   p[a]=p[a-1]+2;
for(int i=2;i<=a;i++)
   p[a]+=2*c(a,i);
}
for(int t=1;t<=T;t++){
   int r=cin.nextInt();
   System.out.println(t+" "+r+" "+p[r]);
}
}
public static int c(int a,int b){
   while(a!=0){
    b=b%a;
    if(a>b){
     int temp=a;
     a=b;
     b=temp;
    }
   }
   if(b==1)
    return 1;
   else
    return 0;
}
}

