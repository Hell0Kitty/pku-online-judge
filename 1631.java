import java.util.*;
public class Main {
  static int a[]=new int[40000];
  static int b[]=new int[40000];
        
static int binary(int i,int k){
if(a[i]<b[1])return 1;
int h=1,j=k;
while(h!=j-1){
   k=(h+j)/2;
   if(b[k]<=a[i])h=k;
   else
    j=k;
}
return j;
}
    public static void main(String[] args) {
          Scanner in=new Scanner(System.in);
        
int n,p,k,i;
n=in.nextInt();
while((n--)!=0){
  p=in.nextInt();
   for(i=0;i<p;i++)
    a[i]=in.nextInt();
   b[1]=a[0];
   k=1;
   for(i=1;i<p;i++){
    if(a[i]>=b[k])b[++k]=a[i];
    else b[binary(i,k)]=a[i];
   }
   System.out.println(k);
  }
 }
}