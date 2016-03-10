//* @author: Yeming Hu"cslittleye@gmail.com"
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    Call[] calls = new Call[n];
    for(int i = 0; i < n; i++)
    {
        int q = sc.nextInt();
        int a = sc.nextInt();
        int x = sc.nextInt();

        calls[i] = new Call(q,a,x);
    }
    Arrays.sort(calls);

    int preQ = 0;
    int num = 0;
    int amount = 0;
    for(int i = 0; i < n; i++)
    {
        if(calls[i].q != preQ)
        {
            preQ = calls[i].q;
        num = 0;
        }
        if(calls[i].a == 1)
        {
        if(calls[i].x == 1)
        {
            amount += 40;
        }else
        {
            amount += 20;
        }
        amount += 10 * num;
        num++;

        }else
        {
        amount += 10;
        }
    }
    System.out.println(amount);
    }
}

class Call implements Comparable< Call>
{
    int q;
    int a;
    int x;

    Call(int q, int a, int x)
    {
        this.q = q;
    this.a = a;
    this.x = x;
    }

    public int compareTo(Call other)
    {
        if(this.q < other.q)
    {
        return -1;
    }else if(this.q == other.q)
    {
        return 0;
    }else
    {
        return 1;
    }
    }
}

