#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 20
#define HASH_TABLE_LEN 9999
#define PROJECT_NUM 100

struct Project {
  char name[LEN];
  int num;
} projects[PROJECT_NUM];
struct HashNode {
  unsigned int key_A;
  unsigned int key_B;
  int project_ID;

} HashTable[HASH_TABLE_LEN];

int project_index;

void init_hashtable() {
  int i = 0;
  for (i = 0; i < HASH_TABLE_LEN; i++) {
    HashTable[i].project_ID = -1;
  }
}

unsigned int RSHash(char *str) {
  unsigned int b = 378551;
  unsigned int a = 63689;
  unsigned int hash = 0;

  while (*str) {
    hash = hash * a + (*str++);
    a *= b;
  }

  return (hash & 0x7FFFFFFF);
}

unsigned int JSHash(char *str) {
  unsigned int hash = 1315423911;

  while (*str) {
    hash ^= ((hash << 5) + (*str++) + (hash >> 2));
  }

  return (hash & 0x7FFFFFFF);
}

unsigned int ELFHash(char *str) {
  unsigned int hash = 0;
  unsigned int x = 0;

  while (*str) {
    hash = (hash << 4) + (*str++);
    if ((x = hash & 0xF0000000L) != 0) {
      hash ^= (x >> 24);
      hash &= ~x;
    }
  }

  return (hash & 0x7FFFFFFF);
}
void count_student(char str[20], int project_ID) {
  unsigned int key = RSHash(str) % HASH_TABLE_LEN;
  unsigned int key_A = JSHash(str);
  unsigned int key_B = ELFHash(str);
  while (HashTable[key].project_ID != -1) {
    if (key_A == HashTable[key].key_A && key_B == HashTable[key].key_B) {
      if (HashTable[key].project_ID == project_ID) {
        return;
      } else if (HashTable[key].project_ID == -2) {
        return;
      } else {
        projects[HashTable[key].project_ID].num--;
        HashTable[key].project_ID = -2;
      }
      return;
    }
    key = (key + 1) % HASH_TABLE_LEN;
  }
  HashTable[key].key_A = key_A;
  HashTable[key].key_B = key_B;
  HashTable[key].project_ID = project_ID;
  projects[project_ID].num++;
}
int compare(const void *a, const void *b) {
  struct Project *p1 = (struct Project *)a;
  struct Project *p2 = (struct Project *)b;
  if (p1->num != p2->num) return p2->num - p1->num;
  return strcmp(p1->name, p2->name);
}
void output() {
  qsort(projects, project_index + 1, sizeof(struct Project), compare);
  int i;
  for (i = 0; i <= project_index; i++) {
    int str_len = strlen(projects[i].name);
    projects[i].name[str_len - 1] = '\0';
    printf("%s %d\n", projects[i].name, projects[i].num);
  }
}
int main() {
  char input[LEN];
  while (fgets(input, LEN, stdin) && input[0] != '0') {
    init_hashtable();
    strcpy(projects[0].name, input);
    projects[0].num = 0;
    project_index = 0;
    while (fgets(input, LEN, stdin) && input[0] != '1') {
      if (input[0] >= 'A' && input[0] <= 'Z')  // project name
      {
        project_index++;
        strcpy(projects[project_index].name, input);

        projects[project_index].num = 0;
      } else {
        count_student(input, project_index);
      }
    }
    output();
  }

  return 0;
}
