#include <iostream>
#include <string>
using namespace std;

struct TrieNode {
  int count;
  struct TrieNode *branch[2];
  TrieNode() {
    count = 0;
    for (int i = 0; i < 2; i++) {
      branch[i] = NULL;
    }
  }
};

//将字符串word插入根为root的字典树
void insert(TrieNode *&root, string word) {
  if (root == NULL) {
    root = new TrieNode();
  }
  TrieNode *p = root;
  for (int i = 0; i < word.size(); i++) {
    if (!p->branch[word[i] - '0']) {
      p->branch[word[i] - '0'] = new TrieNode();
    }
    p = p->branch[word[i] - '0'];
    p->count++;
  }
}

//判断字符串word是否为其他字符串的前缀
//如果是其他字符串的前缀返回false，否则返回true
bool isPrefix(TrieNode *root, string word) {
  if (root == NULL) {
    return false;
  }
  string str = "";
  TrieNode *p = root;
  for (int i = 0; i < word.size(); i++) {
    p = p->branch[word[i] - '0'];
    if (p->count == 1) return true;
  }

  return false;
}

int main() {
  int k = 0, i, num = 1;
  string str, words[8];
  TrieNode *root = NULL;
  while (cin >> str) {
    if (str == "9") {
      bool flag = true;
      for (i = 0; i < k; i++) {
        if (!isPrefix(root, words[i])) {
          flag = false;
          break;
        }
      }
      if (flag) {
        cout << "Set " << num << " is immediately decodable" << endl;
      } else {
        cout << "Set " << num << " is not immediately decodable" << endl;
      }
      num++;
      k = 0;
      root = NULL;
    } else {
      words[k] = str;
      insert(root, words[k]);
      k++;
    }
  }

  return 0;
}
