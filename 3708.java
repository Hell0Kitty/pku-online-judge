import java.util.*;
import java.math.*;
public class Main {
    static BigInteger x,y;
    static BigInteger[] a=new BigInteger[1000];
    static BigInteger[] m=new BigInteger[1000];
    static void egcd(BigInteger a,BigInteger b){
        if(b.equals(BigInteger.ZERO)){
            x=BigInteger.ONE;
            y=BigInteger.ZERO;
            return ;
        }
        egcd(b,a.mod(b));
        BigInteger temp=y;
        y=x.subtract((a.divide(b)).multiply(y));
        x=temp;
    }
    static BigInteger solve(int n){
        BigInteger M=BigInteger.ONE;
        BigInteger ans=BigInteger.ZERO;
        BigInteger mk=null;
        for(int i=0;i< n;i++)
            M=M.multiply(m[i]);
        for(int i=0;i< n;i++){
            mk=M.divide(m[i]);
            egcd(mk,m[i]);
            ans=ans.add(x.multiply(mk).multiply(a[i])).mod(M);
        }
        if(ans.compareTo(BigInteger.ZERO)<0)
            ans=ans.add(M);
        return ans;
    }
    static int[] a1=new int[1000];
    static int[] a2=new int[1000];
    static int[] m1=new int[1000];
    static int[] k1=new int[1000];
    static int[] w1=new int[1000];
    static int[] w2=new int[1000];
    static int[] w3=new int[101];
    static int[] w4=new int[101];
    static int[] w5=new int[101];
    static String mm;
    static String kk;
    static int prime(int x,int y){
        for(int i=2;x>1;i=i*i<=x?i+1:x)
            if(x%i==0){
                int k=0,p=1;
                while(x%i==0){
                    x/=i;
                    k++;
                    p=p*i;
                }
                //System.out.println("w5[i]="+w5[i]+",i="+i+",p="+p+",y="+y);
                if(w5[i]!=0&&w3[w5[i]]%p!=y%p&&w3[w5[i]]%w5[i]!=y%w5[i])
                    return 0;
                p=i;
                for(int j=1;j< k;j++){
                    w4[p]=0;
                    p*=i;
                }
                w3[p]=y%p;
                if(w5[i]< p)
                    w5[i]=p;
            }
        return 1;
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        while(true){
            int d=Integer.parseInt(in.next());
            if(d==-1)
                break;
            for(int i=1;i< d;i++)
                a1[i]=Integer.parseInt(in.next());
            for(int i=0;i< d;i++)
                a2[i]=Integer.parseInt(in.next());
            mm=in.next();
            kk=in.next();
            int l1=0,l2=0;
            BigInteger m2=new BigInteger(mm);
            while(!m2.equals(BigInteger.ZERO)){
                m1[l1++]=m2.mod(BigInteger.valueOf(d)).intValue();
                m2=m2.divide(BigInteger.valueOf(d));
            }
            BigInteger k2=new BigInteger(kk);
            while(!k2.equals(BigInteger.ZERO)){
                k1[l2++]=k2.mod(BigInteger.valueOf(d)).intValue();
                k2=k2.divide(BigInteger.valueOf(d));
            }
            if(l1!=l2){
                System.out.println("NO");
                continue ;
            }
            int q=a1[m1[l1-1]];
            int l=1;
            w1[0]=-1;
            boolean mark=true;
            for(int i=1;i<=d;i++){
                if(q==k1[l1-1]){
                    w1[0]=i;
                }
                if(q==m1[l1-1]){
                    w2[0]=l;
                    break;
                }
                q=a1[q];
                l++;
            }
            if(w1[0]==-1){
                System.out.println("NO");
                mark=false;
                continue ;
            }
            for(int i=1;i< l1;i++){
                q=a2[m1[l1-1-i]];
                l=1;
                w1[i]=-1;
                for(int j=0;j<=d;j++){
                    if(q==k1[l1-i-1]){
                        w1[i]=j+1;
                    }
                    if(q==m1[l1-1-i]){
                        w2[i]=l;
                        break;
                    }
                    l++;
                    q=a2[q];
                }
                if(w1[i]==-1){
                    System.out.println("NO");
                    mark=false;
                    break;
                }
            }
            if(!mark)
                continue ;
            int num=0;
            for(int i=0;i<=d;i++){
                w3[i]=-1;
                w4[i]=1;
                w5[i]=0;
            }
            int tt=0;
            for(int i=0;i< l1;i++){
                if((tt=prime(w2[i],w1[i]))==0){
                    mark=false;
                    System.out.println("NO");
                    break;
                }
            }
            if(!mark)
                continue ;
            for(int i=0;i<=d;i++)
                if(w3[i]!=-1&&w4[i]==1){
                    a[num]=BigInteger.valueOf(w3[i]);
                    m[num++]=BigInteger.valueOf(i);
                    //System.out.println("i="+i+",w="+w3[i]);
                }
            if(num==0)
                System.out.println(1);
            else System.out.println(solve(num));
        }
    }

}

