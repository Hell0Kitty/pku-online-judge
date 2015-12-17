
#include <iostream>
#define MAX_N 10000
using namespace std;
struct node {
  int sum;
  node *lchild;
  node *rchild;
};
node freeNode[MAX_N];
int p, target;
bool Done;

bool getNext(int &data, char &ch) {
  data = -1;
  ch = ' ';
  while (ch == ' ') cin >> ch;
  if (ch >= '0' && ch <= '9' || ch == '-') {
    cin.unget();
    cin >> data;
    return false;
  }
  return true;
}

node *build(int sum) {
  char ch;
  int data;
  bool isCh;
  isCh = getNext(data, ch);
  isCh = getNext(data, ch);
  if (isCh && ch == ')' || ch == '\n') return NULL;
  node *newNode = &freeNode[p++];
  newNode->sum = data + sum;
  newNode->lchild = build(newNode->sum);
  newNode->rchild = build(newNode->sum);
  if (newNode->lchild == NULL && newNode->rchild == NULL &&
      newNode->sum == target)
    Done = true;
  isCh = getNext(data, ch);
  return newNode;
}

int main() {
  while (scanf("%d", &target) != EOF) {
    p = 0, Done = false;
    node *root = build(0);
    if (Done)
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}