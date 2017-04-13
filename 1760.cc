#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct Node;
struct Cata;
typedef vector<Cata> vc;

struct Cata {
    char name[10];
    Node *next;

    bool operator < (const Cata &x) const {
        return strcmp(name, x.name) < 0;
    }
} ;
struct Node {
    vc child;

    Node() {
        child.clear();
    }
} *Root;

void insert(char *p) {
    char tmp[10];
    char *q = tmp;
    Node *cur = Root;
    Cata buf;
    vc::iterator ii;

    while (true) {
        while (*p && *p != '\\') {
            *q = *p;
            q++, p++;
        }
        *q = 0;

        for (ii = cur->child.begin(); ii != cur->child.end(); ii++) {
            if (!strcmp((*ii).name, tmp)) {
                if (!(*ii).next) {
                    (*ii).next = new Node();
                }
                cur = (*ii).next;
                break;
            }
        }
        if (ii == cur->child.end()) {
            buf.next = new Node();
            strcpy(buf.name, tmp);
            cur->child.push_back(buf);
            cur = buf.next;

        }

        if (*p) {
            q = tmp;
            p++;
        } else {
            break;
        }
    }
}

void print(int depth, Node *rt) {
    if (!rt) return ;

    vc::iterator ii;

    sort(rt->child.begin(), rt->child.end());
    for (ii = rt->child.begin(); ii != rt->child.end(); ii++) {
        for (int i = 0; i < depth; i++) {
            putchar(' ');
        }
        puts((*ii).name);
        print(depth + 1, (*ii).next);
    }
}

int main() {
    char buf[100];
    int n;
    while (~scanf("%d", &n)) {
        Root = new Node();
        while (n--) {
            scanf("%s", buf);
            insert(buf);
        }
        print(0, Root);
    }
    return 0;
}