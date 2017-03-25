#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 105

struct Node
{
    Node *left, *right;
    char letter;
}tree[maxn];

char st[maxn];
int node_cnt;

void insert(Node * &proot, char ch)
{
    if (proot == NULL)
    {
        proot = &tree[node_cnt++];
        proot->left = NULL;
        proot->right = NULL;
        proot->letter = ch;
        return;
    }
    if (ch > proot->letter)
        insert(proot->right, ch);
    else
        insert(proot->left, ch);

}

void output(Node *proot)
{
    putchar(proot->letter);
    if (proot->left)
        output(proot->left);
    if (proot->right)
        output(proot->right);
}

void input()
{
    char *p = st;
    while (1)
    {
        scanf("%s", p);
        if (*p == '*')
            return;
        if (*p == '$')
            return;
        p = st + strlen(st);    
    }
}

int main()
{
    while (1)
    {
        input();
        Node *proot = NULL;
        node_cnt = 0;
        for (int i = strlen(st) - 2; i >= 0; i--)
            insert(proot, st[i]);
        output(proot);
        putchar('\n');
        if (st[strlen(st) - 1] == '$')
            break;
    }
    return 0;
}


