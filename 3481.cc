#include<stdio.h>
#include<string.h>
#define MAXD 1000010
int T, node, key[MAXD], client[MAXD], left[MAXD], right[MAXD], size[MAXD];
void left_rotate(int &T)
{
    int k = right[T];
    right[T] = left[k];
    left[k] = T;
    size[k] = size[T];
    size[T] = size[left[T]] + size[right[T]] + 1;
    T = k;
}
void right_rotate(int &T)
{
    int k = left[T];
    left[T] = right[k];
    right[k] = T;
    size[k] = size[T];
    size[T] = size[left[T]] + size[right[T]] + 1;
    T = k;
}
void maintain(int &T, int flag)
{
    if(flag == 0)
    {
        if(size[left[left[T]]] > size[right[T]])
            right_rotate(T);
        else if(size[right[left[T]]] > size[right[T]])
            left_rotate(left[T]), right_rotate(T);
        else
            return ;
    }
    else
    {
        if(size[right[right[T]]] > size[left[T]])
            left_rotate(T);
        else if(size[left[right[T]]] > size[left[T]])
            right_rotate(right[T]), left_rotate(T);
        else
            return ;

    }
    maintain(left[T], 0);
    maintain(right[T], 1);
    maintain(T, 0);
    maintain(T, 1);
}
void add(int &T, int c, int v)
{
    T = ++ node;
    size[T] = 1;
    client[T] = c;
    key[T] = v;
    left[T] = right[T] = 0;
}
void Insert(int &T, int c, int v)
{
    if(T == 0)
    {
        add(T, c, v);
        return ;
    }
    ++ size[T];
    if(v < key[T])
        Insert(left[T], c, v);
    else
        Insert(right[T], c, v);
    maintain(T, v >= key[T]);
}
int Delete(int &T, int v)
{
    if(v == key[T] || (v < key[T] && left[T] == 0) ||(v > key[T] && right[T] == 0))
    {
        int k = key[T];
        if(left[T] == 0 || right[T] == 0)
            T = left[T] + right[T];
        else
            key[T] = Delete(left[T], key[T] + 1);
        return k;
    }
    if(v < key[T])
        return Delete(left[T], v);
    else
        return Delete(right[T], v);
}
void select(int &T, int k, int &c, int &v)
{
    int n = size[left[T]] + 1;
    if(n == k)
    {
        c = client[T];
        v = key[T];
        Delete(T, v);
        return ;
    }
    -- size[T];
    if(k < n)
        select(left[T], k, c, v);
    else
        select(right[T], k - n, c, v);
}
int main()
{
    int k, c, v;
    node = T = left[0] = right[0] = size[0] = 0;
    for(;;)
    {
        scanf("%d", &k);
        if(!k)
            break;
        if(k == 1)
        {
            scanf("%d%d", &c, &v);
            Insert(T, c, v);
        }
        else if(k == 2)
        {
            if(size[T])
            {
                select(T, size[T], c, v);
                printf("%d\n", c);
            }
            else
                printf("0\n");
        }
        else
        {
            if(size[T])
            {
                select(T, 1, c, v);
                printf("%d\n", c);
            }
            else
                printf("0\n");
        }
    }
    return 0;
}



