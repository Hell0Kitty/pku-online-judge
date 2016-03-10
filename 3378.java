mport java.util.*;
import java.math.*;

class Binary
{
    int n,i;
    long ret;
    long a[],c[];
    void init(int x)
    {
        n = x;
        a = new long [x+10];
        c = new long [x+10];
        for(i=0;i< x+10;++i)
        {
            a[i]=c[i]=0;
        }
    }
    void update(int x,long v)
    {
        a[x]+=v;
        for(i=x;i<=n;i+=lowbit(i)) c[i]+=v;
    }
    int lowbit(int x)
    {
        return (x)&(-x);
    }
    long query(int x)
    {
        for(ret=0,i=x;i>0;i^=lowbit(i)) ret+=c[i];
        return ret;
    }
}
public class Main {

/**
 * @param args
 */
public static void main(String[] args) {
    // TODO Auto-generated method stub
    int n,i,j;
    int way[] = new int[50010];
    int num[] = new int[50010];
    int mapping[]= new int[50010];

    BigInteger ans,temp;

    Binary array[] = new Binary[5];

     Scanner cin = new Scanner(System.in);
     while(cin.hasNext())
     {
    n = cin.nextInt();
    for(i=0;i< n;++i)
    {
        way[i]=cin.nextInt();
        num[i]=way[i];
    }
    Arrays.sort(num,0,n);
    mapping[0]=2;
    for(i=1;i< n;++i)
    {
        if(num[i]==num[i-1]) mapping[i]=mapping[i-1];
        else mapping[i]=mapping[i-1]+1;
    }

    for(i=0;i< n;++i)
    {
        way[i]=mapping[binary_search(0,n-1,way[i],num)];
    }
    for(i=0;i< 5;++i)
    {
        array[i]=new Binary();
        array[i].init(50010);
    }

    ans = new BigInteger("0");
    for(i=0;i< n;++i)
    {
        for(j=4;j>0;--j)
        {
           array[j].update(way[i], array[j-1].query(way[i]-1));
        }
        array[1].update(way[i], 1);

        temp = BigInteger.valueOf(array[4].query(way[i]-1));
        ans = ans.add(temp);
    }

    System.out.println(ans);

    }
 }
    public static int binary_search(int left,int right,int value,int num[])
    {
        int mid;
        while(left+1< right)
        {
            mid=(left+right)/2;
            if(num[mid]>value) right = mid;
            else left = mid;
        }
        if(num[left]==value) return left;
        return right;
    }

}

