//* @author: Yeming Hu"cslittleye@gmail.com"
import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        BinaryMinimumHeap minHeap = new BinaryMinimumHeap();
        BinaryMaximumHeap maxHeap = new BinaryMaximumHeap();

        while(true)
        {
            int request = sc.nextInt();
            if(request == 0)
            {
                break;
            }else if(request == 1)
            {
                int k = sc.nextInt();
                int p = sc.nextInt();
                Client client = new Client(k,p);
                minHeap.offer(client);
                maxHeap.offer(client);
            }else if(request == 2)
            {
                if(maxHeap.size() == 0)
                {
                    System.out.println(0);
                }else
                {
                    Client client = maxHeap.poll();
                    minHeap.remove(client);
                    System.out.println(client);
                }
            }else if(request == 3)
            {
                if(minHeap.size() == 0)
                {
                    System.out.println(0);
                }else
                {
                    Client client = minHeap.poll();
                    maxHeap.remove(client);
                    System.out.println(client);
                }
            }else
            {
                throw new RuntimeException("No such type of request");
            }
        }
    }

}

class Client implements Comparable< Client>
{
    int id;
    int priority;
    int posInMinimumHeap;
    int posInMaximumHeap;

    Client(int id, int priority)
    {
        this.id = id;
        this.priority = priority;
        this.posInMaximumHeap = 0;
        this.posInMinimumHeap = 0;
    }

    public int compareTo(Client client)
    {
        if(this.priority < client.priority)
        {
            return - 1;
        }else if(this.priority == client.priority)
        {
            return 0;
        }else
        {
            return 1;
        }
    }

    public String toString()
    {
        return Integer.toString(id);
    }
}

class BinaryMinimumHeap
{

    public static final int capacity = 1000001;
    int count;
    Client[] clients;
    public BinaryMinimumHeap()
    {
        clients = new Client[capacity];
        count = 0;
    }

    public void offer(Client client)
    {
        if(count == capacity - 1)
        {
            throw new RuntimeException("Full Heap");
        }
        count++;
        int i = count;
        while(i > 1 && clients[i/2].compareTo(client) == 1)
        {
            clients[i] = clients[i/2];
            clients[i].posInMinimumHeap = i;
            i /= 2;
        }
        clients[i] = client;
        clients[i].posInMinimumHeap = i;
    }

    public Client poll()
    {
        if(count == 0)
        {
            throw new RuntimeException("Empty Heap");
        }
        Client result = clients[1];
        result.posInMinimumHeap = 0;
        Client last = clients[count];
        count--;
        int i = 1;
        while(2*i <= count)
        {
            int child = 2*i;
            if(child+1 <= count && clients[child].compareTo(clients[child+1]) == 1)
            {
                child += 1;
            }
            if(last.compareTo(clients[child]) == -1)
            {
                break;
            }
            clients[i] = clients[child];
            clients[i].posInMinimumHeap = i;
            i = child;
        }
        clients[i] = last;
        clients[i].posInMinimumHeap = i;

        return result;
    }

    public void remove(Client client)
    {
        int i = client.posInMinimumHeap;
        while(i > 1)
        {
            clients[i] = clients[i/2];
            clients[i].posInMinimumHeap = i;
            i /= 2;
        }
        clients[i] = client;
        clients[i].posInMinimumHeap = i;
        poll();
    }

    public int size()
    {
        return count;
    }

    public int capacity()
    {
        return capacity - 1;
    }
}

class BinaryMaximumHeap
{

    public static final int capacity = 1000001;
    int count;
    Client[] clients;
    public BinaryMaximumHeap()
    {
        clients = new Client[capacity];
        count = 0;
    }

    public void offer(Client client)
    {
        if(count == capacity - 1)
        {
            throw new RuntimeException("Full Heap");
        }
        count++;
        int i = count;
        while(i > 1 && clients[i/2].compareTo(client) == -1)
        {
            clients[i] = clients[i/2];
            clients[i].posInMaximumHeap = i;
            i /= 2;
        }
        clients[i] = client;
        clients[i].posInMaximumHeap = i;
    }

    public Client poll()
    {
        if(count == 0)
        {
            throw new RuntimeException("Empty Heap");
        }
        Client result = clients[1];
        result.posInMaximumHeap = 0;
        Client last = clients[count];
        count--;
        int i = 1;
        while(2*i <= count)
        {
            int child = 2*i;
            if(child+1 <= count && clients[child].compareTo(clients[child+1]) == -1)
            {
                child += 1;
            }
            if(last.compareTo(clients[child]) == 1)
            {
                break;
            }
            clients[i] = clients[child];
            clients[i].posInMaximumHeap = i;
            i = child;
        }
        clients[i] = last;
        clients[i].posInMaximumHeap = i;

        return result;
    }

    public void remove(Client client)
    {
        int i = client.posInMaximumHeap;
        while(i > 1)
        {
            clients[i] = clients[i/2];
            clients[i].posInMaximumHeap = i;
            i /= 2;
        }
        clients[i] = client;
        clients[i].posInMaximumHeap = i;
        poll();
    }

    public int size()
    {
        return count;
    }

    public int capacity()
    {
        return capacity - 1;
    }
}

