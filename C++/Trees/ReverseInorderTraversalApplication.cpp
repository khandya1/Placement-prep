///https://leetcode.com/problems/convert-bst-to-greater-tree/solution/



#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *convertBST(TreeNode *root)
    {

        inorder(root);
        return root;
    }
    int v = 0;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->right)
            inorder(root->right);
        v += root->val;
        root->val = v;
        inorder(root->left);
    }
};