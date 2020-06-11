/* Invert a binary tree */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

struct TreeNode*
invertTree(struct TreeNode* root)
{
  if (!root->left && !root->right) {
    return root;
  } else {
    root->left&& invertTree(root->left);
    root->right&& invertTree(root->right);
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    free(tmp);
    return root;
  }
  return root;
};

int
main()
{
  return EXIT_SUCCESS;
};
