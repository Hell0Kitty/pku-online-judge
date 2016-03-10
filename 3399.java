import java.util.*;
import java.math.*;
public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        int k=in.nextInt();
        int k1=0,k2=0,a=0,kk=0;
        int[] a1=new int[101],a2=new int[101],ans=new int[101];
        for(int i=0;i< n;++i){
            a=in.nextInt();
            if(a>=0)
                a1[k1++]=a;
            else a2[k2++]=a;
        }
        Arrays.sort(a1,0,k1);
        Arrays.sort(a2,0,k2);
        if(k%2==1){
            k--;
            if(k1>0)
                ans[kk++]=a1[--k1];
            else{
                for(int i=k2-1;i>k2-1-k;--i)
                    System.out.print(a2[i]+" ");
                System.out.println(a2[k2-1-k]);
                return ;
            }
        }
        int j2=0;
        for(int i=0;i< k/2;++i){
            int t1=-1000000000;
            int t2=-1000000000;
            if(k1==1&&k2-j2==1){
                ans[kk++]=a1[--k1];
                ans[kk++]=a2[j2++];
            }else{
                if(k1>1)
                    t1=a1[k1-1]*a1[k1-2];
                if(k2-j2>1)
                    t2=a2[j2]*a2[j2+1];
                if(t1>t2){
                    ans[kk++]=a1[--k1];
                    ans[kk++]=a1[--k1];
                }else{
                    ans[kk++]=a2[j2++];
                    ans[kk++]=a2[j2++];
                }
            }
        }
        Arrays.sort(ans,0,kk);
        for(int i=kk-1;i>0;--i)
            System.out.print(ans[i]+" ");
        System.out.println(ans[0]);
    }

}

