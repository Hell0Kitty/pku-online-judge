#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <map>

#define MAX_INT 0x7fffffff
std::map<std::string, int> dict;
int counter = 0;
struct edge_t {
  int b, c;
  struct edge_t *next;
} *k[11000] = {NULL}, pool[184000];
int npool = 0;
int dist[11000] = {0};

int name_insert(const char *name) {
  std::map<std::string, int>::iterator iter;
  if ((iter = dict.find(name)) != dict.end()) {
    return iter->second;
  } else {
    int retval = counter;
    dict.insert(std::pair<std::string, int>(name, counter++));
    return retval;
  }
}

void add_edge(int a, int b, int c) {
  pool[npool].b = b;
  pool[npool].c = c;
  pool[npool].next = k[a];

  k[a] = &pool[npool++];
}

void spfa(int s) {
  for (int i = 0; i < sizeof(dist) / sizeof(dist[0]); ++i) {
    dist[i] = MAX_INT;
  }
  dist[s] = 0;

  std::queue<int> q;

  unsigned char visit[11000] = {0};
  visit[s] = 1;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visit[u] = 0;

    for (edge_t *p = k[u]; p != NULL; p = p->next) {
      int v = p->b;
      int c = p->c;

      if (dist[u] + c < dist[v]) {
        dist[v] = dist[u] + c;
        if (!visit[v]) {
          visit[v] = 1;
          q.push(v);
        }
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int p, n, s, e;
  int db = 0;

  while (scanf("%d%d", &p, &n), p != 0 && n != 0) {
    getchar();
    while (p--) {
      char line[251] = {0};
      gets(line);

      char *pos = strstr(line, ":");
      char *ptr = line;

      std::vector<int> idlist;
      while (ptr && ptr < pos) {
        char *next = NULL;

        char *lastname = ptr;
        next = strstr(lastname, ",");
        *next = '\0';

        char *firstname = next + 2;
        next = strstr(firstname, ",");
        if (!next) next = strstr(firstname, ":");
        *next = '\0';

        char name[251] = {0};
        strcpy(name, lastname);
        strcat(name, ", ");
        strcat(name, firstname);

        int index = name_insert(name);
        idlist.push_back(index);

        if (strcmp(name, "Erdos, P.") == 0) {
          s = index;
        }

        ptr = next + 2;
      }

      for (int i = 0; i < idlist.size(); ++i) {
        for (int j = i + 1; j < idlist.size(); ++j) {
          add_edge(idlist[i], idlist[j], 1);
          add_edge(idlist[j], idlist[i], 1);
        }
      }
    }
    spfa(s);

    printf("Database #%d\n", ++db);
    while (n--) {
      char line[251] = {0};
      gets(line);

      int slen = strlen(line);
      if (line[slen - 1] == '\n') {
        line[slen - 1] = '\0';
      }

      e = name_insert(line);
      if (dist[e] == MAX_INT) {
        printf("%s: infinity\n", line);
      } else {
        printf("%s: %d\n", line, dist[e]);
      }
    }
    printf("\n");
  }
  return 0;
}
