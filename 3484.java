//* @author:
import java.util.*;
import java.math.*;
import java.io.FileReader;
class node{
    int x,y,z;
    node(String s) {
        int t=0,cnt=0;
        for (int i=0;i<=s.length();i++) {
            if (i!=s.length()&&s.charAt(i)>='0'&&s.charAt(i)<='9') {
                t=t*10+s.charAt(i)-'0';
            }
            else {
                if (cnt==0) x=t;
                else if (cnt==1) y=t;
                else if (cnt==2) z=t;
                cnt++;
                t=0;
            }
        }
    }
}
public class Main {
    static void doit(Vector a) {
        int n=a.size();
        node tt=null;
        long beg=2147483647,end=0,ans=0;
        long total=0;
        for (int i=0;i< n;i++) {
            tt=(node)a.get(i);
            total+=(tt.y-tt.x)/tt.z+1;
            if (beg>tt.x) beg=tt.x;
            if (end< tt.y) end=tt.y;
        }
        if (total%2==0) {
            System.out.println("no corruption");
            return;
        }
        while (beg<=end) {
            long mid=(beg+end)/2;
            total=0;
            for (int i=0;i< n;i++) {
                tt=(node)a.get(i);
                long left,right,x=tt.x,y=tt.y,z=tt.z;
                if (x>beg) left=x;
                else {
                    if (beg%z==x%z) left=beg;
                    else if (beg%z>x%z) left=beg-beg%z+x%z+z;
                    else left=beg-beg%z+x%z;
                }
                if (y< mid) right=y;
                else right=mid;
                if (right>=left) total+=(right-left)/z+1;
            }
            if (total%2==1) {
                end=mid;
                if (beg==end) {
                    ans=beg;
                    break;
                }
            }
            else {
                beg=mid+1;
            }
        }
        System.out.print(ans);
        int ans2=0;
        for (int i=0;i< n;i++) {
            tt=(node)a.get(i);
            if (ans>=tt.x&&ans<=tt.y&&ans%tt.z==tt.x%tt.z) ans2++;
        }
        System.out.print(' ');
        System.out.println(ans2);
    }
    public static void main(String[] args) throws Exception{
        Scanner in=new Scanner(System.in);
        while (true) {
            Vector a=new Vector(0);
            while (true) {
                String s;
                try {s=in.nextLine();}
                catch (Exception e) {
                    if (a.size()!=0) doit(a);
                    return;
                }
                if (s.length()==0) {
                    if (a.size()!=0) {
                        doit(a);
                        break;
                    }
                }
                else a.add(new node(s));
            }
        }
    }
}

