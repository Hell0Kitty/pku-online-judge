#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
  char val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  TreeNode *build(string &preorder, string &inorder, int pl, int pr, int il,
                  int ir) {
    TreeNode *root;
    if (pl > pr || il > ir) {
      root = NULL;
    } else {
      root = new TreeNode(preorder[pl]);
      int i;
      for (i = il; i <= ir && preorder[pl] != inorder[i]; i++)
        ;
      root->left = build(preorder, inorder, pl + 1, pl + i - il, il, i - 1);
      root->right = build(preorder, inorder, pl + i - il + 1, pr, i + 1, ir);
    }
    return root;
  }

 public:
  void postorder_traversal(TreeNode *root) {
    if (root == NULL) return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    putchar(root->val);
  }

  TreeNode *buildTree(string &preorder, string &inorder) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    return build(preorder, inorder, 0, preorder.size() - 1, 0,
                 inorder.size() - 1);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  char buffer1[10000];
  char buffer2[10000];
  while (scanf("%s%s", buffer1, buffer2) != EOF) {
    string a = buffer1;
    string b = buffer2;
    // cout << "[dbg] input string1: " << a << " input string2: " << b << endl;
    TreeNode *root = s.buildTree(a, b);
    s.postorder_traversal(root);
    cout << endl;
  }

  return 0;
}