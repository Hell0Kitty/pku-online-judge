//* @author: Yeming Hu"cslittleye@gmail.com"
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
    BallSeq head, tail;
    BinaryHeap pq = new BinaryHeap();
    String s = sc.next();
    char previousChar = s.charAt(0);
        Ball ball = new Ball(0+1);
    BallSeq seq = new BallSeq(previousChar,0+1);
        head=seq;
        tail = seq;
    seq.firstBall = ball;
        seq.lastBall = ball;
    seq.number++;
    for(int i = 1; i < s.length(); i++)
    {
        char currentChar = s.charAt(i);
        if(currentChar==previousChar)
        {
        ball = new Ball(i+1);
                seq.lastBall.nextBall = ball;
                //ball.previousBall = seq.lastBall;
                seq.lastBall = ball;
                seq.number++;
        }else
        {
        previousChar = currentChar;
                pq.offer(seq);
        seq = new BallSeq(previousChar,i+1);
                tail.nextBallSeq = seq;
                seq.previousBallSeq = tail;
                tail = seq;
        ball = new Ball(i+1);
                seq.firstBall = ball;
                seq.lastBall = ball;
        seq.number++;
        }
    }
        pq.offer(seq);
    while(true)
    {
        int size = pq.size();
        if(size==0)
        {
            break;
        }
        seq = pq.poll();
        if(seq.number==1)
        {
            break;
        }
        System.out.print(seq.color);
            ball = seq.firstBall;
        for(int i = 0; i < seq.number; i++)
        {
            System.out.print(" "+ball.position);
                ball = ball.nextBall;
        }
        System.out.println();
        if(seq == head)
            {
                head = seq.nextBallSeq;
                if(head != null)
                {
                    head.previousBallSeq = null;
                }
            }else if(seq == tail)
            {
                tail = seq.previousBallSeq;
                if(tail !=null )
                {
                    tail.nextBallSeq = null;
                }
            }else
            {
                BallSeq p = seq.previousBallSeq;
                BallSeq n = seq.nextBallSeq;
                if(p.color == n.color)
                {
                    pq.remove(p);
                    pq.remove(n);
                    p.number += n.number;
                    p.lastBall.nextBall = n.firstBall;
                    //n.firstBall.previousBall = p.lastBall;
                    p.lastBall = n.lastBall;
                    p.nextBallSeq = n.nextBallSeq;
                    if(n != tail)
                    {
                        n.nextBallSeq.previousBallSeq = p;
                    }else
                    {
                        tail =p;
                    }
                    pq.offer(p);
                }else
                {
                    p.nextBallSeq = n;
                    n.previousBallSeq = p;
                }
            }
    }
    }
}

class BallSeq implements Comparable< BallSeq>
{
    public char color;
    public int number;
    public int start;
    public int position;
    Ball firstBall;
    Ball lastBall;
    BallSeq previousBallSeq;
    BallSeq nextBallSeq;
    public BallSeq(char color, int start)
    {
        this.color = color;
    this.start = start;
    this.number = 0;
        position = 0;
        firstBall = null;
        lastBall = null;
        previousBallSeq = null;
        nextBallSeq = null;
    }
    public int compareTo(BallSeq bs)
    {
        if(this.number == bs.number)
    {
        if(this.start == bs.start)
        {
            return 0;
        }else if(this.start < bs.start)
        {
            return -1;
        }else
        {
            return 1;
        }
    }else if(this.number < bs.number)
    {
        return 1;
    }else
    {
        return -1;
    }
    }
}

class Ball
{
    //Ball previousBall;
    Ball nextBall;
    int position;//position in the sequence
    public Ball(int position)
    {
        this.position = position;
        //previousBall = null;
        nextBall = null;
    }
}
class BinaryHeap
{
    public static final int max = 1000000;
    int count;
    BallSeq[] segments;
    public BinaryHeap()
    {
        count = 0;
        segments = new BallSeq[max];
    }
    public void offer(BallSeq seq)
    {
        if(count == max - 1)
        {
            throw new RuntimeException("Full Heap");
        }
        count++;
        int i = count;
        while(i > 1 && segments[i/2].compareTo(seq) == 1)
        {
            segments[i] = segments[i/2];
            segments[i].position = i;
            i = i/2;
        }
        segments[i] = seq;
        segments[i].position = i;
    }
    public void remove(BallSeq seq)
    {
        int i = seq.position;
        while(i > 1)
        {
            segments[i] = segments[i/2];
            segments[i].position = i;
            i = i/2;
        }
        segments[i] = seq;
        segments[i].position = i;
        poll();
    }
    public BallSeq poll()
    {
        if(count == 0)
        {
            throw new RuntimeException("Empty Heap");
        }
        BallSeq result = segments[1];
        BallSeq last = segments[count];
        count--;
        int i =1;
        while(2*i <= count)
        {
            int child = 2*i;
            if(child + 1 <= count && segments[child].compareTo(segments[child+1]) == 1)
            {
                child += 1;
            }
            if(last.compareTo(segments[child]) == -1)
            {
                break;
            }
            segments[i] = segments[child];
            segments[i].position = i;
            i = child;
        }
        segments[i] = last;
        segments[i].position = i;
        return result;
    }
    public int size()
    {
        return count;
    }
    public int capacity()
    {
        return max;
    }
}

